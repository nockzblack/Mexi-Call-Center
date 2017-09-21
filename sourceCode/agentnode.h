//
//  agentnode.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 09/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef agentnode_h
#define agentnode_h

#include "agent.h"

#include <exception>
#include <string>


class NodeException : public std::exception {
private:
    std::string msg;

public:
    explicit NodeException (const char* message) : msg(message) { }

    explicit NodeException (const std::string& message) : msg(message) { }

    virtual ~NodeException() throw () { }

    virtual const char* what() const throw () {
        return msg.c_str();
    }
};


class AgentNode {
private:
    // Class's Attributes
    Agent* dataPtr;
    AgentNode* next;
    AgentNode* prev;


public:
    // Constructors
    AgentNode(); // Default
    AgentNode(const Agent& /*, AgentNode*, AgentNode* */); // Parameterized

    // Destructor
    ~AgentNode();

    // Getters
    Agent* getDataPtr();
    Agent& getData();
    AgentNode* getNext();
    AgentNode* getPrev();

    // Setters
    void setDataPtr(Agent*);
    void setData(const Agent&);
    void setNext(AgentNode*);
    void setPrev(AgentNode*);
};


#endif /* agentnode_h */
