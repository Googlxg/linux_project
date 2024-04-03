#include "mainwindow.h"
#include "picture_1.h"
#include "ui_picture_1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Picture_1 picture_1 ;
    w.show();
    return a.exec();
}
