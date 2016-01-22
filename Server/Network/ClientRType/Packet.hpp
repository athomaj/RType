//
//  Packet.hpp
//  ClientRType
//
//  Created by Julien Athomas on 15/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef Packet_hpp
#define Packet_hpp

#include <vector>
#include <iostream>

enum instruct
{
    CONNECT = 1,
    ROOM,
    CREATE,
    JOIN,
    LEAVE,
    READY,
    START,
    DATAMAP,
    ENDGAME,
    SCORE,
    GAMEDATA
};

class Packet;

Packet* unserPacket(std::vector<unsigned char>&);
unsigned char *serPacket(Packet packet);

class Packet
{
public:
    Packet(int const, int const, int const, std::vector<unsigned char>&);
    int getMagic() const;
    int getSize() const;
    int getType() const;
    std::vector<unsigned char>& getData();
    static Packet& build(int instruct, std::string const& data);
    static unsigned char* toBuf(std::vector<unsigned char>&);
private:
    int _magic;
    int _size;
    int _type;
    std::vector<unsigned char> _data;
};

#endif /* Packet_hpp */
