#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QPushButton>

class Edit: QWidget {
private:
    QVBoxLayout layout;
    QHBoxLayout input_layout;
    QTextEdit text_edit;
    QPushButton clear_button;
    QTextBrowser text_browser;

    void text_edit_updated() {
        text_browser.setMarkdown(text_edit.toPlainText());
    }

    void clear_button_clicked() {
        text_browser.clear();
    }
public:
    explicit Edit(QWidget *parent) :
        QWidget(parent) ,
        layout(parent),
        clear_button("clear")
    {
        input_layout.addWidget(&text_edit);
        input_layout.addWidget(&text_browser);
        layout.addLayout(&input_layout);
        text_browser.setAcceptRichText(true);
        text_browser.setOpenExternalLinks(true);
        layout.addWidget(&clear_button);

        QObject::connect(&clear_button , &QPushButton::clicked, [this]{ this->clear_button_clicked(); });
        QObject::connect(&text_edit, &QTextEdit::textChanged, [this]{ text_edit_updated(); });
    }
};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    Edit edit(&w);

    w.setWindowTitle("markdown edit?");
    w.setFixedSize(500, 500);
    w.show();

    return QApplication::exec();
}
