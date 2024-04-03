#include "tcpclient.h"
#include "ui_tcpclient.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    ui->pushButton_2->setEnabled(false);
    ui->lineEdit->setText("192.168.101.1");
    ui->lineEdit_2->setText("8080");
    ui->lineEdit_3->setText("请输入......");
    connect(tcpSocket, SIGNAL(connected()),
            this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(disconnected()),
            this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(readyRead()),
            this, SLOT(receiveMessages()));
    connect(ui->pushButton_4, SIGNAL(clicked()),
            this, SLOT(sendMessages()));
    connect(tcpSocket,
            SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,
            SLOT(socketStateChange(QAbstractSocket::SocketState)));


}
TcpClient::~TcpClient()
{
    delete ui;
}

//返回按钮
void TcpClient::on_pushButton_3_clicked()
{
    this->hide();
    MainWindow* mainwindows = new MainWindow();
    mainwindows->show();
}

//开始连接
void TcpClient::on_pushButton_clicked()
{
    QString HostIp = ui->lineEdit->text();
    QString HostDuankou = ui->lineEdit_2->text();
    if (tcpSocket->state() != tcpSocket->ConnectedState)
    {
         tcpSocket->connectToHost(ui->lineEdit->text(),HostDuankou.toInt());
         ui->textBrowser->append("正在准备连接......");
    }
}
//断开链接
void TcpClient::on_pushButton_2_clicked()
{
    /* 断开连接 */
    tcpSocket->disconnectFromHost();

    /* 关闭socket*/
    tcpSocket->close();
}
void TcpClient::connected()
{
    /* 显示已经连接 */
    ui->textBrowser->append("已经连上服务端");
    /* 设置按钮与下拉列表框的状态 */
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void TcpClient::disconnected()
{
    /* 显示已经连接 */
    ui->textBrowser->append("已经断开服务端");
    /* 设置按钮与下拉列表框的状态 */
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}


/* 客户端接收消息 */
void TcpClient::receiveMessages()
{
    /* 读取接收到的消息 */
    QString messages = tcpSocket->readAll();
    ui->textBrowser->append("服务端：" + messages);
    qDebug()<<tcpSocket->state()<<endl;
}

/* 客户端发送消息 */
void TcpClient::sendMessages()
{
    if(NULL == tcpSocket)
        return;

    if(tcpSocket->state() == tcpSocket->ConnectedState)
    {
        /* 客户端显示发送的消息 */
        ui->textBrowser->append("客户端：" + ui->lineEdit_3->text());
        /* 发送消息 */
        tcpSocket->write(ui->lineEdit_3->text().toUtf8().data());
    }
}

/* 客户端状态改变 */
void TcpClient::socketStateChange(QAbstractSocket::SocketState state)
{
    switch (state) {
    case QAbstractSocket::UnconnectedState:
        ui->textBrowser->append("scoket状态：UnconnectedState");
        break;
    case QAbstractSocket::ConnectedState:
        ui->textBrowser->append("scoket状态：ConnectedState");
        break;
    case QAbstractSocket::ConnectingState:
        ui->textBrowser->append("scoket状态：ConnectingState");
        break;
    case QAbstractSocket::HostLookupState:
        ui->textBrowser->append("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ClosingState:
        ui->textBrowser->append("scoket状态：ClosingState");
        break;
    case QAbstractSocket::ListeningState:
        ui->textBrowser->append("scoket状态：ListeningState");
        break;
    case QAbstractSocket::BoundState:
        ui->textBrowser->append("scoket状态：BoundState");
        break;
    default:
        break;
    }
}

void TcpClient::on_pushButton_5_clicked()
{
    ui->textBrowser->clear();
}



