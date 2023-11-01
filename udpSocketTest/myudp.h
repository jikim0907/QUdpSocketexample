#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>

class MyUdp : public QObject
{
    Q_OBJECT
public:
    explicit MyUdp(QObject *parent = nullptr);
    QUdpSocket *socket;
    void HelloUDP();

public slots:
    void readyRead();
};

#endif // MYUDP_H
