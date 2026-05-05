#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout v_layout(&w);

    QString rgb_string("#000000");

    QComboBox rgb_combo_box;
    v_layout.addWidget(&rgb_combo_box);

    rgb_combo_box.addItem("Black(#000000)");
    rgb_combo_box.addItem("Red(#ff0000)");
    rgb_combo_box.addItem("Green(#00ff00)");
    rgb_combo_box.addItem("Blue(#0000ff)");
    rgb_combo_box.addItem("Yellow(#ffff00)");
    rgb_combo_box.addItem("Magenta(#ff00ff)");
    rgb_combo_box.addItem("Cyan(#00ffff)");
    rgb_combo_box.addItem("White(#ffffff)");

    QHBoxLayout text_h_align_layout;
    v_layout.addLayout(&text_h_align_layout);
    Qt::AlignmentFlag h_align_flag = Qt::AlignmentFlag::AlignHCenter;

    QButtonGroup text_h_align_group;
    QRadioButton h_left("left");
    text_h_align_group.addButton(&h_left);
    text_h_align_layout.addWidget(&h_left);
    QRadioButton h_center("center");
    text_h_align_group.addButton(&h_center);
    text_h_align_layout.addWidget(&h_center);
    QRadioButton h_right("right");
    text_h_align_group.addButton(&h_right);
    text_h_align_layout.addWidget(&h_right);
    h_center.setChecked(true);

    QHBoxLayout text_v_align_layout;
    v_layout.addLayout(&text_v_align_layout);
    Qt::AlignmentFlag v_align_flag = Qt::AlignmentFlag::AlignVCenter;

    QButtonGroup text_v_align_group;
    QRadioButton v_top("top");
    text_v_align_group.addButton(&v_top);
    text_v_align_layout.addWidget(&v_top);
    QRadioButton v_center("center");
    text_v_align_group.addButton(&v_center);
    text_v_align_layout.addWidget(&v_center);
    QRadioButton v_bottom("bottom");
    text_v_align_group.addButton(&v_bottom);
    text_v_align_layout.addWidget(&v_bottom);
    v_center.setChecked(true);

    int font_size = 20;
    QSlider slider(Qt::Horizontal);
    slider.setRange(1, 100);
    slider.setValue(font_size);
    v_layout.addWidget(&slider);

    QLabel label(QString("rgb %1").arg(rgb_string));
    auto update_label_style = [&] {
        const QString new_style(
            "background-color: %1;"
            "color: %2;"
            "font-size: %3px;"
        );
        label.setStyleSheet(
            new_style
                .arg(rgb_string)
                .arg("#777777")
                .arg(font_size)
        );
        label.setAlignment(v_align_flag | h_align_flag);
    };

    QObject::connect(&rgb_combo_box, &QComboBox::currentTextChanged, [&](const QString& text) {
        const qsizetype start_index = text.indexOf('(') + 1;
        const qsizetype end_index = text.indexOf(')') - 1;
        const QString new_value = text.sliced(start_index, end_index - start_index + 1);

        rgb_string = new_value;

        update_label_style();
        label.setText(QString("rgb %1").arg(rgb_string));
    });

    QObject::connect(&text_h_align_group, &QButtonGroup::buttonToggled, [&](const QAbstractButton* btn, auto checked) {
        if (&h_left == btn) {
            h_align_flag = Qt::AlignLeft;
        } else if (&h_center == btn) {
            h_align_flag = Qt::AlignHCenter;
        } else if (&h_right == btn) {
            h_align_flag = Qt::AlignRight;
        } else {
            throw std::runtime_error("Unknown CheckBox is changed");
        }
        update_label_style();
    });

    QObject::connect(&text_v_align_group, &QButtonGroup::buttonToggled, [&](const QAbstractButton* btn, auto checked) {
        if (&v_top == btn) {
            v_align_flag = Qt::AlignTop;
        } else if (&v_center == btn) {
            v_align_flag = Qt::AlignVCenter;
        } else if (&v_bottom == btn) {
            v_align_flag = Qt::AlignBottom;
        } else {
            throw std::runtime_error("Unknown CheckBox is changed");
        }
        update_label_style();
    });

    QObject::connect(&slider, &QSlider::valueChanged, [&](int value) {
        font_size = value;
        update_label_style();
    });

    update_label_style();

    label.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label.setAlignment(Qt::AlignCenter);
    v_layout.addWidget(&label);

    w.resize(500 , 500);
    w.show();

    return QApplication::exec();
}
