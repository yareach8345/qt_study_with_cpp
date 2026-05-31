//
// Created by yareach on 26. 5. 30..
//

#ifndef CPP_QT_STUDY_MYAPP_H
#define CPP_QT_STUDY_MYAPP_H

#include <QWidget>
#include <QKeyEvent>
#include <QApplication>
#include <QString>
#include <QLabel>

class MyApp : public QWidget {
    Q_OBJECT
private:
    static QString label_style_template;
    static QString color_table[];

    static QString mouse_info_template;

    int double_click_count = 0;

    QLabel mouse_point_label;

    void initUi();

protected:
    void keyPressEvent(QKeyEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mouseDoubleClickEvent(QMouseEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;

public:
    MyApp();

signals:
    void custom_event();
};

#endif //CPP_QT_STUDY_MYAPP_H
