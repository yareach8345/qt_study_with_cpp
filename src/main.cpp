#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout v_layout(&w);

    QString rgb_string("#000000");
    bool is_r_on = false;
    bool is_g_on = false;
    bool is_b_on = false;

    QHBoxLayout h_layout;
    v_layout.addLayout(&h_layout);

    QButtonGroup rgb_group;
    rgb_group.setExclusive(false);
    // r
    QCheckBox r_check_box("r");
    h_layout.addWidget(&r_check_box);
    rgb_group.addButton(&r_check_box);
    // g
    QCheckBox g_check_box("g");
    h_layout.addWidget(&g_check_box);
    rgb_group.addButton(&g_check_box);
    // b
    QCheckBox b_check_box("b");
    h_layout.addWidget(&b_check_box);
    rgb_group.addButton(&b_check_box);

    QLabel label(QString("rgb %1").arg(rgb_string));
    auto update_label_style = [&] {
        const QString new_style(
            "background-color: %1;"
            "color: %2;"
        );
        label.setStyleSheet(
            new_style
                .arg(rgb_string)
                .arg("#777777")
        );
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
    update_label_style();

    label.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label.setAlignment(Qt::AlignCenter);
    v_layout.addWidget(&label);

    w.resize(500 , 500);
    w.show();

    return QApplication::exec();
}
