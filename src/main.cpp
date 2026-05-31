#include <QtWidgets/QApplication>
#include "MyApp.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    MyApp app;

    QObject::connect(&app, &MyApp::custom_event, []() {
        qDebug() << "custom event";
    });

    return QApplication::exec();
}