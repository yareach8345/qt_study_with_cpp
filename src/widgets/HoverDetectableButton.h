//
// Created by yareach on 26. 4. 23..
//

#ifndef CPP_QT_STUDY_HOVERDETECTABLEBUTTON_H
#define CPP_QT_STUDY_HOVERDETECTABLEBUTTON_H

#include <QtWidgets/QPushButton>


class HoverDetectableButton: public QPushButton {
private:
    int rotationSteps;
public:
    using QPushButton::QPushButton;

    explicit HoverDetectableButton(const QString &text, QWidget *parent);

protected:
    void enterEvent(QEnterEvent *event) override;

    void leaveEvent(QEvent *event) override;
};



#endif //CPP_QT_STUDY_HOVERDETECTABLEBUTTON_H
