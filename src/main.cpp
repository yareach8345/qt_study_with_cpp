#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

class Edit: QWidget {
private:
    QVBoxLayout layout;
    QHBoxLayout input_layout;
    QLineEdit line_edit;
    QPushButton add_button;
    QPushButton clear_button;
    QTextBrowser text_browser;

    void add_button_clicked() {
        const QString& input = line_edit.text();
        text_browser.append(input);
    }

    void clear_button_clicked() {
        text_browser.clear();
    }
public:
    explicit Edit(QWidget *parent) :
        QWidget(parent) ,
        layout(parent),
        add_button("add"),
        clear_button("clear")
    {
        input_layout.addWidget(&line_edit);
        input_layout.addWidget(&add_button);
        layout.addLayout(&input_layout);
        layout.addWidget(&text_browser);
        text_browser.setAcceptRichText(true);
        text_browser.setOpenExternalLinks(true);
        layout.addWidget(&clear_button);

        QObject::connect(&add_button, &QPushButton::clicked, [this] { this->add_button_clicked(); });
        QObject::connect(&clear_button , &QPushButton::clicked, [this]{ this->clear_button_clicked(); });
    }
};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    Edit edit(&w);

    w.setWindowTitle("edit?");
    w.setFixedSize(500, 500);
    w.show();

    return QApplication::exec();
}
