//
// Created by yareach on 26. 5. 31..
//

#ifndef CPP_QT_STUDY_PAINTINGAREA_H
#define CPP_QT_STUDY_PAINTINGAREA_H

#include <QtWidgets/QWidget>
#include <vector>
#include "RectInfo.h"

class PaintingArea: public QWidget {
    Q_OBJECT
private:
    std::vector<RectInfo> rects;

    int brushSize;

    bool fill;

    QColor color;

    bool release;
    QPoint releaseStartPoint;
    QPoint releaseEndPoint;

    void drawLine();
protected:
    void mousePressEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void paintEvent(QPaintEvent* event) override;

    void wheelEvent(QWheelEvent* event) override;
public:
    explicit PaintingArea();

    std::vector<RectInfo> getRects();

    [[nodiscard]] QColor getColor() const;

    void setColor(QColor newColor);

    [[nodiscard]] unsigned long getNumberOfPoints() const;

    void setBrushSize(int newBrushSize);

    [[nodiscard]] int getBrushSize() const;
signals:
    void drawn(RectInfo rect);

    void brushSizeChanged(int brushSize);

    void fillChanged(bool fill);
};


#endif //CPP_QT_STUDY_PAINTINGAREA_H
