
<<<<<<< HEAD
#include "server.h"
=======
#define UDP_LISTEN_PORT 6666

>>>>>>> 574dad37f46c4ad150750a7519904e51acfb3ca2
Server::Server()
{
    //获取本机ip地址
    QList<QHostAddress> vAddressList = QNetworkInterface::allAddresses();
    for(int i=0;i<vAddressList.size();i++)
    {
        if((vAddressList.at(i)!=QHostAddress::LocalHost)&&(vAddressList.at(i).protocol()==QAbstractSocket::IPv4Protocol))
        {
<<<<<<< HEAD
            myIP=vAddressList.at(i);
            break;
        }
    }
    remoteIP=QHostAddress::Broadcast;
    myUpdPort=UDP_LISTEN_PORT;
    remoteUpdPort=UDP_LISTEN_PORT;
=======
            mIP=vAddressList.at(i);
            break;
        }
    }

>>>>>>> 574dad37f46c4ad150750a7519904e51acfb3ca2
    //初始化套接字和在线用户
    udpSocket=new QUdpSocket(this);
    udpSocket->bind(myUpdPort, QUdpSocket::ShareAddress);
    mOnlineUsrMap=new QMap<QString,QHostAddress>();
    //绑定接受函数
    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(ReadPendingData()));
}
void
Server::LoginBrocast(QString username)
{
<<<<<<< HEAD
    qDebug("广播上线消息");
    QByteArray datagram=CMsgOperation::createBroadcast(1, username, myIP.toString());
    udpSocket->writeDatagram(datagram.data(),datagram.size(),remoteIP,remoteUpdPort);
=======
    QByteArray datagram=CMsgOperation::createBroadcast(1, username, mIP.toString());
    udpServerSocket->writeDatagram(datagram.data(),datagram.size(),QHostAddress::Broadcast,UDP_LISTEN_PORT);

>>>>>>> 574dad37f46c4ad150750a7519904e51acfb3ca2
}
void
Server::LogoutBrocast(QString username)
{
    qDebug("广播下线消息");
    QByteArray datagram=CMsgOperation::createBroadcast(0, username, myIP.toString());
    udpSocket->writeDatagram(datagram.data(),datagram.size(),remoteIP,remoteUpdPort);
}

<<<<<<< HEAD
=======
    while (udpServerSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpServerSocket->pendingDatagramSize());
        udpServerSocket->readDatagram(datagram.data(), datagram.size());
        ProcessRecvMsg(datagram);
        // qDebug(datagram.data());
    }

}
>>>>>>> 574dad37f46c4ad150750a7519904e51acfb3ca2
void
Server::ProcessRecvMsg(QByteArray data)
{
    QJsonObject json=CMsgOperation::getJsonObject(data);
    QStringList keyList = json.keys();
    QStringList::iterator it=keyList.begin();
    if((*it)=="chatMsg"){
        //收到一般数据
        QJsonObject dataJson=json.value(*it).toObject();
        ProcessDataMsg(dataJson);
    }
    else if((*it)=="online"||(*it)=="offline") {
        QString username=NULL;
        QString ipString=NULL;
        QJsonObject attr=json.value(*it).toObject();
        username=attr.value("userName").toString();
        ipString=attr.value("ipAddress").toString();
        QHostAddress ip=QHostAddress(ipString);
        if((*it)=="online"){
            mOnlineUsrMap->insert(username,ip);
            //构造信号函数，通知窗口更新用户列表
            emit NewUsrOnline(username);
        }
        else if((*it)=="offline"){
            QMap<QString,QHostAddress>::iterator it;
            it= mOnlineUsrMap->find(username);
            if(it!=mOnlineUsrMap->end()){
                mOnlineUsrMap->erase(it);
                //用户下线了，构造信号函数，通知窗口更新用户列表
<<<<<<< HEAD
                emit OldUsrOffline(username);
=======
>>>>>>> 574dad37f46c4ad150750a7519904e51acfb3ca2
            }
        }
    }

}


