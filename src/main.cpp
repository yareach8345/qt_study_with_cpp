#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QCalendarWidget calendar;
    QLabel label;

    calendar.setGridVisible(true);

    auto update_label = [&label, &calendar] {
        label.setText(calendar.selectedDate().toString());
    };
    update_label();

    QObject::connect(&calendar, &QCalendarWidget::clicked, update_label);

    QVBoxLayout layout;
    layout.addWidget(&calendar);
    layout.addWidget(&label);

    w.setLayout(&layout);
    w.setWindowTitle("QCalendarWidget");
    w.show();

    return QApplication::exec();
}
