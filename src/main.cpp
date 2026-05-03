#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    auto *lb1 = new QLabel("Label One", &w);
    auto *lb2 = new QLabel("Label Two", &w);
    auto *lb3 = new QLabel("Label Three", &w);
    auto *lb4 = new QLabel("Label Fore", &w);

    lb1->setGeometry(0, 0, 300, 100);
    lb1->setStyleSheet("background: red");

    lb2->setGeometry(0, 100, 300, 100);
    lb2->setStyleSheet("background: green");
    lb2->setAlignment(Qt::AlignmentFlag::AlignCenter);

    lb3->setGeometry(0, 200, 300, 100);
    lb3->setStyleSheet("background: blue");
    lb3->setFont(QFont("", 20));
    lb3->setAlignment(Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);

    QPixmap image(":images/profile");
    image = image.scaled(200, 200, Qt::AspectRatioMode::KeepAspectRatio);
    lb4->setPixmap(image);
    lb4->move(0, 300);
    lb4->setStyleSheet(
        "border-style: solid;"
        "border-width: 2;"
        "border-color: red;"
    );

    w.resize(500 , 500);
    w.show();

    return QApplication::exec();
}
