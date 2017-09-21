//
//  agent.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 09/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef agent_h
#define agent_h

#include <string.h>

#include "name.h"
#include "time.h"
#include "clientlist.h"


class  Agent {
private:
    // Class's Attributes
    std::string ID;
    int numOfExt;
    int extraHours;
    Name name;
    std::string department;
    Time startingTime;
    Time endingTime;
    ClientList attendedClients;

public:
    // Constructors
    Agent(); // Default
    Agent(const Agent&); // Copy

    // Getters
    std::string getID();
    int getNumOfExt();
    int getExtraHours();
    Name& getName();
    std::string getDepartment();
    Time& getStartingTime();
    Time& getEndingTime();
    ClientList& getClientList();

    // Setters
    void setID(const std::string&);
    void setNumOfExt(const int&);
    void setExtraHours(const int&);
    void setName(const Name&);
    void setDepartment(const std::string&);
    void setStartingTime(const Time&);
    void setEndingTime(const Time&);
    void setClientList(const ClientList&);

    // Func to transform the data to a String
    std::string toString();

    // Operators Overload
    Agent& operator = (const Agent&);
    bool operator == (Agent&);
    bool operator != (Agent&);
    bool operator < (Agent&);
    bool operator <= (Agent&);
    bool operator >= (Agent&);
    bool operator > (Agent&);

    friend std::ostream& operator << (std::ostream&, Agent&);
    friend std::istream& operator >> (std::istream&, Agent&);
};


#endif /* agent_h */
