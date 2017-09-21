//
//  clientnode.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 09/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef clientnode_h
#define clientnode_h

#include "client.h"

class ClientNode {
private:
    // Class's Attributes
    Client data;
    ClientNode* next;

public:
    // Constructors
    ClientNode(); // Default
    ClientNode(const Client&, ClientNode* = nullptr); // Parameterized

    // Getters
    Client& getData();
    ClientNode* getNext();

    // Setters
    void setData(const Client&);
    void setNext(ClientNode*);
};

#endif /* clientnode_h */
