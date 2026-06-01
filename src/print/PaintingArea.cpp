//
// Created by yareach on 26. 5. 31..
//

#include "PaintingArea.h"
#include <QMouseEvent>
#include <QPainter>

PaintingArea::PaintingArea(): brushSize(1), release(false) {
    setMouseTracking(true);
}

void PaintingArea::drawPoint(const QPoint pos) {
    const PointInfo pointInfo = { .size = brushSize, .point = pos, .color = color };
    qDebug() << "(" << pos.x() << ", " << pos.y() << ")";
    points.push_back(pointInfo);
    update();
    emit drawn(pointInfo);
}

void PaintingArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(QColor(0, 0, 0));
    for (PointInfo pos: points) {
        QPen pen;
        pen.setColor(pos.color);
        pen.setWidth(pos.size);
        painter.setPen(pen);
        painter.drawPoint(pos.point);
    }
    painter.end();
}

void PaintingArea::mousePressEvent(QMouseEvent *event) {
    if (event->button() != Qt::MouseButton::LeftButton) { return; }

    this->release = true;
    drawPoint(event->pos());
}

void PaintingArea::mouseMoveEvent(QMouseEvent *event) {
    if (release == false) { return; }
    drawPoint(event->pos());
}

void PaintingArea::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() != Qt::MouseButton::LeftButton) { return; }

    this->release = false;
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

std::vector<PointInfo> PaintingArea::getPoints() {
    return points;
}

QColor PaintingArea::getColor() const {
    return color;
}

void PaintingArea::setColor(const QColor newColor) {
    color = newColor;
}

unsigned long PaintingArea::getNumberOfPoints() const {
    return points.size();
}

void PaintingArea::setBrushSize(const int newBrushSize) {
    brushSize = newBrushSize;
}

int PaintingArea::getBrushSize() const {
    return brushSize;
}
