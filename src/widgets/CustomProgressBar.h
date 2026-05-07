//
// Created by yareach on 26. 5. 6..
//

#ifndef CPP_QT_STUDY_CUSTOMPROGRESSBAR_H
#define CPP_QT_STUDY_CUSTOMPROGRESSBAR_H

#include <QtWidgets/QProgressBar>

#include "../data/Range.h"

class CustomProgressBar: public QProgressBar {
    Q_OBJECT
private:
    Range normal_range;

    void update_color();
public:
    explicit CustomProgressBar(Range normal_range, int max = 100, int min = 0);

    void setValue(int value);
};


#endif //CPP_QT_STUDY_CUSTOMPROGRESSBAR_H
