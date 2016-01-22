//
//  ASocket.hpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ASocket_hpp
#define ASocket_hpp

#include "ISocket.h"

class ASocket : public ISocket
{
public:
    ASocket(socketType const);
    virtual socketType& getFd();
    virtual int readData() = 0;
    virtual void writeData() = 0;
    virtual void writeUdpData(struct sockaddr_in&);
    virtual bool dataToWrite();
    virtual std::string& getName();
    virtual std::vector<struct sockaddr_in>& getUdpClients();
    virtual int getScore() const;
    virtual void incScore();
    virtual void resetScore();
    
    template<class T>
    T getData(T (*unserialize)(std::vector<unsigned char>&))
    {
        auto tmp = _rData.getData();
        if (!tmp.size() || tmp.size() < 12)
            throw std::runtime_error("The buffer is empty");
        return (unserialize(tmp));
    }
    
    template<class T>
    void addData(T data, unsigned char *(*serialize)(T))
    {
        unsigned char *newdata;
        
        newdata = serialize(data);
        _writable = true;
        _wData.addData(newdata, static_cast<int>(data.getSize()));
    }
protected:
    char *_data;
    socketType _socket;
    bool _writable;
    CBuf _wData;
    CBuf _rData;
    std::string _name;
    struct sockaddr_in si_other;
    std::vector<struct sockaddr_in> _udpClients;
    int _score;
    int _highScore;
};


#endif /* ASocket_hpp */
