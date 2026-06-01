//
// Created by yareach on 26. 5. 31..
//

#include "ColorSelector.h"

std::vector<QColor> ColorSelector::colorTable = {
    Qt::white, Qt::red, Qt::green, Qt::blue, Qt::magenta, Qt::cyan, Qt::black
};

std::vector<ColorOption> ColorSelector::generateColorOptions(const int defaultValue) {
    std::vector<ColorOption> result;

    for (int i = 0; i < colorTable.size(); i++) {
        result.emplace_back(colorTable[i], i == defaultValue);
    }

    return result;
}

void ColorSelector::initUi() {
    for (ColorOption& colorOption : colorOptions) {
        mainLayout.addWidget(&colorOption);
    }
}

QColor ColorSelector::getSelectedColor() const {
    return selectedColorOption->getColor();
}

ColorSelector::ColorSelector(const int defaultValue): colorOptions(generateColorOptions(defaultValue)), mainLayout(this) {
    selectedColorOption = &colorOptions[0];
    setMinimumWidth(70);
    initUi();
    for (int i = 0; i < colorOptions.size(); i++) {
        QObject::connect(&colorOptions[i], &ColorOption::selected, [&, i]() {
            if (&colorOptions[i] == selectedColorOption) { return; }
            colorOptions[i].setIsSelected(true);
            selectedColorOption->setIsSelected(false);
            selectedColorOption = &colorOptions[i];

            emit selectedColorChanged(selectedColorOption->getColor());
        });
    }
}
