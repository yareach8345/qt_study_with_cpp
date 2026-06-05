//
// Created by yareach on 26. 6. 4..
//

#ifndef CPP_QT_STUDY_CIRCLEINFO_H
#define CPP_QT_STUDY_CIRCLEINFO_H

#include <QtCore/QPoint>
#include <QtGui/QColor>

struct CircleInfo {
    int size;
    QPoint center;
    int r;
    QColor color;
    bool fill;
};

#endif //CPP_QT_STUDY_CIRCLEINFO_H
