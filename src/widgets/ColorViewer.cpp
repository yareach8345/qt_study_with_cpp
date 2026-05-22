//
// Created by yareach on 26. 5. 22..
//

#include "ColorViewer.h"

ColorViewer::ColorViewer(const QColor &defaultColor): color(defaultColor), layout(this) {
    this->color_viewer.setFixedSize(QSize(100, 100));
    this->color_name.setFixedWidth(100);

    initLayout();
    updateColor(&defaultColor);
}

void ColorViewer::initLayout() {
    layout.addWidget(&this->color_viewer);
    layout.addWidget(&this->color_name);
    layout.setAlignment(Qt::AlignHCenter);
    color_name.setAlignment(Qt::AlignHCenter);
}

QColor ColorViewer::getColor() const {
    return color;
}

void ColorViewer::updateColor(const QColor *newColor) {
    this->color = *newColor;
    this->color_viewer.setStyleSheet(style_template.arg(newColor->name()));
    this->color_name.setText(newColor->name());
}

bool ColorViewer::setColor(const QColor *newColor) {
    if (!newColor->isValid()) {
        return false;
    }

    if (*newColor == color) {
        return false;
    }

    updateColor(newColor);

    return true;
}

QString ColorViewer::style_template = QString(
    "border-radius: 15px;"
    "border-style: solid;"
    "border-width: 1px;"
    "border-color: black;"
    "background-color: %1;"
);
