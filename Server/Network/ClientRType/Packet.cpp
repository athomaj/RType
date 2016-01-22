//
//  Packet.cpp
//  ClientRType
//
//  Created by Julien Athomas on 15/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "Packet.hpp"

Packet::Packet(int const magic, int const size, int const type, std::vector<unsigned char>& data) :
    _magic(magic), _size(size), _type(type), _data(data)
{
}

int Packet::getMagic() const
{
    return _magic;
}

int Packet::getSize() const
{
    return _size;
}

int Packet::getType() const
{
    return _type;
}

std::vector<unsigned char>& Packet::getData()
{
    return _data;
}

Packet& Packet::build(int instruct, std::string const& data)
{
    int size = 12;
    std::vector<unsigned char> datas;
    for (unsigned int i=0; i < data.length(); ++i)
    {
        datas.push_back(data[i]);
        ++size;
    }
    Packet *pack = new Packet(0xBB, size, instruct, datas);
    return (*pack);
}

Packet* unserPacket(std::vector<unsigned char>& data)
{
    unsigned int *magic = reinterpret_cast<unsigned int*>(const_cast<unsigned char *>(&data[0]));
    unsigned int *size = reinterpret_cast<unsigned int*>(const_cast<unsigned char *>(&data[4]));
    unsigned int *type = reinterpret_cast<unsigned int*>(const_cast<unsigned char *>(&data[8]));
    std::vector<unsigned char> datas;
    
    for (unsigned int i=0; i< (*size) - 12; ++i)
    {
        datas.push_back(data[i + 12]);
    }
    Packet* newPacket = new Packet(*magic, *size, *type, datas);
    return (newPacket);
}

unsigned char* Packet::toBuf(std::vector<unsigned char> &data)
{
    unsigned char *buf = new unsigned char[data.size()];
    
    for (unsigned int i=0;i<data.size(); ++i)
    {
        buf[i] = data[i];
    }
    return buf;
}

unsigned char *serPacket(Packet packet)
{
    unsigned int magicTmp = packet.getMagic();
    unsigned int sizeTmp = packet.getSize();
    unsigned int typeTmp = packet.getType();
    auto data = packet.getData();
    unsigned char *magic = reinterpret_cast<unsigned char *>(&magicTmp);
    unsigned char *size = reinterpret_cast<unsigned char *>(&sizeTmp);
    unsigned char *type = reinterpret_cast<unsigned char *>(&typeTmp);
    
    unsigned char *buf = new (unsigned char[4096]);
    for (unsigned int i=0; i<4; ++i)
    {
        buf[i] = magic[i];
        buf[i + 4] = size[i];
        buf[i + 8] = type[i];
    }
    for (unsigned int i=0; i<data.size(); ++i)
    {
        buf[i + 12] = data[i];
    }
    return buf;
}

