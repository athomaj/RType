//
//  IThreadCond.h
//  ServerRType
//
//  Created by Julien Athomas on 10/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef IThreadCond_h
#define IThreadCond_h

class IThreadCond
{
public:
    virtual void init() = 0;
    virtual void wait() = 0;
    virtual void signal() = 0;
    virtual bool getWaiting() const = 0;
};

#endif /* IThreadCond_h */
