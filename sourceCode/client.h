//
//  client.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 08/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef client_h
#define client_h

#include <string>
#include <iostream>

#include "time.h"
#include "name.h"

class Client {
private:
    // Class's Attributes
    std::string id;
    Name name;
    Time callDuration;
    Time callTime;

public:
    // Constructors
    Client(); // Default
    Client(const Client&); // Copy

    // Getters
    std::string getID();
    Name& getName();
    Time& getCallDuration();
    Time& getCallTime();

    // Setters
    void setID(const std::string);
    void setName(const Name&);
    void setCallDuration(const Time&);
    void setCallTime(const Time&);

    // Func to transform the data to a String
    std::string toString();

    // Operators Overload
    Client& operator = (const Client&);
    bool operator == (Client&);
    bool operator != (Client&);
    bool operator < (Client&);
    bool operator > (Client&);
    bool operator <= (Client&);
    bool operator >= (Client&);

    friend std::ostream& operator << (std::ostream&, Client&);
    friend std::istream& operator >> (std::istream&, Client&);

};

#endif /* client_h */
