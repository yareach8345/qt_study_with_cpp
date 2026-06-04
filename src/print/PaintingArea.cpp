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
    const QRect rect(this->releaseStartPoint, this->releaseEndPoint);
    const RectInfo lineInfo = {
        .size = brushSize,
        .rect = rect,
        .color = color,
        .fill = this->fill,
    };
    qDebug() << "[" << this->releaseStartPoint << ", " << this->releaseEndPoint << "]";
    rects.push_back(lineInfo);
    update();
    emit drawn(lineInfo);
}

void PaintingArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(QColor(0, 0, 0));
    for (const RectInfo rect: rects) {
        QPen pen;
        pen.setColor(rect.color);
        pen.setWidth(rect.size);
        painter.setPen(pen);
        painter.setBrush(rect.fill ? QBrush(rect.color) : Qt::NoBrush);
        painter.drawArc(rect.rect, 0, 360 * 16);
    }
    if (release == true) {
        QPen pen;
        painter.setBrush(this->fill ? QBrush(this->color) : Qt::NoBrush);
        pen.setStyle(Qt::PenStyle::DashLine);
        pen.setColor(Qt::GlobalColor::gray);
        painter.setPen(pen);
        painter.drawRect(QRect(this->releaseStartPoint, this->releaseEndPoint));
        pen.setStyle(Qt::PenStyle::SolidLine);
        pen.setColor(color);
        pen.setWidth(brushSize);
        painter.setPen(pen);
        painter.drawArc(QRect(this->releaseStartPoint, this->releaseEndPoint), 0, 360 * 16);
    }
    painter.end();
}

void PaintingArea::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        this->release = true;

        this->releaseStartPoint = event->pos();
        this->releaseEndPoint = event->pos();
        this->update();
        return;
    } else if (event->button() == Qt::MouseButton::RightButton) {
        this->fill = !this->fill;
        emit fillChanged(this->fill);
    }
}

void PaintingArea::mouseMoveEvent(QMouseEvent *event) {
    if (release == false) { return; }

    this->releaseEndPoint = event->pos();
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

std::vector<RectInfo> PaintingArea::getRects() {
    return rects;
}

QColor PaintingArea::getColor() const {
    return color;
}

void PaintingArea::setColor(const QColor newColor) {
    color = newColor;
}

unsigned long PaintingArea::getNumberOfPoints() const {
    return rects.size();
}

void PaintingArea::setBrushSize(const int newBrushSize) {
    brushSize = newBrushSize;
}

int PaintingArea::getBrushSize() const {
    return brushSize;
}
