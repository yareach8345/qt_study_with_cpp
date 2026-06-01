//
// Created by yareach on 26. 5. 31..
//

#ifndef CPP_QT_STUDY_PRINTINFOSTATUSBAR_H
#define CPP_QT_STUDY_PRINTINFOSTATUSBAR_H

#include <QtWidgets/QStatusBar>
#include <QtWidgets/QLabel>

#include "BrushSizeLabel.h"

class PrintInfoStatusBar: public QStatusBar {
    Q_OBJECT
private:
    static QString numberOfPointsInfoTemplate;

    int numberOfPoints;

    QLabel numberOfPointsLabel;

    BrushSizeLabel brushSizeLabel;

    void updateNumberOfPointsLabel();
public:
    explicit PrintInfoStatusBar(int numberOfPoints = 0, int brushSize = 1);

    [[nodiscard]] int getNumberOfPoints() const;

    void setNumberOfPoints(int numberOfPoints);

    [[nodiscard]] int getBrushSize() const;

    void setBrushSize(int brushSize);

    void reset();

signals:
    void brushSizeChanged(int brushSize);
};


#endif //CPP_QT_STUDY_PRINTINFOSTATUSBAR_H
