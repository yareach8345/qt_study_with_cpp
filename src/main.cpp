#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

#define NUMBER_OF_INPUT 2
#define MAX_DIAL_INPUT 100

struct DialStruct {
    QVBoxLayout layout;
    QDial dial;
    QLCDNumber lcd_number;
};

void init_dial_input(DialStruct *dial_input) {
    dial_input->layout.addWidget(&dial_input->lcd_number);
    dial_input->layout.addWidget(&dial_input->dial);
    dial_input->dial.setMinimum(0);
    dial_input->dial.setMaximum(MAX_DIAL_INPUT);
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget widget;

    DialStruct output_dial;
    init_dial_input(&output_dial);
    output_dial.dial.setDisabled(true);
    output_dial.dial.setMaximum(MAX_DIAL_INPUT * NUMBER_OF_INPUT);

    int inputs[NUMBER_OF_INPUT] = {};

    auto update_output_dial = [&] {
        int sum = 0;
        for (int i = 0; i < NUMBER_OF_INPUT; i++) { sum += inputs[i]; }
        output_dial.dial.setValue(sum);
        output_dial.lcd_number.display(sum);
    };

    DialStruct input_dials[NUMBER_OF_INPUT];

    QHBoxLayout input_layout;

    for (int i = 0; i < NUMBER_OF_INPUT; i++) {
        DialStruct *input_dial = &input_dials[i];
        init_dial_input(input_dial);

        input_layout.addLayout(&input_dial->layout);
        QObject::connect(&input_dial->dial, &QDial::valueChanged, [&inputs, &update_output_dial, input_dial, i](const auto new_value) {
            input_dial->lcd_number.display(new_value);
            inputs[i] = new_value;
            update_output_dial();
        });
    }

    QVBoxLayout layout(&widget);
    layout.addWidget(new QLabel("Inputs"));
    layout.addLayout(&input_layout);
    layout.addWidget(new QLabel("Output"));
    layout.addLayout(&output_dial.layout);

    widget.setWindowTitle("font");
    widget.show();

    return QApplication::exec();
}