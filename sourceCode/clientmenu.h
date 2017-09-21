//
//  clientmenu.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 09/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef clientmenu_h
#define clientmenu_h

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

#include "clientlist.h"


class ClientMenu {
private:
    // Atrribute
    ClientList* ClientListRef;

    // Methods
    void mainMenu();
    void addClient();
    void showClientsList();
    void deleteClient();
    void modifyClient();
    void deleteAll();
    void exit();
    void enterToContinue();

public:
    // Constructor
    ClientMenu(ClientList*);

};


#endif /* clientmenu_h */
