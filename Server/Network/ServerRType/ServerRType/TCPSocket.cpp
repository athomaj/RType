//
//  TCPSocket.cpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "TCPSocket.hpp"

TCPSocket::TCPSocket(socketType const socket) :
ASocket(socket)
{
    _data = (char *)malloc(128);
    memset(_data, 0, 128);
}

int TCPSocket::readData()
{
    unsigned char data[128];
    int ret;

    memset(data, 0, 128);
#ifdef _WIN32
	if ((ret = recv(_socket, reinterpret_cast<char *>(data), 128, 0)) <= 0)
		return (-1);
#else
	if ((ret = recv(_socket, reinterpret_cast<void *>(data), 128, 0)) <= 0)
		return (-1);
#endif
    _rData.addData(data, static_cast<int>(ret));
    return (0);
}

void TCPSocket::writeData()
{
    std::vector<unsigned char> data;
    
    data = _wData.getData();
    unsigned char *buf = Packet::toBuf(data);
    ::send(_socket, reinterpret_cast<char *>(buf), data.size(), 0);
    delete[] buf;
    _writable = false;
}
