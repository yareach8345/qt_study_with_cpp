//
// Created by yareach on 26. 5. 31..
//

#ifndef CPP_QT_STUDY_COLORSELECTOR_H
#define CPP_QT_STUDY_COLORSELECTOR_H

#include <QtWidgets/QVBoxLayout>
#include <vector>
#include "ColorOption.h"

class ColorSelector: public QWidget {
    Q_OBJECT
private:
    static std::vector<QColor> colorTable;

    static std::vector<ColorOption> generateColorOptions(int defaultValue = 0);
    ColorOption *selectedColorOption;

    QVBoxLayout mainLayout;

    std::vector<ColorOption> colorOptions;

    void initUi();
public:
    [[nodiscard]] QColor getSelectedColor() const;

    explicit ColorSelector(int defaultValue = 0);

signals:
    void selectedColorChanged(QColor selectedColor);
};


#endif //CPP_QT_STUDY_COLORSELECTOR_H
