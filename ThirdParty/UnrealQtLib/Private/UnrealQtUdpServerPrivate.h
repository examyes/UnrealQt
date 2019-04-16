#pragma once

#include <QObject>
#include <QHostAddress>
#include <QList>
#include <QUdpSocket>

class UnrealQtUdpServerPrivate : public QObject
{
    Q_OBJECT
public:
    UnrealQtUdpServerPrivate();
    ~UnrealQtUdpServerPrivate();

    void start();
    void stop();

    void setHostAddr(const QString &addr);
    void setPort(quint16 port);

    QList<QByteArray> readAllPackets();

private slots:
    void onReadyRead();

private:
    QHostAddress m_hostAddr;
    quint16 m_port;
    QUdpSocket m_udpSocket;
    QList<QByteArray> m_packetList;
};
