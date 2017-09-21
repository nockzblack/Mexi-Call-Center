//
//  clientnode.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 16/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "clientnode.h"

using namespace  std;

// Constructos Implementation
ClientNode::ClientNode() : next(nullptr) {}

ClientNode::ClientNode(const Client& e, ClientNode* p) : data(e), next(p) {}


// Getters Implementation
Client& ClientNode::getData() {
    return data;
}
ClientNode* ClientNode::getNext() {
    return next;
}


// Setters Implementation
void ClientNode::setData(const Client& e) {
    data = e;
}
void ClientNode::setNext(ClientNode* p) {
    next = p;
}
