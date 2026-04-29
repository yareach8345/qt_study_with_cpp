#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    w.setToolTip("This is a <h1>tool tip</h1> of widget");
    // style
    QVBoxLayout layout;
    w.setLayout(&layout);

    QLabel red("Red");
    red.setStyleSheet(
        "color: red;"
        "border-style: solid;"
        "border-width: 2px;"
        "border-color: #FA8072;"
        "border-radius: 3px;"
    );
    layout.addWidget(&red);

    QLabel green("Green");
    green.setStyleSheet(
        "color: green;"
        "background-color: #7FFFD4;"
    );
    layout.addWidget(&green);

    QLabel blue("Blue");
    blue.setStyleSheet(
        "color: blue;"
        "background-color: #87CEFA;"
        "border-style: solid;"
        "border-width: 10px;"
        "border-color: #FA8072;"
        "border-radius: 10px;"
    );
    layout.addWidget(&blue);

    w.resize(500 , 500);
    w.show();

    return QApplication::exec();
}
