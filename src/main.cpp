#include <QtWidgets/QApplication>
#include <QDirIterator>

#include "widgets/HoverDetectableButton.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    const QIcon icon(":/images/profile.jpg");
    if (icon.isNull()) {
        throw std::runtime_error("icon is null");
    }

    QWidget w;
    w.setToolTip("This is a <h1>tool tip</h1> of widget");

    auto btn = HoverDetectableButton("Quit", &w);
    QObject::connect(&btn, &QPushButton::clicked, [] () {
        QApplication::quit();
    });

    btn.setToolTip("This is a <b>TOOL TIP!</b>");

    w.setWindowTitle("Hello, Qt6!");
    w.setGeometry(300, 300, 400, 400);
    w.setWindowIcon(icon);
    w.show();

    return QApplication::exec();
}
