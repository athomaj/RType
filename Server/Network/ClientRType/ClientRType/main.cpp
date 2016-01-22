//
//  main.cpp
//  ClientRType
//
//  Created by Julien Athomas on 12/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ClientTCP.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "menu.hh"
#include "Loader.hh"
#include "menuWindow.hh"
#include "Thread.hpp"
#include "Packet.hpp"

int main(int argc, const char * argv[])
{
//    Packet pack = Packet::build(1, "tim le noob");
//    
//    
//    unsigned char *data = serPacket(pack);
//    
//    Packet *newPack = unserPacket(data);
//    
//    std::cout << newPack->getType() << std::endl;
//    std::cout << newPack->getSize() << std::endl;
//    auto datas = newPack->getData();
//    
//    for (unsigned int i=0; i<datas.size(); ++i)
//    {
//        std::cout << datas[i] << std::endl;
//    }
    MenuWindow win(1701, 1056, "R-TYPE");

    win.checkEvent();    
    return 0;
}
