//
// Created by yareach on 26. 5. 31..
//

#ifndef CPP_QT_STUDY_COLOROPTION_H
#define CPP_QT_STUDY_COLOROPTION_H

#include <QLabel>

class ColorOption: public QWidget {
    Q_OBJECT
private:
    static QString toolTipTemplate;

    bool isSelected{};

    QColor color;
protected:
    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;
public:
    explicit ColorOption(QColor color, bool isSelected = false);

    explicit ColorOption(const ColorOption& other);

    void setIsSelected(bool newIsSelected);

    void setColor(int newColor);

    [[nodiscard]] QColor getColor() const;

signals:
    void selected();
};


#endif //CPP_QT_STUDY_COLOROPTION_H
