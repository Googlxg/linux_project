#include "mainwindow.h"
#include "ui_mainwindow.h"

quint32 buffer[100]= {0};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 1024, 600);
    qDebug()<<"程序开始"<<endl;
    {

        ui->lineEdit_6->setText(QString::number(buffer[5]));
        ui->lineEdit_7->setText(QString::number(buffer[6]));
        ui->lineEdit_8->setText(QString::number(buffer[7]));
        ui->lineEdit_9->setText(QString::number(buffer[8]));
        ui->lineEdit_10->setText(QString::number(buffer[9]));
        ui->lineEdit_11->setText(QString::number(buffer[0]));
        ui->lineEdit_12->setText(QString::number(buffer[1]));
        ui->lineEdit_13->setText(QString::number(buffer[2]));
        ui->lineEdit_14->setText(QString::number(buffer[3]));
        ui->lineEdit_15->setText(QString::number(buffer[4]));
        ui->lineEdit_16->setText(QString::number(buffer[11]));
        ui->lineEdit_17->setText(QString::number(buffer[12]));
        ui->lineEdit_18->setText(QString::number(buffer[13]));
        ui->lineEdit_19->setText(QString::number(buffer[14]));
        ui->lineEdit_20->setText(QString::number(buffer[15]));

    }
    file.setFileName("/sys/devices/platform/leds/leds/beep/brightness");

    if (!file.exists())
        qDebug()<<"未获取到BEEP设备！"<<endl;


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBeepOn()
{
    /* 在设置BEEP状态时先读取 */
    bool state = getBeepState();

    /* 如果文件不存在，则返回 */
    if (!file.exists())
        return;

    if(!file.open(QIODevice::ReadWrite))
        qDebug()<<file.errorString();

    QByteArray buf[2] = {"0", "1"};

    file.write(buf[1]);
    file.close();
    QTest::qSleep(100);
    /* 如果文件不存在，则返回 */
    if (!file.exists())
        return;

    if(!file.open(QIODevice::ReadWrite))
        qDebug()<<file.errorString();
    file.write(buf[0]);
    file.close();

    getBeepState();
}

bool MainWindow::getBeepState()
{
    /* 如果文件不存在，则返回 */
    if (!file.exists())
        return false;

    if(!file.open(QIODevice::ReadWrite))
        qDebug()<<file.errorString();

    QTextStream in(&file);

    /* 读取文件所有数据 */
    QString buf = in.readLine();

    /* 打印出读出的值 */
    qDebug()<<"buf: "<<buf<<endl;
    file.close();
    if(buf == '1')
        return true;
    else if(buf == '0')
        return false;
}



