//
// Created by yareach on 26. 5. 30..
//

#include "MyApp.h"

QString MyApp::mouse_info_template("x: %1, y: %2");

QString MyApp::label_style_template("background-color: %1;");

QString MyApp::color_table[] = {
    "#ffffff",
    "#ff0000",
    "#00ff00",
    "#0000ff",
};

void MyApp::initUi() {
    mouse_point_label.setFixedWidth(100);
    mouse_point_label.setWordWrap(true);
    setWindowTitle("Reimplementing event handler");
    setGeometry(300, 300, 500, 500);
    show();
}

void MyApp::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Escape:
            QApplication::quit();
            break;
        case Qt::Key_F:
            showFullScreen();
            break;
        case Qt::Key_N:
            showNormal();
            break;
        default:
            break;
    }
}

void MyApp::mouseMoveEvent(QMouseEvent* event) {
    const auto pos = event->pos();
    mouse_point_label.setText(mouse_info_template.arg(pos.x()).arg(pos.y()));
    mouse_point_label.move(pos);
}

void MyApp::mouseDoubleClickEvent(QMouseEvent* event) {
    double_click_count = ++double_click_count & 0b011;
    mouse_point_label.setStyleSheet(label_style_template.arg(color_table[double_click_count]));
}

void MyApp::mousePressEvent(QMouseEvent* event) {
    qDebug() << "pressed";
    emit custom_event();
}

MyApp::MyApp() : QWidget(), mouse_point_label(this) {
    setMouseTracking(true);
    initUi();
}
