#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDockWidget>

#include "print/ColorSelector.h"
#include "print/PrintInfoStatusBar.h"
#include "print/PaintingArea.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QMainWindow mainWindow;

    PrintInfoStatusBar printInfoStatusBar;

    PaintingArea paintingArea;
    paintingArea.setMinimumSize(500, 500);

    mainWindow.setCentralWidget(&paintingArea);
    mainWindow.setStatusBar(&printInfoStatusBar);

    QDockWidget sidebar("sidebar", &mainWindow);
    ColorSelector colorSelector;
    sidebar.setWidget(&colorSelector);
    mainWindow.addDockWidget(Qt::RightDockWidgetArea, &sidebar);

    paintingArea.setColor(colorSelector.getSelectedColor());

    QObject::connect(&paintingArea, &PaintingArea::drawn, [&] {
        printInfoStatusBar.setNumberOfPoints(static_cast<int>(paintingArea.getNumberOfPoints()));
    });

    QObject::connect(&paintingArea, &PaintingArea::brushSizeChanged, [&](const int newBrushSize){
        printInfoStatusBar.setBrushSize(newBrushSize);
    });

    QObject::connect(&printInfoStatusBar, &PrintInfoStatusBar::brushSizeChanged, [&](const int newBrushSize) {
        paintingArea.setBrushSize(newBrushSize);
    });

    QObject::connect(&colorSelector, &ColorSelector::selectedColorChanged, [&] (const QColor selectedColor) {
        paintingArea.setColor(selectedColor);
    });

    mainWindow.show();

    return QApplication::exec();
}