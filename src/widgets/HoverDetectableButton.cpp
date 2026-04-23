//
// Created by yareach on 26. 4. 23..
//

#include "HoverDetectableButton.h"
#include <cmath>

HoverDetectableButton::HoverDetectableButton(const QString &text, QWidget *parent = nullptr): QPushButton(text, parent), rotationSteps(0) {
    resize(60, 30);
    move(200 - 30, 200 - 15 - 150);
}

void HoverDetectableButton::enterEvent(QEnterEvent *event) {
    const double radian = (++rotationSteps * 30) * (M_PI / 180.0);
    const int dx = sin(radian) * 150;
    const int dy = cos(radian) * 150;
    move(200 - dx, 200 - dy);
}

void HoverDetectableButton::leaveEvent(QEvent *event) {
}
