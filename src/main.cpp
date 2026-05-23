#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFontDialog>


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout layout(&w);
    layout.setAlignment(Qt::AlignHCenter);

    QTextEdit edit;
    edit.setPlaceholderText("Input text");
    layout.addWidget(&edit, 1);

    QLabel label;
    label.setAlignment(Qt::AlignHCenter);
    layout.addWidget(&label, 1);

    QPushButton button("Select font");
    layout.addWidget(&button, 0);

    QObject::connect(&edit, &QTextEdit::textChanged, [&]() {
        label.setText(edit.toPlainText());
    });

    QObject::connect(&button, &QPushButton::clicked, [&]() {
        bool ok_flag;
        const auto selected_font = QFontDialog::getFont(&ok_flag, &w);

        if (ok_flag == false) { return; }

        label.setFont(selected_font);
    });

    w.setWindowTitle("font");
    w.setMinimumSize(500, 500);
    w.show();

    return QApplication::exec();
}
