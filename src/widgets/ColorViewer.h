//
// Created by yareach on 26. 5. 22..
//

#ifndef CPP_QT_STUDY_COLORVIEWER_H
#define CPP_QT_STUDY_COLORVIEWER_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtGui/QColor>

class ColorViewer: public QWidget {
    Q_OBJECT
private:
    static QString style_template;

    QColor color;
    QVBoxLayout layout;
    QLabel color_viewer;
    QLabel color_name;

    void initLayout();

    void updateColor(const QColor* newColor);

public:
    explicit ColorViewer(const QColor& defaultColor = Qt::white);

    bool setColor(const QColor* newColor);
    QColor getColor() const;
};


#endif //CPP_QT_STUDY_COLORVIEWER_H
