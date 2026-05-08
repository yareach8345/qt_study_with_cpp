#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSplitter>
#include "widgets/CustomLabel.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QVBoxLayout v_layout(&w);

    QSplitter splitter;
    splitter.setFixedWidth(255);
    v_layout.addWidget(&splitter);

    CustomLabel r_label("r");
    r_label.setStyleSheet("background-color: red;");

    CustomLabel g_label("g");
    g_label.setStyleSheet("background-color: green;");

    CustomLabel b_label("b");
    b_label.setStyleSheet("background-color: blue;");

    splitter.addWidget(&r_label);
    splitter.addWidget(&g_label);
    splitter.addWidget(&b_label);

    QLabel label("#000000");
    v_layout.addWidget(&label);

    auto update_label_color = [&]() {
        const int r = r_label.width();
        const int g = g_label.width();
        const int b = b_label.width();

        const auto rgb_string = QString("background-color: #%1%2%3;")
            .arg(r, 2, 16, QChar('0'))
            .arg(g, 2, 16, QChar('0'))
            .arg(b, 2, 16, QChar('0'));

        qDebug() << r << g << b << rgb_string;
        label.setStyleSheet(rgb_string);
        label.setText(rgb_string);
    };

    QObject::connect(&r_label, &CustomLabel::resized, [&](const int width){
        update_label_color();
    });

    QObject::connect(&g_label, &CustomLabel::resized, [&](const int width){
        update_label_color();
    });

    QObject::connect(&b_label, &CustomLabel::resized, [&](const int width){
        update_label_color();
    });

    w.setWindowTitle("Window");
    w.show();

    return QApplication::exec();
}
