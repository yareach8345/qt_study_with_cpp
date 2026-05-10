#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QtCore>

class TabWidget : public QWidget {
private:
    QPushButton btn;
public:
    explicit TabWidget(QString name): btn(this) {
        btn.setText(name);

        const auto r = QRandomGenerator::global();
        const int x = r->bounded(0, 200);
        const int y = r->bounded(0, 200);
        btn.setGeometry(x, y, 100, 100);
    }

};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    auto tabs = QTabWidget();
    tabs.addTab(new TabWidget("Tab1"), "Tab1");
    tabs.addTab(new TabWidget("Tab2"), "Tab2");
    tabs.addTab(new TabWidget("Tab3"), "Tab3");
    tabs.setTabsClosable(true);

    QObject::connect(&tabs, &QTabWidget::tabCloseRequested, [&](auto index) {
        tabs.removeTab(index);
    });

    QObject::connect(&tabs, &QTabWidget::currentChanged, [&](auto index) {
        qDebug() << index;
    });


    QVBoxLayout vbox(&w);
    vbox.addWidget(&tabs);

    w.setWindowTitle("Window");
    w.show();

    return QApplication::exec();
}
