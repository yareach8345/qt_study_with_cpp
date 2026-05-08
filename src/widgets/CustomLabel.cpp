//
// Created by yareach on 26. 5. 8..
//

#include "CustomLabel.h"
#include <QResizeEvent>

void CustomLabel::resizeEvent(QResizeEvent *event) {
    const auto new_size = event->size();

    resized(new_size.width());
}

CustomLabel::CustomLabel(const QString &text): QLabel(text) {}
