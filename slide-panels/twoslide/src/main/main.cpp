/*
 * Sapronov Alexander sapronov.alexander92@gmail.com
 * 2013-07-18
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
