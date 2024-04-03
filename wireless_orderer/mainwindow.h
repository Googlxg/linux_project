#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "picture_1.h"
#include "ui_picture_1.h"
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>
#include <QRect>
#include <QDebug>
#include "QTest"
#include "tcpclient.h"
#include "ui_tcpclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /* 文件 */
    QFile file;
    QString caipin[20] = {"鱼香肉丝","红烧猪蹄","白菜粉条","糖醋排骨","炸蘑菇","青椒鸡蛋","肉末粉条","土豆丝","东坡肉","宫保鸡丁","0","卷饼","兰州拉面","馒头","冷面","米饭"};
    int money[20] = {23, 33, 13, 28, 20, 13, 18, 13, 30, 28, 0, 2, 13, 2, 13, 2};
    /* 设置BEEP的状态 */
    bool getBeepState();
    void setBeepOn();

private slots:
    void on_pushButton_21_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_29_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_22_clicked();

    void on_pushButton_12_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    /*第二篇*按钮点击槽函数*/
    void on_pushButton_31_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

public:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
