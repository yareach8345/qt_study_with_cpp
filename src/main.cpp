#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    w.setToolTip("This is a <h1>tool tip</h1> of widget");

    QLabel red("Red", &w);
    red.setStyleSheet(
        "color: red;"
        "border-style: solid;"
        "border-width: 2px;"
        "border-color: #FA8072;"
        "border-radius: 3px;"
    );
    red.setGeometry(100, 100, 100, 40);

    QLabel green("Green", &w);
    green.setStyleSheet(
        "color: green;"
        "background-color: #7FFFD4;"
    );
    green.setGeometry(100, 150, 100, 40);

    QLabel blue("Blue", &w);
    blue.setStyleSheet(
        "color: blue;"
        "background-color: #87CEFA;"
        "border-style: solid;"
        "border-width: 10px;"
        "border-color: #FA8072;"
        "border-radius: 10px;"
    );
    blue.setGeometry(100, 200, 100, 40);

    w.resize(500 , 500);
    w.show();

    return QApplication::exec();
}
