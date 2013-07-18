/*
 * Sapronov Alexander sapronov.alexander92@gmail.com
 * 2013-07-18
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect( ui->pB, SIGNAL(clicked()), this, SLOT( slotShowHideSlide()));
    connect( ui->pBTwo, SIGNAL(clicked()), this, SLOT( slotShowHideSlideTwo()));

    m_slideWidget = new SlideWidget(this);
    m_slideWidget->hide();
    m_geometry = m_slideWidget->geometry();
    m_boolHide = true;

    m_slideTwo = new SlideTwo(this);
    m_slideTwo->hide();
    m_geometryTwo = m_slideTwo->geometry();
    m_boolHideTwo = true;

    ui->centralWidget->setMouseTracking(true);
}
//------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//------------------------------------------------------------------------------
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    if (!m_boolHide)
        m_slideWidget->setGeometry(QRect(width() - m_slideWidget->width(), 0, m_slideWidget->width(),height()));

    if (!m_boolHideTwo)
        m_slideTwo->setGeometry(QRect(0,0, m_slideTwo->width(), height()));
}
//------------------------------------------------------------------------------
void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if (abs(ev->pos().x() - width()) < 50)
    {
        if (m_boolHide)
            slotShowHideSlide();
    }
    else
    {
        if (!m_boolHide)
            slotShowHideSlide();
    }

    if (ev->pos().x() < 50)
    {
        if (m_boolHideTwo)
            slotShowHideSlideTwo();
    }
    else
    {
        if (!m_boolHideTwo)
            slotShowHideSlideTwo();
    }
}
//------------------------------------------------------------------------------
void MainWindow::slotShowHideSlide()
{
    if (m_slideWidget->isHidden())
        m_slideWidget->show();

    showHideSlideWidget(m_boolHide);
}
//------------------------------------------------------------------------------
void MainWindow::showHideSlideWidget(bool f_flag)
{
    if (f_flag)
        m_slideWidget->setGeometry(m_geometry);

    m_animation = new QPropertyAnimation(m_slideWidget, "geometry");
    m_animation->setDuration(300);

    QRect startRect(width(), 0, 0, height());
    QRect endRect(width() - m_slideWidget->width(), 0, m_slideWidget->width(), height());

    if (f_flag)
    {
        m_animation->setStartValue(startRect);
        m_animation->setEndValue(endRect);
    }
    else
    {
        m_animation->setStartValue(endRect);
        m_animation->setEndValue(startRect);
    }

    m_animation->start();
    m_boolHide = !f_flag;

//    QRect t_startRect(width(), 0, 0, height());
//    QRect t_endRect(width() - m_slideWidget->width(), 0, m_slideWidget->width(), height());
//    m_boolHide = showHideSlide(f_flag, m_slideWidget, t_startRect, t_endRect, m_geometry);
}
//------------------------------------------------------------------------------
void MainWindow::slotShowHideSlideTwo()
{
    if (m_slideTwo->isHidden())
        m_slideTwo->show();

    showHideSlideWidgetTwo(m_boolHideTwo);
}
//------------------------------------------------------------------------------
void MainWindow::showHideSlideWidgetTwo(bool f_flag)
{
    if (f_flag)
        m_slideTwo->setGeometry(m_geometryTwo);

    m_animation = new QPropertyAnimation(m_slideTwo, "geometry");
    m_animation->setDuration(300);

    QRect startRect(0, 0, 0, height());
    QRect endRect(0, 0, m_slideTwo->width(), height());

    if (f_flag)
    {
        m_animation->setStartValue(startRect);
        m_animation->setEndValue(endRect);
    }
    else
    {
        m_animation->setStartValue(endRect);
        m_animation->setEndValue(startRect);
    }
    m_animation->start();
    m_boolHideTwo = !f_flag;
}
//------------------------------------------------------------------------------
//bool MainWindow::showHideSlide(bool f_flag, QWidget *f_widget, QRect f_start, QRect f_end, QRect f_geometry)
//{
//    if (f_flag)
//        f_widget->setGeometry(f_geometry);

//    m_animation = new QPropertyAnimation(f_widget, "geometry");
//    m_animation->setDuration(300);

//    if (f_flag)
//    {
//        m_animation->setStartValue(f_start);
//        m_animation->setEndValue(f_end);
//    }
//    else
//    {
//        m_animation->setStartValue(f_end);
//        m_animation->setEndValue(f_start);
//    }

//    m_animation->start();
//    return !f_flag;
//}
//------------------------------------------------------------------------------
