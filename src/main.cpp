#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout vbox;
    w.setLayout(&vbox);

    QGridLayout grid;
    vbox.addLayout(&grid);

    QLabel title_label("Title: ");
    grid.addWidget(&title_label, 0, 0);
    QLabel author_label("Author: ");
    grid.addWidget(&author_label, 1, 0);
    QLabel review_label("Review: ");
    grid.addWidget(&review_label, 2, 0);

    QLineEdit title_input;
    grid.addWidget(&title_input, 0, 1);
    QLineEdit author_input;
    grid.addWidget(&author_input, 1, 1);
    QTextEdit review_input;
    grid.addWidget(&review_input, 2, 1);

    QHBoxLayout hbox;
    vbox.addLayout(&hbox);

    auto clear_inputs = [&] {
        title_input.clear();
        author_input.clear();
        review_input.clear();
    };

    const QString log_form("submit - title : %0, author: %1, review: %2");

    QPushButton submit_button("Submit");
    hbox.addWidget(&submit_button, 1);
    QObject::connect(&submit_button, &QAbstractButton::clicked, [&] {
        const auto title = title_input.text();
        const auto author = author_input.text();
        const auto review = review_input.toPlainText();

        QMessageBox msgBox;

        if (title.isEmpty() || author.isEmpty() || review.isEmpty()) {
            msgBox.setText("failed submit");
            msgBox.exec();
            return;
        }

        qDebug() << log_form.arg(title).arg(author).arg(review);

        msgBox.setText("success submit");
        msgBox.exec();
        clear_inputs();
    });

    QPushButton reset_button("Reset");
    hbox.addWidget(&reset_button, 1);
    QObject::connect(&reset_button, &QPushButton::clicked, [&] {
        clear_inputs();
    });

    QPushButton quit_button("Quit");
    hbox.addWidget(&quit_button, 1);
    QObject::connect(&quit_button, &QPushButton::clicked, [&] {
        QApplication::quit();
    });

    w.resize(500 , 500);
    w.show();

    return QApplication::exec();
}
