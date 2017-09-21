//
//  agentnode.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 09/03/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "agentnode.h"

using namespace std;

// Constructors Implementation
AgentNode::AgentNode() {
    prev = nullptr;
    next = nullptr;
    dataPtr = nullptr;
}

AgentNode::AgentNode(const Agent &e) : AgentNode() {
    dataPtr = new Agent(e);

    if (dataPtr == nullptr) {
        throw NodeException("memoria no disponible <StudentNode> <constructor copia>");
    }
}



// Getters Implementation
Agent* AgentNode::getDataPtr() {
    return dataPtr;
}


Agent& AgentNode::getData() {
    if(dataPtr==nullptr){
        throw NodeException("Insuficiencia de datos <StudentNode> <getData>");
    }
    return *dataPtr;
}


AgentNode* AgentNode::getPrev() {
    return prev;
}


AgentNode* AgentNode::getNext() {
    return next;
}


// Setters Implementation
void AgentNode::setDataPtr(Agent* p) {
    dataPtr = p;
}


void AgentNode::setData(const Agent& e) {
    if (dataPtr == nullptr) {
        dataPtr = new Agent(e);
        if (dataPtr == nullptr) {
            throw NodeException("memoria no disponible <StudentNode> <setData>");
        }
    } else {
        *dataPtr = e;
    }
}


void AgentNode::setPrev(AgentNode *p) {
    prev = p;
}


void AgentNode::setNext(AgentNode *p) {
    next = p;
}



// Destructor Implementation
AgentNode::~AgentNode() {
    delete dataPtr;
}


