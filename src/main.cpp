#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QVBoxLayout layout(&w);

    QSpinBox first_number_spinbox;
    layout.addWidget(&first_number_spinbox);
    first_number_spinbox.setMinimum(1);
    first_number_spinbox.setMaximum(9);
    first_number_spinbox.setValue(5);

    QSpinBox second_number_spinbox;
    layout.addWidget(&second_number_spinbox);
    second_number_spinbox.setMinimum(1);
    second_number_spinbox.setMaximum(9);
    second_number_spinbox.setValue(5);

    QLabel result_label;
    layout.addWidget(&result_label);
    const QString result_template = "%1 * %2 = %3";
    auto result_label_update = [&] {
        const int first_number = first_number_spinbox.value();
        const int second_number = second_number_spinbox.value();
        const int result = first_number * second_number;
        result_label.setText(result_template.arg(first_number).arg(second_number).arg(result));
    };
    result_label_update();

    QObject::connect(&first_number_spinbox, &QSpinBox::valueChanged, result_label_update);

    QObject::connect(&second_number_spinbox, &QSpinBox::valueChanged, result_label_update);

    w.setWindowTitle("QGugu?");
    w.setFixedSize(500, 500);
    w.show();

    return QApplication::exec();
}