void MainWindow::on_pushButton_21_clicked()
{
    buffer[0]--;
    QString str = QString::number(buffer[0]);
    ui->lineEdit_11->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_22_clicked()
{
    buffer[1]--;
    QString str = QString::number(buffer[1]);
    ui->lineEdit_12->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_23_clicked()
{
    buffer[2]--;
    QString str = QString::number(buffer[2]);
    ui->lineEdit_13->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_24_clicked()
{
    buffer[3]--;
    QString str = QString::number(buffer[3]);
    ui->lineEdit_14->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_25_clicked()
{
    buffer[4]--;
    QString str = QString::number(buffer[4]);
    ui->lineEdit_15->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}

void MainWindow::on_pushButton_26_clicked()
{
    buffer[0]++;
    QString str = QString::number(buffer[0]);
    ui->lineEdit_11->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_27_clicked()
{
    buffer[1]++;
    QString str = QString::number(buffer[1]);
    ui->lineEdit_12->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_28_clicked()
{
    buffer[2]++;
    QString str = QString::number(buffer[2]);
    ui->lineEdit_13->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_29_clicked()
{
    buffer[3]++;
    QString str = QString::number(buffer[3]);
    ui->lineEdit_14->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_30_clicked()
{
    buffer[4]++;
    QString str = QString::number(buffer[4]);
    ui->lineEdit_15->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}


void MainWindow::on_pushButton_11_clicked()
{
    buffer[5]--;
    QString str = QString::number(buffer[5]);
    ui->lineEdit_6->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_12_clicked()
{
    buffer[6]--;
    QString str = QString::number(buffer[6]);
    ui->lineEdit_7->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_13_clicked()
{
    buffer[7]--;
    QString str = QString::number(buffer[7]);
    ui->lineEdit_8->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_14_clicked()
{
    buffer[8]--;
    QString str = QString::number(buffer[8]);
    ui->lineEdit_9->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_15_clicked()
{
    buffer[9]--;
    QString str = QString::number(buffer[9]);
    ui->lineEdit_10->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}

void MainWindow::on_pushButton_16_clicked()
{
    buffer[5]++;
    QString str = QString::number(buffer[5]);
    ui->lineEdit_6->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_17_clicked()
{
    buffer[6]++;
    QString str = QString::number(buffer[6]);
    ui->lineEdit_7->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_18_clicked()
{
    buffer[7]++;
    QString str = QString::number(buffer[7]);
    ui->lineEdit_8->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_19_clicked()
{
    buffer[8]++;
    QString str = QString::number(buffer[8]);
    ui->lineEdit_9->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_20_clicked()
{
    buffer[9]++;
    QString str = QString::number(buffer[9]);
    ui->lineEdit_10->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}


/*
 * 这个是第二篇的按钮点击槽函数
 */
void MainWindow::on_pushButton_31_clicked()
{
    buffer[11]--;
    QString str = QString::number(buffer[11]);
    ui->lineEdit_16->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_32_clicked()
{
    buffer[12]--;
    QString str = QString::number(buffer[12]);
    ui->lineEdit_17->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_33_clicked()
{
    buffer[13]--;
    QString str = QString::number(buffer[13]);
    ui->lineEdit_18->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_34_clicked()
{
    buffer[14]--;
    QString str = QString::number(buffer[14]);
    ui->lineEdit_19->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_35_clicked()
{
    buffer[15]--;
    QString str = QString::number(buffer[15]);
    ui->lineEdit_20->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}

void MainWindow::on_pushButton_36_clicked()
{
    buffer[11]++;
    QString str = QString::number(buffer[11]);
    ui->lineEdit_16->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_37_clicked()
{
    buffer[12]++;
    QString str = QString::number(buffer[12]);
    ui->lineEdit_17->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_38_clicked()
{
    buffer[13]++;
    QString str = QString::number(buffer[13]);
    ui->lineEdit_18->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_39_clicked()
{
    buffer[14]++;
    QString str = QString::number(buffer[14]);
    ui->lineEdit_19->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}
void MainWindow::on_pushButton_40_clicked()
{
    buffer[15]++;
    QString str = QString::number(buffer[15]);
    ui->lineEdit_20->setText(str);
    qDebug()<<str<<endl;
    setBeepOn();
}



/*
 *第二篇与第一篇按钮进行转换
 */
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    setBeepOn();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    setBeepOn();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
    Picture_1* picture_1  = new Picture_1();
    picture_1->show();

    setBeepOn();
}

void MainWindow::on_pushButton_6_clicked()
{
    this->close();
    TcpClient* tcpclient = new TcpClient();
    tcpclient->show();
    setBeepOn();

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    setBeepOn();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->textBrowser->clear();
    int i = 0;
    QString kongge = " ";
    ui->textBrowser->append("菜品"+kongge+kongge+"数量"+"价格");
    for(i = 0;i <= 16;i++)
    {
        if(buffer[i] != 0)
        {
            ui->textBrowser->append(caipin[i]+" : "+QString::number(buffer[i])+"   "+QString::number(money[i]));
        }
    }


    setBeepOn();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->textBrowser->clear();
    int i = 0;
    QString kongge = " ";
    ui->textBrowser->append("菜品"+kongge+kongge+"数量"+"价格");
    for(i = 0;i <= 16;i++)
    {
        if(buffer[i] != 0)
        {
            ui->textBrowser->append(caipin[i]+" : "+QString::number(buffer[i])+"   "+QString::number(money[i]));
        }
    }


    setBeepOn();
}

//void MainWindow::on_pushButton_7_clicked()
//{
//    this->close();
//    TcpClient* tcpclient = new TcpClient();
//    QString text_1 = ui->textBrowser->toPlainText();
//    tcpclient->on_pushButton_clicked();
//    tcpclient->ui->lineEdit_3->setText(text_1);
//    //tcpclient->sendMessages();
//    tcpclient->show();
//    setBeepOn();
//}

void MainWindow::on_pushButton_7_clicked()
{
    QTcpSocket* tcpSocket = new QTcpSocket();
    QString text_1 = ui->textBrowser->toPlainText();
    if (tcpSocket->state() != tcpSocket->ConnectedState)
    {
         tcpSocket->connectToHost("192.168.101.1",8080);
    }
    qDebug()<<tcpSocket->state() <<endl;
    if(tcpSocket->state() == tcpSocket->ConnectingState)
    {
        /* 客户端显示发送的消息 */
        //ui->textBrowser->append("客户端：" + text_1);
        /* 发送消息 */
        tcpSocket->write(text_1.toUtf8().data());
    }

}
