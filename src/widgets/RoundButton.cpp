//
// Created by yareach on 26. 4. 23..
//

#include "RoundButton.h"
#include <cmath>

RoundButton::RoundButton(const QString &text, QWidget *parent = nullptr): QPushButton(text, parent), rotationSteps(0) {
    resize(60, 30);
    move(200 - 30, 200 - 15 - 150);
}

void RoundButton::enterEvent(QEnterEvent *event) {
    rotationSteps = ++rotationSteps % 12;
    const double radian = (rotationSteps * 30) * (M_PI / 180.0);
    const int dx = sin(radian) * 150;
    const int dy = cos(radian) * 150;
    move(200 - dx, 200 - dy);

    emit moved(rotationSteps);
}
