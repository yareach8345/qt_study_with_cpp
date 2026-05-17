#include <QtWidgets/QApplication>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QTime>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QVBoxLayout layout(&w);

    layout.addWidget(new QLabel("QTimeEdit"));

    QTimeEdit timeEdit;
    layout.addWidget(&timeEdit);
    timeEdit.setTime(QTime::currentTime());
    timeEdit.setMinimumTime(QTime(00, 00, 00));
    timeEdit.setMaximumTime(QTime(24, 00, 00));

    QObject::connect(&timeEdit, &QTimeEdit::dateChanged, [](const QDate new_date) {
        qDebug() << new_date.toString();
    });

    w.setWindowTitle("QTime?");
    w.setFixedSize(500, 500);
    w.show();

    return QApplication::exec();
}
