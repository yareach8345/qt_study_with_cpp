#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QDial>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>

#include "widgets/CustomProgressBar.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout vbox(&w);

    std::vector<QSlider*> sbs;

    QSlider sb1(Qt::Orientation::Horizontal);
    QSlider sb2(Qt::Orientation::Horizontal);
    QSlider sb3(Qt::Orientation::Horizontal);
    QSlider sb4;

    QDial dial;

    sbs.push_back(&sb1);
    sbs.push_back(&sb2);
    sbs.push_back(&sb3);
    sbs.push_back(&sb4);

    vbox.addWidget(&sb1);
    sb1.setRange(0, 100);

    vbox.addWidget(&sb2);
    sb2.setTickPosition(QSlider::TickPosition::TicksAbove);

    vbox.addWidget(&sb3);
    sb3.setTickPosition(QSlider::TickPosition::TicksBelow);
    sb3.setTickInterval(10);

    vbox.addWidget(&sb4);
    sb4.setTickPosition(QSlider::TickPosition::TicksRight);
    sb4.setTickInterval(20);

    vbox.addWidget(&dial);
    dial.setRange(0, 100);

    QHBoxLayout hbox;
    vbox.addLayout(&hbox);

    hbox.addWidget(new QLabel("0"), 1);
    CustomProgressBar cp({ 40, 60 });
    hbox.addWidget(&cp, 20);
    hbox.addWidget(new QLabel("100"), 1);

    for (QSlider* slider: sbs) { slider->setValue(50); }

    auto slider_update = [&sbs, &dial, &cp](const int value) {
        for (QSlider* slider : sbs) {
            slider->setValue(value);
        }
        dial.setValue(value);
        cp.setValue(value);
    };

    for (const QSlider* slider: sbs) {
        QObject::connect(slider, &QSlider::valueChanged, slider_update);
    }
    QObject::connect(&dial, &QSlider::valueChanged, slider_update);

    w.resize(400, 500);
    w.show();

    // QObject::connect(&timer, &QTimer::timeout, [&]() {
    //     const int current_pb3_value = pb3.value();
    //     pb3.setValue(current_pb3_value + 1);
    //     cp.setValue(current_pb3_value);
    //     if (current_pb3_value == 100) {
    //         timer.stop();
    //         lb.setText("Finished...");
    //     }
    // });

    return QApplication::exec();
}
