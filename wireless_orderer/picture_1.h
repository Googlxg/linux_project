#ifndef PICTURE_1_H
#define PICTURE_1_H

#include <QWidget>

namespace Ui {
class Picture_1;
}

class Picture_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Picture_1(QWidget *parent = nullptr);
    ~Picture_1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Picture_1 *ui;
};

#endif // PICTURE_1_H
