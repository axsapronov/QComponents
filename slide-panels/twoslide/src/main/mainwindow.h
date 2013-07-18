/*
 * Sapronov Alexander sapronov.alexander92@gmail.com
 * 2013-07-18
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "slidewidget.h"
#include "slidetwo.h"
#include <QPropertyAnimation>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event);
    void mouseMoveEvent(QMouseEvent *ev);

private slots:
    void slotShowHideSlide();
    void slotShowHideSlideTwo();

private:
    Ui::MainWindow *ui;

    SlideWidget *m_slideWidget;
    SlideTwo *m_slideTwo;

    QPropertyAnimation *m_animation;

    void showHideSlideWidget(bool f_flag);
    void showHideSlideWidgetTwo(bool f_flag);
    bool m_boolHide;
    bool m_boolHideTwo;
    QRect m_geometry;
    QRect m_geometryTwo;

//    bool showHideSlide(bool f_flag, QWidget *f_widget, QRect f_start, QRect f_end, QRect f_geometry);
};

#endif // MAINWINDOW_H
