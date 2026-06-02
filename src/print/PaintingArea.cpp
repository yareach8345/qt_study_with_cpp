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
    const LineInfo lineInfo = {
        .size = brushSize,
        .start = this->releaseStartPoint,
        .end = this->releaseEndPoint,
        .color = color
    };
    qDebug() << "[" << this->releaseStartPoint << ", " << this->releaseEndPoint << "]";
    lines.push_back(lineInfo);
    update();
    emit drawn(lineInfo);
}

void PaintingArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(QColor(0, 0, 0));
    for (const LineInfo line: lines) {
        QPen pen;
        pen.setColor(line.color);
        pen.setWidth(line.size);
        painter.setPen(pen);
        painter.drawLine(line.start, line.end);
    }
    if (release == true) {
        QPen pen;
        pen.setColor(color);
        pen.setWidth(brushSize);
        painter.setPen(pen);
        painter.drawLine(this->releaseStartPoint, this->releaseEndPoint);
    }
    painter.end();
}

void PaintingArea::mousePressEvent(QMouseEvent *event) {
    if (event->button() != Qt::MouseButton::LeftButton) { return; }

    this->release = true;

    this->releaseStartPoint = event->pos();
    this->releaseEndPoint = event->pos();
    this->update();
}

void PaintingArea::mouseMoveEvent(QMouseEvent *event) {
    if (release == false) { return; }

    this->releaseEndPoint = event->pos();
    this->update();
}

void PaintingArea::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() != Qt::MouseButton::LeftButton) { return; }

    this->release = false;

    drawLine();
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

std::vector<LineInfo> PaintingArea::getLines() {
    return lines;
}

QColor PaintingArea::getColor() const {
    return color;
}

void PaintingArea::setColor(const QColor newColor) {
    color = newColor;
}

unsigned long PaintingArea::getNumberOfPoints() const {
    return lines.size();
}

void PaintingArea::setBrushSize(const int newBrushSize) {
    brushSize = newBrushSize;
}

int PaintingArea::getBrushSize() const {
    return brushSize;
}
