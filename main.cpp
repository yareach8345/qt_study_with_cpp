#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtGui/QIcon>
#include <QtWidgets/QPushButton>
#include <QDirIterator>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QIcon icon(":/images/profile.jpg");
    if (icon.isNull()) {
        throw std::runtime_error("icon is null");
    }

    QWidget w;

    auto btn = QPushButton("Quit", &w);
    btn.move(100, 200);
    QObject::connect(&btn, &QPushButton::clicked, [] () {
        QApplication::quit();
    });

    w.setWindowTitle("Hello, Qt6!");
    w.setGeometry(300, 300, 400, 400);
    w.setWindowIcon(icon);
    w.show();

    return QApplication::exec();
}
