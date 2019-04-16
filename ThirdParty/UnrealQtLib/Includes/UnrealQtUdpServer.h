#pragma once

#include <string>
#include <cstdint>
#include <vector>
#include <list>

class UnrealQtUdpServerPrivate;

class UnrealQtUdpServer
{
public:
    UnrealQtUdpServer();
    virtual ~UnrealQtUdpServer();

    void start();
    void stop();

    void setHostAddr(const std::string &addr);
    void setPort(uint16_t port);

    std::list<std::vector<uint8_t>> readAllPackets();


private:
    UnrealQtUdpServerPrivate *m_impl;
};
