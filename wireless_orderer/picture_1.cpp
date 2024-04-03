#include "picture_1.h"
#include "ui_picture_1.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
Picture_1::Picture_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Picture_1)
{
    ui->setupUi(this);
}

Picture_1::~Picture_1()
{
    delete ui;
}

void Picture_1::on_pushButton_clicked()
{
    this->close();
    MainWindow* mainwindows = new MainWindow();
    mainwindows->show();
}
