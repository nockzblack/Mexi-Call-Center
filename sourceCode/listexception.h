//
//  listexception.h
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 16/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#ifndef listexception_h
#define listexception_h

#include <exception>
#include <string>

class ListException : public std:: exception {
private:
    std::string msg;

public:
    explicit ListException (const char* message) : msg(message) {}
    explicit ListException (const std::string* message) : msg(*message) {}
    virtual ~ListException () throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

#endif /* listexception_h */
