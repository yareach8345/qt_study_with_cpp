//
// Created by yareach on 26. 5. 31..
//

#ifndef CPP_QT_STUDY_BRUSHSIZELABEL_H
#define CPP_QT_STUDY_BRUSHSIZELABEL_H

#include <QtWidgets/QLabel>
#include <QtWidgets/QInputDialog>

class BrushSizeLabel: public QLabel {
    Q_OBJECT
private:
    int brushSize;

    static QString brushSizeInfoTemplate;

    void updateBrushSizeLabel();
protected:
    void mousePressEvent(QMouseEvent *event) override;

public:
    explicit BrushSizeLabel(int initValue = 1);

    void setSize(int newSize);

    [[nodiscard]] int getSize() const;

signals:
    void sizeChanged(int newSize);
};


#endif //CPP_QT_STUDY_BRUSHSIZELABEL_H
