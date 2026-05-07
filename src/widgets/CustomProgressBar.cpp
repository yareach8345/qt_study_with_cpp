//
// Created by yareach on 26. 5. 6..
//

#include "CustomProgressBar.h"

CustomProgressBar::CustomProgressBar(const Range normal_range, const int max, const int min): normal_range(normal_range) {
    setMaximum(max);
    setMinimum(min);
}

void CustomProgressBar::setValue(const int value) {
    QProgressBar::setValue(value);

    update_color();
}

void CustomProgressBar::update_color() {
    const int current_value = value();

    if (current_value < normal_range.start) {
        setStyleSheet("selection-background-color: red;");
    } else if (current_value < normal_range.end) {
        setStyleSheet("selection-background-color: green;");
    } else {
        setStyleSheet("selection-background-color: blue;");
    }
}