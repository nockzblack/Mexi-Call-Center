//
//  agentlist.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 09/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef agentlist_h
#define agentlist_h

#include <string>
#include <fstream>

#include "agent.h"
#include "agentnode.h"

class AgentList {
private:
    // Attrinute
    AgentNode* header;
    

    bool isValidPos(AgentNode*);
    void sortByName(AgentNode*, AgentNode*);
    void sortByDeparment(AgentNode*, AgentNode*);
    void exchange(AgentNode*, AgentNode*);

public:
    // Cosntructors
    AgentList();
    AgentList(const AgentList&);

    // Destructor
    ~AgentList();

    // List Operations
    bool isEmpty();

    AgentNode* insertData(AgentNode*, const Agent&);
    AgentNode* getFirstPos();
    AgentNode* getLastPos();
    AgentNode* getPrevPos(AgentNode*);
    AgentNode* getNextPos(AgentNode*);

    AgentNode* findData(Agent&);
    AgentNode* findDataByName(Agent&);
    Agent retrieve(AgentNode*);

    void deleteData(AgentNode*);
    void deleteAll();
    void copyAll(const AgentList&);
    void sortByDepartment();
    void sortByName();


    // Func to transform the data to a String
    std::string toString();

    // Operator Overload
    AgentList& operator = (const AgentList&);

    // Funcs to Write and Read from/to Disk
    std::string writeToDisk(const std::string&);
    std::string readFromDisk(const std::string&);

};

#endif /* agentlist_h */
