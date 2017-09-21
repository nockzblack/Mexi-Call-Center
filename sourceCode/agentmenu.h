//
//  agentmenu.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 09/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef agentmenu_h
#define agentmenu_h

#include <cstdlib>
#include <iostream>
#include <string>

#include "agentlist.h"
#include "clientmenu.h"

class AgentMenu {
private:
    // Atrribute
    AgentList* AgentListRef;

    // Interface Methods
    void mainMenu();
    void addAgent();
    void showAgent();
    void showAgentList();
    void deleteAgent();
    void modifyAgent();
    void deleteAll();
    void saveInfo();
    void readInfo();
    void exit();
    void enterToContinue();

public:
    // Constructor
    AgentMenu(AgentList*);

};


#endif /* agentmenu_h */
