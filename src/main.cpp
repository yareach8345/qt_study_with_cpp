#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtCore/QtCore>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QSlider>
#include <QColor>

QImage blur(const QImage &original, const int d) {
    QImage blurred(original.width(), original.height(), QImage::Format_RGB32);

    const int div = (d * 2 + 1) * (d * 2 + 1);

    for (int x = d; x < original.width() - d; x++) {
        for (int y = d; y < original.height() - d; y++) {
            int r = 0;
            int g = 0;
            int b = 0;
            for (int dx = -d; dx <= d; dx++) {
                for (int dy = -d; dy <= d; dy++) {
                    auto color = original.pixelColor(x + dx, y + dy);
                    r += color.red();
                    g += color.green();
                    b += color.blue();
                }
            }
            r /= div;
            g /= div;
            b /= div;

            blurred.setPixelColor(x, y, QColor(r, g, b));
        }
    }

    return std::move(blurred);
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QVBoxLayout layout(&w);

    QImage original_img(":images/profile.jpg");

    QLabel label;
    layout.addWidget(&label);

    auto set_label_pixel_img = [&](const int new_value) {
        const QImage image = blur(original_img, new_value);
        const QPixmap pixmap = QPixmap::fromImage(image);
        label.setPixmap(pixmap);
    };

    QSlider slider;
    slider.setMinimum(0);
    slider.setMaximum(20);
    slider.setTickInterval(1);
    slider.setValue(5);
    slider.setOrientation(Qt::Horizontal);
    layout.addWidget(&slider);

    const auto img_info = QString("original image size - w: %1, h: %2").arg(original_img.width()).arg(original_img.height());
    QLabel label2(img_info);
    layout.addWidget(&label2);

    QObject::connect(&slider, &QSlider::valueChanged, &w, set_label_pixel_img);
    set_label_pixel_img(slider.value());

    w.setWindowTitle("Blur. 느림주의.");
    w.show();

    return QApplication::exec();
}
