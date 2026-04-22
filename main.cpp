#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    w.setWindowTitle("Hello, Qt6!");
    w.move(300, 300);
    w.resize(400, 400);
    w.show();

    return QApplication::exec();
}
