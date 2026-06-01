//
// Created by yareach on 26. 5. 31..
//

#include "BrushSizeLabel.h"
#include <QMouseEvent>

QString BrushSizeLabel::brushSizeInfoTemplate("Brush Size: %1");

BrushSizeLabel::BrushSizeLabel(const int initValue): brushSize {initValue} {
    updateBrushSizeLabel();
}

void BrushSizeLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() != Qt::LeftButton) { return; }

    bool isOk;
    const int result = QInputDialog::getInt(
        this,
        "브러쉬 크기 설정",
        "브러쉬 크기 입력",
        brushSize,
        1, 255, 1,
        &isOk
    );
    qDebug() << (isOk ? "true" : "false") << result;
    if (!isOk) { return; }
    setSize(result);
}

void BrushSizeLabel::updateBrushSizeLabel() {
    this->setText(brushSizeInfoTemplate.arg(this->brushSize));
}

int BrushSizeLabel::getSize() const {
    return this->brushSize;
}

void BrushSizeLabel::setSize(const int newSize) {
    this->brushSize = newSize;
    emit sizeChanged(newSize);
    updateBrushSizeLabel();
}
