#ifndef SERVER_H
#define SERVER_H
#include "common.h"
#include <QtNetwork>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
class QUdpSocket;
class list;
class Server:QObject
{
	Q_OBJECT
public:
    Server();
    //广播上线消息
    void LoginBrocast(QString username);
    //广播下线消息
    void LogoutBrocast(QString username);
   //处理收到的聊天消息
    void ProcessDataMsg();
    //处理收到的数据
    void ProcessRecvMsg(QByteArray data);
    //处理收到的控制消息
    void ProcessControlMsg();
    //ui显示收到的消息
    void ShowReceiveMsg();
    //发送消息
    void SendMsg(QByteArray data);
private slots:
    //点击发送按钮触发的事件，并处理需要发送的消息
    void SendProcess();
    //读取收到的数据
    void ReadPendingData();
 

private:
    //服务器的套接字
    QUdpSocket *udpServerSocket;
    //当前在线的用户列表
    QMap<QString,QHostAddress> *mOnlineUsrMap;
    //本机ip地址
    QHostAddress mIP;
    QXmlStreamReader readXml;
};

#endif // SERVER_H
