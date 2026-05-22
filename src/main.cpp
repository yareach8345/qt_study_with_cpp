#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include "widgets/ColorInput.h"


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QVBoxLayout layout(&w);
    layout.setAlignment(Qt::AlignHCenter);

    QHBoxLayout color_inputs;
    layout.addLayout(&color_inputs);

    ColorInput color_input1(QColor(255, 0, 0));
    ColorInput color_input2(QColor(0, 0, 255));
    color_inputs.addWidget(&color_input1);
    color_inputs.addWidget(&color_input2);

    QLabel l1("混ぜたら 混ぜたら 何色 なるかな");
    l1.setAlignment(Qt::AlignHCenter);
    layout.addWidget(&l1);

    ColorViewer result_color;
    auto update_result = [&]() {
        const QColor color1 = color_input1.color();
        const QColor color2 = color_input2.color();
        const auto result = QColor(
            (color1.red() + color2.red()) / 2,
            (color1.green() + color2.green()) / 2,
            (color1.blue() + color2.blue()) / 2
        );
        qDebug() << color1.name();
        qDebug() << color2.name();
        qDebug() << result.name();

        result_color.setColor(&result);
    };
    update_result();
    layout.addWidget(&result_color);

    QLabel l2("STAMP!");
    l2.setAlignment(Qt::AlignHCenter);
    layout.addWidget(&l2);

    QObject::connect(&color_input1, &ColorInput::colorChanged, [&] { update_result(); });
    QObject::connect(&color_input2, &ColorInput::colorChanged, [&] { update_result(); });

    w.setWindowTitle("Mazetara");
    w.setMinimumSize(500, 500);
    w.show();

    return QApplication::exec();
}
