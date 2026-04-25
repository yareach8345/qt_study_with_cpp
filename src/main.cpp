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

    // exit action
    const auto exit_action = std::make_unique<QAction>("Exit");
    exit_action->setShortcut(QKeySequence("Ctrl+Q"));
    exit_action->setStatusTip("Exit Application");
    QObject::connect(exit_action.get(), &QAction::triggered, QApplication::quit);

    // toggle movable action
    const auto toggle_movable = std::make_unique<QAction>("Toggle movable");
    toggle_movable->setShortcut(QKeySequence("Ctrl+M"));
    toggle_movable->setStatusTip("Toggle movable");
    QObject::connect(toggle_movable.get(), &QAction::triggered, [&btn, &statusBar] {
        const bool new_value = btn.toggle_movable();
        const auto event_message = QString("movable is changed to %1").arg(new_value ? "true" : "false");
        qDebug() << event_message;
        statusBar->showMessage(event_message, 5000);
    });

    // menu bar
    const auto menu_bar = w.menuBar();
    QMenu *menu = menu_bar->addMenu("menu");
    menu->addAction(exit_action.get());
    menu->addSeparator();
    menu->addAction(toggle_movable.get());

    w.setWindowTitle("Hello, Qt6!");
    w.setGeometry(300, 300, 400, 400);
    w.setWindowIcon(icon);
    w.show();

    return QApplication::exec();
}
