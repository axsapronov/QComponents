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
    connect( ui->pushButton, SIGNAL(clicked()), this, SLOT(slotShowHideSlide()));
    m_slideWidget = new SlideWidget(this);
    m_slideWidget->hide();
    m_geometry = m_slideWidget->geometry();
    m_boolHide = true;
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
        m_slideWidget->setGeometry(QRect(0, height() - m_slideWidget->height(), width(), m_slideWidget->height()));
}
//------------------------------------------------------------------------------
void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if (abs(ev->pos().y() - height()) < 50)
    {
        if (m_boolHide)
            slotShowHideSlide();
    }
    else
    {
        if (!m_boolHide)
            slotShowHideSlide();
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

    QRect startRect(0, height(), width(), 0);
    QRect endRect(0, height() - m_slideWidget->height(), width(), m_slideWidget->height());

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
}
//------------------------------------------------------------------------------
