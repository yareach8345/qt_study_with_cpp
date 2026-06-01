//
// Created by yareach on 26. 5. 31..
//

#include "ColorOption.h"
#include <QPainter>
#include <QMouseEvent>

QString ColorOption::toolTipTemplate("%1 눌러서 변경하기");

void ColorOption::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (isSelected) {
        painter.setBrush(Qt::darkGray);
        painter.drawRect(0, 0, 3, 50);
    }
    painter.setBrush(color);
    painter.drawRect(5, 5, 40, 40);
    painter.end();
}

void ColorOption::mousePressEvent(QMouseEvent *event) {
    if (event->button() != Qt::LeftButton) {
        return;
    }

    emit selected();
}

ColorOption::ColorOption(const ColorOption &other): isSelected(other.isSelected), color(other.color) {}

ColorOption::ColorOption(const QColor color, const bool isSelected): isSelected(isSelected), color(color) {
    resize(50, 50);

    setToolTip(toolTipTemplate.arg(color.name()));
}

void ColorOption::setIsSelected(const bool newIsSelected) {
    this->isSelected = newIsSelected;
}

void ColorOption::setColor(const int newColor) {
    this->color = newColor;
}

QColor ColorOption::getColor() const {
    return this->color;
}
