#include "myudp.h"

MyUdp::MyUdp(QObject *parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 5000);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));//when recieve some data at this socket instance\
    //generate the readyRead signal( readyRead is in class QUdpSocket)
}

void MyUdp::HelloUDP(){
    QByteArray Data;
    Data.append("Hello from UDP");
    socket->writeDatagram(Data, QHostAddress::LocalHost, 5000); //write Data to Localhost:5000
    //and generate the readyRead signal so that call function MyUdp::readyRead()
    }

void MyUdp::readyRead(){
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort); //readDatagram function can
    //read Data(Data, QHostAddress, Port info ... from the binded socket)

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}

