#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFontDialog>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMenuBar>
#include <QtGui/QAction>


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QMainWindow window;

    QWidget widget;
    window.setCentralWidget(&widget);

    QMenuBar *menubar = window.menuBar();
    QMenu *file_menu = menubar->addMenu("&File");

    QAction open_action("&Open");
    open_action.setShortcut(QKeySequence::Open);
    file_menu->addAction(&open_action);

    QAction save_action("&Save");
    save_action.setShortcut(QKeySequence::Save);
    file_menu->addAction(&save_action);

    QMenu *edit_menu = menubar->addMenu("&Edit");

    QAction clear_action("&Clear");
    edit_menu->addAction(&clear_action);

    QVBoxLayout layout(&widget);
    layout.setAlignment(Qt::AlignHCenter);

    QTextEdit edit;
    edit.setPlaceholderText("Input text");
    layout.addWidget(&edit, 1);

    QTextBrowser text_browser;
    text_browser.setAlignment(Qt::AlignHCenter);
    layout.addWidget(&text_browser, 1);

    QPushButton button("Select font");
    layout.addWidget(&button, 0);

    QObject::connect(&open_action, &QAction::triggered, [&] {
        const auto file_name = QFileDialog::getOpenFileName(&widget, "Open File", "./");

        // 파일 선택이 취소되면 빈 문자열이 반환됨
        if (file_name.isEmpty()) {
            qDebug() << "file not selected";
            return;
        }

        QFile file(file_name);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << file.errorString();
            throw std::runtime_error("Could not open file!");
        }

        QTextStream in(&file);
        edit.clear();
        while (!in.atEnd()) {
            QString line = in.readLine();
            edit.append(line);
        }

        file.close();
    });

    QObject::connect(&save_action, &QAction::triggered, [&] {
        const auto file_name = QFileDialog::getSaveFileName(&widget, "Save File", "./");

        // 파일 선택이 취소되면 빈 문자열이 반환됨
        if (file_name.isEmpty()) {
            qDebug() << "file not selected";
            return;
        }

        QFile file(file_name);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << file.errorString();
            throw std::runtime_error("Could not open file!");
        }
        QTextStream out(&file);
        out << edit.toPlainText();
        file.close();
    });

    QObject::connect(&clear_action, &QAction::triggered, [&] {
        edit.clear();
    });

    QObject::connect(&edit, &QTextEdit::textChanged, [&]() {
        text_browser.setMarkdown(edit.toPlainText());
    });

    QObject::connect(&button, &QPushButton::clicked, [&]() {
        bool ok_flag;
        const auto selected_font = QFontDialog::getFont(&ok_flag, &widget);

        if (ok_flag == false) { return; }

        text_browser.setFont(selected_font);
    });

    window.setWindowTitle("font");
    window.setMinimumSize(500, 500);
    window.show();

    return QApplication::exec();
}
