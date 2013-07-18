/*
 * Sapronov Alexander sapronov.alexander92@gmail.com
 * 2013-07-18
 */

#include "slidetwo.h"
#include "ui_slidetwo.h"

SlideTwo::SlideTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlideTwo)
{
    ui->setupUi(this);
}

SlideTwo::~SlideTwo()
{
    delete ui;
}

void SlideTwo::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
