#include <QtWidgets/QApplication>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMenu>

QGroupBox *gen_radio_buttons_group() {
    auto *group = new QGroupBox("Exclusive Radio Buttons");

    auto *layout = new QVBoxLayout;

    for (int i = 0; i < 3; i++) {
        const auto new_radio = new QRadioButton(QString("Radio%1").arg(i + 1));
        layout->addWidget(new_radio);
        if (i == 0) {
            new_radio->setChecked(true);
        }
    }

    group->setLayout(layout);

    return std::move(group);
}

QGroupBox *gen_check_boxes_group() {
    auto *group = new QGroupBox("Non-Exclusive Checkboxes");

    auto *layout = new QVBoxLayout;

    for (int i = 0; i < 3; i++) {
        const auto new_radio = new QCheckBox(QString("Checkbox%1").arg(i + 1));
        layout->addWidget(new_radio);
    }
    layout->addStretch(1);

    group->setLayout(layout);

    return std::move(group);
}

QGroupBox *gen_radio_buttons_group2() {
    auto group = gen_radio_buttons_group();
    group->setCheckable(true);
    group->setChecked(true);

    const auto checkbox = new QCheckBox("Independent Checkbox");
    checkbox->setChecked(true);
    group->layout()->addWidget(checkbox);

    return std::move(group);
}

QGroupBox *gen_push_buttons_groups(QWidget* widget) {
    auto *group = new QGroupBox("Push Buttons");
    group->setCheckable(true);
    group->setChecked(true);

    const auto pushbutton = new QPushButton("Normal Button");

    const auto toggleButton = new QPushButton("Toggle Button");
    toggleButton->setCheckable(true);
    toggleButton->setChecked(true);

    const auto flatButton = new QPushButton("Flat Button");
    flatButton->setFlat(true);

    const auto popupButton = new QPushButton("Flat Button");
    const auto menu = new QMenu(widget);
    menu->addAction("First Item");
    menu->addAction("Second Item");
    menu->addAction("Third Item");
    menu->addAction("Fourth Item");
    popupButton->setMenu(menu);

    const auto vBox = new QVBoxLayout;
    vBox->addWidget(pushbutton);
    vBox->addWidget(toggleButton);
    vBox->addWidget(flatButton);
    vBox->addWidget(popupButton);
    vBox->addStretch(1);

    group->setLayout(vBox);
    return std::move(group);
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QGridLayout layout(&w);

    layout.addWidget(gen_radio_buttons_group(), 0, 0);
    layout.addWidget(gen_check_boxes_group(), 0, 1);
    layout.addWidget(gen_radio_buttons_group2(), 1, 0);
    layout.addWidget(gen_push_buttons_groups(&w), 1, 1);

    w.setWindowTitle("Window");
    w.show();

    return QApplication::exec();
}
