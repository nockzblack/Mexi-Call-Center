//
//  clientlist.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 09/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef clientlist_h
#define clientlist_h

#include <string>
#include <iostream>
#include <fstream>

#include "client.h"
#include "clientnode.h"
#include "listexception.h"

class ClientList {
private:
    // Attrinute
    ClientNode* anchor;

    bool isValidPos(ClientNode*);

public:
    // Cosntructors
    ClientList();
    ClientList(const ClientList&);

    // Destructor
    ~ClientList();

    // List Operations
    bool isEmpty();
    void insertData(ClientNode*,const  Client&);
    void insertSorted(Client&);
    void deleteData(ClientNode*);

    ClientNode* getFirstPos();
    ClientNode* getLastPos();
    ClientNode* getPrevPos(ClientNode*);
    ClientNode* getNextPos(ClientNode*);

    ClientNode* findData(Client&);
    Client& retrieve(ClientNode*);

    void copyAll(const ClientList&);
    void deleteAll();

    // Func to transform the data to a String
    // And print the List
    std::string toString();

    // Operator Overload
    ClientList& operator = (const ClientList&);

    void writeToDisk(const std::string&);
    void readFromDisk(const std::string&);


};


#endif /* clientlist_h */
