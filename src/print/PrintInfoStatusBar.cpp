//
// Created by yareach on 26. 5. 31..
//

#include "PrintInfoStatusBar.h"

QString PrintInfoStatusBar::numberOfPointsInfoTemplate("Number of Points: %1");

QString PrintInfoStatusBar::fillInfoTemplate("fill : %1");

void PrintInfoStatusBar::updateNumberOfPointsLabel() {
    this->numberOfPointsLabel.setText(numberOfPointsInfoTemplate.arg(this->numberOfPoints));
}

PrintInfoStatusBar::PrintInfoStatusBar(const int numberOfPoints, const int brushSize, const bool fill): numberOfPoints(numberOfPoints), brushSizeLabel(brushSize), fill(fill) {
    addWidget(&numberOfPointsLabel);
    updateNumberOfPointsLabel();

    addWidget(&brushSizeLabel);
    connect(&brushSizeLabel, &BrushSizeLabel::sizeChanged, [this](const int newSize) {
        emit brushSizeChanged(newSize);
    });

    addWidget(&fillLabel);
    updateFillLabel();
}

int PrintInfoStatusBar::getNumberOfPoints() const {
    return this->numberOfPoints;
}

void PrintInfoStatusBar::setNumberOfPoints(const int numberOfPoints) {
    this->numberOfPoints = numberOfPoints;
    updateNumberOfPointsLabel();
}

int PrintInfoStatusBar::getBrushSize() const {
    return this->brushSizeLabel.getSize();
}

void PrintInfoStatusBar::setBrushSize(const int brushSize) {
    this->brushSizeLabel.setSize(brushSize);
}

bool PrintInfoStatusBar::getFill() const {
    return this->fill;
}

void PrintInfoStatusBar::setFill(const bool fill) {
    this->fill = fill;
    updateFillLabel();
}

void PrintInfoStatusBar::updateFillLabel() {
    fillLabel.setText(fillInfoTemplate.arg(this->getFill() ? "true" : "false"));
}

void PrintInfoStatusBar::reset() {
    setNumberOfPoints(0);
    setBrushSize(0);
}
