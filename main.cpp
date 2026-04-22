#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtGui/QIcon>
#include <QDirIterator>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QIcon icon(":/images/profile.jpg");
    if (icon.isNull()) {
        throw std::runtime_error("icon is null");
    }

    QWidget w;
    w.setWindowTitle("Hello, Qt6!");
    w.setGeometry(300, 300, 400, 400);
    w.setWindowIcon(icon);
    w.show();

    return QApplication::exec();
}
