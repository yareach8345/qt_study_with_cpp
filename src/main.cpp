#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QVBoxLayout vbox;
    QHBoxLayout hbox;

    QPushButton ok_btn("ok");
    ok_btn.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QPushButton cancel_btn("cancel");
    cancel_btn.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    w.setLayout(&vbox);
    vbox.addStretch(2);
    vbox.addLayout(&hbox, 1);
    vbox.addStretch(1);

    hbox.addStretch(1);
    hbox.addWidget(&ok_btn, 1);
    hbox.addWidget(&cancel_btn, 2);
    hbox.addStretch(1);

    w.resize(500 , 500);
    w.show();

    return QApplication::exec();
}
