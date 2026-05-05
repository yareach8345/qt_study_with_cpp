#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QGridLayout>
#include <functional>

int main(int argc, char* argv[]) {
    std::hash<QString> hash;

    QApplication a(argc, argv);

    QWidget w;

    QGridLayout layout(&w);

    QLineEdit input;
    QLabel hashed_value_label;

    layout.addWidget(new QLabel("input"), 0, 0);
    layout.addWidget(&input, 0, 1);
    layout.addWidget(new QLabel("hashed"), 1, 0);
    layout.addWidget(&hashed_value_label, 1, 1);

    QObject::connect(&input, &QLineEdit::textChanged, [&](const QString &new_text) {
        const std::size_t hashed = hash(new_text);
        hashed_value_label.setText(QString::number(hashed));
    });

    w.resize(500, 40);
    w.show();

    return QApplication::exec();
}
