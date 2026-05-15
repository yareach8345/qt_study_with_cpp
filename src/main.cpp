#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QDoubleSpinBox* gen_spin_box() {
    const auto spin_box = new QDoubleSpinBox();
    spin_box->setRange(0, 10);
    spin_box->setSingleStep(0.1);
    spin_box->setValue(5);
    return spin_box;
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QVBoxLayout layout(&w);

    const auto first_spinbox = gen_spin_box();
    layout.addWidget(first_spinbox);
    const auto second_spinbox = gen_spin_box();
    layout.addWidget(second_spinbox);

    QLabel result_label;
    layout.addWidget(&result_label);
    const QString result_template = "%1 * %2 = %3";
    auto result_label_update = [&] {
        const double first_number = first_spinbox->value();
        const double second_number = second_spinbox->value();
        const double result = first_number * second_number;
        result_label.setText(result_template.arg(first_number).arg(second_number).arg(result));
    };
    result_label_update();

    QObject::connect(first_spinbox, &QDoubleSpinBox::valueChanged, result_label_update);

    QObject::connect(second_spinbox, &QDoubleSpinBox::valueChanged, result_label_update);

    w.setWindowTitle("QGugu?");
    w.setFixedSize(500, 500);
    w.show();

    return QApplication::exec();
}
