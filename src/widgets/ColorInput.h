//
// Created by yareach on 26. 5. 22..
//

#ifndef CPP_QT_STUDY_COLORINPUT_H
#define CPP_QT_STUDY_COLORINPUT_H

#include <QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtGui/QColor>

#include "ColorViewer.h"

class ColorInput: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout layout;
    ColorViewer color_viewer;
    QPushButton button;

    QColor selected_color;

    void init_layout();

    void on_color_viewer_clicked();

    void update_color(const QColor *new_color);
public:
    explicit ColorInput(const QColor &defaultColor = Qt::white);

public:
    QColor color() const;

    bool setColor(const QColor *new_color);
signals:
    void colorChanged(QColor* color);
};


#endif //CPP_QT_STUDY_COLORINPUT_H
