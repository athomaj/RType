//
//  UDPSocket.cpp
//  ServerRType
//
//  Created by Julien Athomas on 03/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include <string.h>
#include "UDPSocket.hpp"

UDPSocket::UDPSocket(socketType const socket, std::string const& ip, int const port) :
    ASocket(socket)
{
    _data = (char *)malloc(128);
    memset(_data, 0, 128);
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(port);
//    inet_aton(ip.c_str(), &si_other.sin_addr);
    si_other.sin_addr.s_addr=inet_addr(ip.c_str());
//    std::cout << port << ip << std::endl;
}

void UDPSocket::addClientData(struct sockaddr_in* si)
{
    for (unsigned int i=0; i < _udpClients.size(); ++i)
    {
        if (strcmp(inet_ntoa(_udpClients[i].sin_addr), inet_ntoa(si->sin_addr)) == 0 &&
            ntohs(_udpClients[i].sin_port) == ntohs(si->sin_port))
            return ;
    }
    _udpClients.push_back(*si);
}

int UDPSocket::readData()
{
    unsigned char data[128];
    int ret;
    struct sockaddr_in si_other;
    int slen = sizeof(si_other);
    
    memset(data, 0, 128);
#ifdef _WIN32
	ret = recvfrom(_socket, reinterpret_cast<char *>(data), 128, 0,
		reinterpret_cast<struct sockaddr*>(&si_other), &slen);
#else
	ret = recvfrom(_socket, reinterpret_cast<void *>(data), 128, 0,
		reinterpret_cast<struct sockaddr*>(&si_other), reinterpret_cast<socklen_t *>(&slen));
#endif
//    std::cout << "ret: " << ret << std::endl;
    _rData.addData(data, static_cast<int>(ret));
    if (_udpClients.size() != 4)
        addClientData(&si_other);
    return (0);
}

void UDPSocket::writeData()
{
    std::vector<unsigned char> data;
    
    data = _wData.getData();
    unsigned char *buf = Packet::toBuf(data);
    ::sendto(_socket, reinterpret_cast<char *>(buf), data.size(), 0, reinterpret_cast<struct sockaddr *>(&si_other), sizeof(si_other));
    delete[] buf;
}
