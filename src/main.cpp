#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QDateTime>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QVBoxLayout layout(&w);

    layout.addWidget(new QLabel("QTimeEdit"));

    QDateTimeEdit datetimeEdit;
    layout.addWidget(&datetimeEdit);
    datetimeEdit.setDateTime(QDateTime::currentDateTime());
    datetimeEdit.setMinimumDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
    datetimeEdit.setMaximumDateTime(QDateTime(QDate(2099, 12, 31), QTime(23, 59, 59)));

    QLabel label;
    layout.addWidget(&label);
    auto update_label = [&label](const QDateTime& date_time) {
        label.setText(date_time.toString("yyyy년 MM월 dd일 hh시 mm분 ss초"));
    };
    update_label(datetimeEdit.dateTime());

    QObject::connect(&datetimeEdit, &QDateTimeEdit::dateTimeChanged, [&update_label](const QDateTime &date_time) {
        qDebug() << "qDateTime updated to " << date_time.toString();
        update_label(date_time);
    });

    w.setWindowTitle("QTime?");
    w.setFixedSize(500, 500);
    w.show();

    return QApplication::exec();
}
