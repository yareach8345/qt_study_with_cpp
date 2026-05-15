#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QDate>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QVBoxLayout layout(&w);

    layout.addWidget(new QLabel("QDateEdit"));

    QDateEdit dateEdit;
    layout.addWidget(&dateEdit);
    dateEdit.setDate(QDate::currentDate());
    dateEdit.setMinimumDate(QDate(2001, 01, 01));
    dateEdit.setMaximumDate(QDate(2099, 12, 31));

    QObject::connect(&dateEdit, &QDateEdit::dateChanged, [](const QDate new_date) {
        qDebug() << new_date.toString();
    });

    w.setWindowTitle("QGugu?");
    w.setFixedSize(500, 500);
    w.show();

    return QApplication::exec();
}
