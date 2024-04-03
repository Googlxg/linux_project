#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QNetworkInterface>
#include <QTcpSocket>
#include "mainwindow.h"
#include "ui_mainwindow.h"
namespace Ui {
class TcpClient;
}
class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    QTcpSocket* tcpSocket;
    Ui::TcpClient *ui;

public slots:
    void on_pushButton_clicked();


private slots:
    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();

    void connected();

    void disconnected();


    /* 接收到消息 */
    void receiveMessages();

    /* 发送消息 */
    void sendMessages();

    /* 连接状态改变槽函数 */
    void socketStateChange(QAbstractSocket::SocketState);

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();
};

#endif // TCPCLIENT_H
