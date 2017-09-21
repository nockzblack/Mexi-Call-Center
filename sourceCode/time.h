//
//  time.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 08/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef time_h
#define time_h

#include <string>
#include <iostream>
#include <ctime>


class Time {
private:
    // Class's Attributes
    int hour;
    int minute;
    int second;

    // Func to valid the time
    bool IsValid(const int&, const int&, const int&);

public:
    // Constructors
    Time(); // Default
    Time(const Time&); // Copy
    Time(const int&, const int&, const int&); // Parameterized


    // Getters
    int getHour();
    int getMinute();
    int getSecond();

    // Setters
    void setHour(const int&);
    void setMinute(const int&);
    void setSecond(const int&);

    // Func to transform data into a string
    std::string toString();
    std::string toStringWithoutSeconds();

    int timeInSeconds();

    // Operators Overload
    Time& operator = (const Time&);
    bool operator == (Time&);
    bool operator != (Time&);
    bool operator < (Time&);
    bool operator <= (Time&);
    bool operator >= (Time&);
    bool operator > (Time&);

    friend std::ostream& operator << (std:: ostream&, Time&);
    friend std::istream& operator >> (std:: istream&, Time&);
    
};

#endif /* time_h */
