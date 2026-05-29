#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QKeyEvent>

class MyApp : public QWidget {
private:
    void initUi() {
        setWindowTitle("Reimplementing event handler");
        setGeometry(300, 300, 300, 200);
        show();
    }

protected:
    void keyPressEvent(QKeyEvent* event) override {
        switch (event->key()) {
            case Qt::Key_Escape:
                QApplication::quit();
                break;
            case Qt::Key_F:
                showFullScreen();
                break;
            case Qt::Key_N:
                showNormal();
                break;
            default:
                break;
        }
    }

public:
    MyApp() : QWidget() {
        initUi();
    }
};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    MyApp app;

    return QApplication::exec();
}