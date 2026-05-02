#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout layout;
    w.setLayout(&layout);

    QVBoxLayout toggle_buttons_layout;
    layout.addLayout(&toggle_buttons_layout);
    for (int i = 0; i < 2; i++) {
        auto button = new QPushButton();
        button->setText("OFF");
        button->setCheckable(true);
        button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

        QObject::connect(button, &QPushButton::clicked, [button] { button->setText(button->isChecked() ? "ON" : "OFF"); });
        toggle_buttons_layout.addWidget(button);
    }

    QVBoxLayout buttons_layout;
    layout.addLayout(&buttons_layout);
    for (int i = 0; i < 2; i++) {
        auto button = new QPushButton();
        button->setText(QString("Send %1").arg(i));
        button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

        QObject::connect(button, &QPushButton::clicked, [button] { qDebug() << button->text() << " click"; });
        buttons_layout.addWidget(button);
    }

    w.resize(500 , 500);
    w.show();

    return QApplication::exec();
}
