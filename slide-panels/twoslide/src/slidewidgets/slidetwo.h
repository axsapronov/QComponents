/*
 * Sapronov Alexander sapronov.alexander92@gmail.com
 * 2013-07-18
 */

#ifndef SLIDETWO_H
#define SLIDETWO_H

#include <QWidget>

namespace Ui {
class SlideTwo;
}

class SlideTwo : public QWidget
{
    Q_OBJECT

public:
    explicit SlideTwo(QWidget *parent = 0);
    ~SlideTwo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SlideTwo *ui;
};

#endif // SLIDETWO_H
