#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout v_layout(&w);

    QString rgb_string("#000000");

    QHBoxLayout rgb_layout;
    v_layout.addLayout(&rgb_layout);

    QButtonGroup rgb_group;
    rgb_group.setExclusive(false);
    // r
    QCheckBox r_check_box("r");
    rgb_layout.addWidget(&r_check_box);
    rgb_group.addButton(&r_check_box);
    // g
    QCheckBox g_check_box("g");
    rgb_layout.addWidget(&g_check_box);
    rgb_group.addButton(&g_check_box);
    // b
    QCheckBox b_check_box("b");
    rgb_layout.addWidget(&b_check_box);
    rgb_group.addButton(&b_check_box);

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

    QObject::connect(&rgb_group, &QButtonGroup::buttonToggled, [&](const QAbstractButton* btn, auto checked) {
        std::size_t start_index;
        if (&r_check_box == btn) {
            start_index = 1;
        } else if (&g_check_box == btn) {
            start_index = 3;
        } else if (&b_check_box == btn) {
            start_index = 5;
        } else {
            throw std::runtime_error("Unknown CheckBox is changed");
        }
        const char new_value = checked ? 'f' : '0';
        rgb_string[start_index] = new_value;
        rgb_string[start_index + 1] = new_value;

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
