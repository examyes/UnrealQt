#include "UnrealQtUdpServerPrivate.h"

UnrealQtUdpServerPrivate::UnrealQtUdpServerPrivate()
    : QObject(nullptr)
{
    connect(&m_udpSocket, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
}

UnrealQtUdpServerPrivate::~UnrealQtUdpServerPrivate()
{
    stop();
}

void UnrealQtUdpServerPrivate::start()
{
    m_udpSocket.bind(m_port);
}

void UnrealQtUdpServerPrivate::stop()
{
    m_udpSocket.close();
}

void UnrealQtUdpServerPrivate::setHostAddr(const QString &addr)
{
    m_hostAddr.setAddress(addr);
}

void UnrealQtUdpServerPrivate::setPort(quint16 port)
{
    m_port = port;
}

QList<QByteArray> UnrealQtUdpServerPrivate::readAllPackets()
{
    QList<QByteArray> packetList = m_packetList;
    m_packetList.clear();
    return packetList;
}

void UnrealQtUdpServerPrivate::onReadyRead()
{
    while (m_udpSocket.hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(int(m_udpSocket.pendingDatagramSize()));

        QHostAddress sender;
        quint16 senderPort;

        auto readSize = m_udpSocket.readDatagram(datagram.data(), datagram.size(),
                              &sender, &senderPort);
        Q_UNUSED(readSize);

        m_packetList.append(datagram);
    }
}
