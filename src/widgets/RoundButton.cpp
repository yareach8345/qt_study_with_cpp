//
// Created by yareach on 26. 4. 23..
//

#include "RoundButton.h"
#include <cmath>

RoundButton::RoundButton(const QString &text, QWidget *parent = nullptr): QPushButton(text, parent), rotationSteps(0), movable(true) {
    resize(60, 30);
    move(200 - 30, 200 - 15 - 150);
}

void RoundButton::enterEvent(QEnterEvent *event) {
    if (movable == false) { return; }
    rotationSteps = ++rotationSteps % 12;
    const double radian = (rotationSteps * 30) * (M_PI / 180.0);
    const int dx = sin(radian) * 150;
    const int dy = cos(radian) * 150;
    move(200 - dx, 200 - dy);

    emit moved(rotationSteps);
}

bool RoundButton::get_movable() const {
    return movable;
}

bool RoundButton::set_movable(const bool movable) {
    this->movable = movable;
    return true;
}

bool RoundButton::toggle_movable() {
    const bool new_value = !this->movable;
    this->movable = new_value;
    return new_value;
}
