//
// Created by yareach on 26. 4. 23..
//

#ifndef CPP_QT_STUDY_ROUNDBUTTON_H
#define CPP_QT_STUDY_ROUNDBUTTON_H

#include <QtWidgets/QPushButton>


class RoundButton: public QPushButton {
    Q_OBJECT
private:
    unsigned int rotationSteps;
public:
    using QPushButton::QPushButton;

    explicit RoundButton(const QString &text, QWidget *parent);

protected:
    void enterEvent(QEnterEvent *event) override;

signals:
    void moved(unsigned int rotationSteps);
};



#endif //CPP_QT_STUDY_ROUNDBUTTON_H
