//
// Created by yareach on 26. 5. 31..
//

#include "PaintingArea.h"
#include <QMouseEvent>
#include <QPainter>

PaintingArea::PaintingArea(): brushSize(1), release(false) {
    setMouseTracking(true);
}

void PaintingArea::drawLine() {

    const CircleInfo circle_info {
        .size = brushSize,
        .center = this->center,
        .r = this->r,
        .color = this->color,
        .fill = this->fill
    };

    qDebug() << "[" << circle_info.center << ", " << circle_info.r << "]";
    circles.push_back(circle_info);
    update();
    emit drawn(circle_info);
}

void PaintingArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(QColor(0, 0, 0));
    for (const CircleInfo circle: circles) {
        QPen pen;
        pen.setColor(circle.color);
        pen.setWidth(circle.size);
        painter.setPen(pen);
        painter.setBrush(circle.fill ? QBrush(circle.color) : Qt::NoBrush);
        painter.drawArc(circle.center.x() - circle.r, circle.center.y() - circle.r, circle.r * 2, circle.r * 2, 0, 360 * 16);
    }
    if (release == true) {
        QPen pen;
        painter.setBrush(this->fill ? QBrush(this->color) : Qt::NoBrush);
        pen.setStyle(Qt::PenStyle::DashLine);
        pen.setColor(Qt::GlobalColor::gray);
        painter.setPen(pen);
        painter.drawLine(center, mouse_pos);
        pen.setStyle(Qt::PenStyle::SolidLine);
        pen.setColor(color);
        pen.setWidth(brushSize);
        painter.setPen(pen);
        painter.drawArc(center.x() - r, center.y() - r, r * 2, r * 2, 0, 360 * 16);
    }
    painter.end();
}

void PaintingArea::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        this->release = true;

        this->r = 0;
        this->center = event->pos();
        this->update();
        return;
    } else if (event->button() == Qt::MouseButton::RightButton) {
        this->fill = !this->fill;
        emit fillChanged(this->fill);
    }
}

void PaintingArea::mouseMoveEvent(QMouseEvent *event) {
    if (release == false) { return; }

    mouse_pos = event->pos();
    const auto dx = mouse_pos.x() - this->center.x();
    const auto dy = mouse_pos.y() - this->center.y();
    this->r = sqrt(dx * dx + dy * dy);
    this->update();
}

void PaintingArea::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        this->release = false;

        drawLine();
    }
}

void PaintingArea::wheelEvent(QWheelEvent *event) {
    // true == up, false == down
    const bool direction = event->angleDelta().y() > 0;

    if (direction) {
        if (brushSize >= 255) {
            return;
        }
        brushSize++;
    } else {
        if (brushSize <= 1) {
            return;
        }
        brushSize--;
    }

    brushSizeChanged(brushSize);

    qDebug() << "wheet event : " << (direction ? "up" : "down") << "(" << brushSize << ")";
}

std::vector<CircleInfo> PaintingArea::getRects() {
    return circles;
}

QColor PaintingArea::getColor() const {
    return color;
}

void PaintingArea::setColor(const QColor newColor) {
    color = newColor;
}

unsigned long PaintingArea::getNumberOfPoints() const {
    return circles.size();
}

void PaintingArea::setBrushSize(const int newBrushSize) {
    brushSize = newBrushSize;
}

int PaintingArea::getBrushSize() const {
    return brushSize;
}
