//
// Created by yareach on 26. 5. 8..
//

#ifndef CPP_QT_STUDY_CUSTOMLABEL_H
#define CPP_QT_STUDY_CUSTOMLABEL_H

#include <QtWidgets/QLabel>


class CustomLabel: public QLabel {
    Q_OBJECT
protected:
    void resizeEvent(QResizeEvent *event) override;
public:
    explicit CustomLabel(const QString &text);
signals:
    void resized(int size);
};


#endif //CPP_QT_STUDY_CUSTOMLABEL_H
