/*
 * Sapronov Alexander sapronov.alexander92@gmail.com
 * 2013-07-18
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "slidewidget.h"
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
//    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *event);
    void mouseMoveEvent(QMouseEvent *ev);

private slots:
    void slotShowHideSlide();

private:
    Ui::MainWindow *ui;

    SlideWidget *m_slideWIdget;

    QPropertyAnimation *m_animation;

    void showHideSlideWidget(bool f_flag);
    bool m_boolHide;
    QRect m_geometry;
};

#endif // MAINWINDOW_H
