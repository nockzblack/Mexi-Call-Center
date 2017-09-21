//
//  name.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 08/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef name_h
#define name_h

#include <string>
#include <iostream>


class Name{
private:
    // Class's Attributes
    std::string last;
    std::string first;

public:
    // Constructors
    Name(); // Default
    Name(const Name&); // Copy
    Name(const std::string&, const std::string&); // Parameterized

    // Getters
    std::string getLast();
    std::string getFirst();

    // Setters
    void setLast(const std::string&);
    void setFirst(const std::string&);

    // Func to transform data into a string
    std::string toString();

    // Operators Overload
    Name& operator = (const Name&);
    bool operator == (Name&);
    bool operator != (Name&);
    bool operator < (Name&);
    bool operator <= (Name&);
    bool operator >= (Name&);
    bool operator > (Name&);

    friend std::ostream& operator << (std:: ostream&, Name&);
    friend std::istream& operator >> (std:: istream&, Name&);
};

#endif /* name_h */
