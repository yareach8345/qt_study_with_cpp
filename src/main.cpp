#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QDirIterator>
#include <QMenuBar>

#include "widgets/RoundButton.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    const QIcon icon(":/images/profile.jpg");
    if (icon.isNull()) {
        throw std::runtime_error("icon is null");
    }

    QMainWindow w;
    w.setToolTip("This is a <h1>tool tip</h1> of widget");

    auto btn = RoundButton("Quit", &w);
    QObject::connect(&btn, &QPushButton::clicked, [] () {
        QApplication::quit();
    });

    QStatusBar *statusBar = w.statusBar();

    QObject::connect(&btn, &RoundButton::moved, [&statusBar](const unsigned int step) {
        qDebug() << step;
        statusBar->showMessage(QString("step %1").arg(step));
    });

    btn.setToolTip("This is a <b>TOOL TIP!</b>");

    auto exit_action = std::make_unique<QAction>("Exit");
    exit_action->setShortcut(QKeySequence("Ctrl+Q"));
    exit_action->setStatusTip("Exit Application");
    QObject::connect(exit_action.get(), &QAction::triggered, QApplication::quit);

    auto menu_bar = w.menuBar();
    QMenu *menu = menu_bar->addMenu("menu");
    menu->addAction(exit_action.get());

    w.setWindowTitle("Hello, Qt6!");
    w.setGeometry(300, 300, 400, 400);
    w.setWindowIcon(icon);
    w.show();

    return QApplication::exec();
}
