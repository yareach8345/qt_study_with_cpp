#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QLabel>
#include <QtCore/QTimer>
#include <QtWidgets/QGridLayout>

#include "widgets/CustomProgressBar.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout layout(&w);

    QProgressBar pb1;
    QProgressBar pb2;
    QProgressBar pb3;
    QLabel lb("...");

    layout.addWidget(&pb1);
    layout.addWidget(&pb2);
    layout.addWidget(&pb3);
    layout.addWidget(&lb);
    layout.addStretch(1);

    pb1.setMinimum(0);
    pb1.setMaximum(0);

    pb2.setValue(50);

    pb3.setOrientation(Qt::Orientation::Vertical);

    QTimer timer;
    timer.start(100);

    CustomProgressBar cp({ 40, 60 });
    layout.addWidget(&cp);

    w.resize(400, 500);
    w.show();

    QObject::connect(&timer, &QTimer::timeout, [&]() {
        const int current_pb3_value = pb3.value();
        pb3.setValue(current_pb3_value + 1);
        cp.setValue(current_pb3_value);
        if (current_pb3_value == 100) {
            timer.stop();
            lb.setText("Finished...");
        }
    });

    return QApplication::exec();
}
