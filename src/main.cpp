#include <QtWidgets/QApplication>
#include <QKeyEvent>
#include <QPoint>
#include <QtWidgets/QLabel>

class MyApp : public QWidget {
private:
    static QString label_style_template;
    static QString color_table[];

    static QString mouse_info_template;

    int double_click_count = 0;

    QLabel mouse_point_label;

    void initUi() {
        mouse_point_label.setFixedWidth(100);
        mouse_point_label.setWordWrap(true);
        setWindowTitle("Reimplementing event handler");
        setGeometry(300, 300, 500, 500);
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

    void mouseMoveEvent(QMouseEvent* event) override {
        const auto pos = event->pos();
        mouse_point_label.setText(mouse_info_template.arg(pos.x()).arg(pos.y()));
        mouse_point_label.move(pos);
    }

    void mouseDoubleClickEvent(QMouseEvent* event) override {
        double_click_count = ++double_click_count & 0b011;
        mouse_point_label.setStyleSheet(label_style_template.arg(color_table[double_click_count]));
    }

public:
    MyApp() : QWidget(), mouse_point_label(this) {
        setMouseTracking(true);
        initUi();
    }
};

QString MyApp::mouse_info_template("x: %1, y: %2");

QString MyApp::label_style_template("background-color: %1;");

QString MyApp::color_table[] = {
    "#ffffff",
    "#ff0000",
    "#00ff00",
    "#0000ff",
};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    MyApp app;

    return QApplication::exec();
}