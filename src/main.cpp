#include <QtWidgets/QApplication>
#include <QDirIterator>
#include <QPainter>

#include "widgets/HoverDetectableButton.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    const QIcon icon(":/images/profile.jpg");
    if (icon.isNull()) {
        throw std::runtime_error("icon is null");
    }

    QWidget w;

    auto btn = HoverDetectableButton("Quit", &w);
    QObject::connect(&btn, &QPushButton::clicked, [] () {
        QApplication::quit();
    });

    w.setWindowTitle("Hello, Qt6!");
    w.setGeometry(300, 300, 400, 400);
    w.setWindowIcon(icon);
    w.show();

    return QApplication::exec();
}
