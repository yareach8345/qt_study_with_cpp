//
// Created by yareach on 26. 5. 22..
//

#include "ColorInput.h"
#include <QtWidgets/QColorDialog>

ColorInput::ColorInput(const QColor &defaultColor): layout(this), button("Change color"), selected_color(defaultColor) {
    this->button.setFixedWidth(100);
    this->init_layout();
    this->update_color(&defaultColor);

    QObject::connect(&this->button, &QPushButton::clicked, [this]{ this->on_color_viewer_clicked(); });
}

void ColorInput::init_layout() {
    layout.addWidget(&this->color_viewer);
    layout.addWidget(&this->button);
}

void ColorInput::update_color(const QColor *new_color) {
    this->selected_color = *new_color;
    color_viewer.setColor(new_color);
    emit colorChanged(&this->selected_color);
}

void ColorInput::on_color_viewer_clicked() {
    const QColor new_color = QColorDialog::getColor();
    update_color(&new_color);
}

QColor ColorInput::color() const {
    return this->selected_color;
}

bool ColorInput::setColor(const QColor *new_color) {
    if (!new_color->isValid()) {
        return false;
    }

    if (*new_color == selected_color) {
        return false;
    }

    update_color(new_color);

    return true;
}