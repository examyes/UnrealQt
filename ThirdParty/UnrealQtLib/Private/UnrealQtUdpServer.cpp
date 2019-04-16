#include "UnrealQtUdpServer.h"

#include "UnrealQtUdpServerPrivate.h"

UnrealQtUdpServer::UnrealQtUdpServer()
    : m_impl(new UnrealQtUdpServerPrivate)
{

}

UnrealQtUdpServer::~UnrealQtUdpServer()
{
    delete m_impl;
}

void UnrealQtUdpServer::start()
{
    m_impl->start();
}

void UnrealQtUdpServer::stop()
{
    m_impl->stop();
}

void UnrealQtUdpServer::setHostAddr(const std::string &addr)
{
    m_impl->setHostAddr(QString::fromStdString(addr));
}

void UnrealQtUdpServer::setPort(uint16_t port)
{
    m_impl->setPort(port);
}

std::list< std::vector<uint8_t> > UnrealQtUdpServer::readAllPackets()
{
    auto packets = m_impl->readAllPackets();

    std::list< std::vector<uint8_t> > packetsToReturn;

    for (auto packet : packets)
    {
        std::vector<uint8_t> v(packet.constBegin(), packet.constEnd());
        packetsToReturn.push_back(v);
    }

    return packetsToReturn;
}
