//  client.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 15/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "client.h"

using namespace std;

// Constructors Implementation
Client::Client() {}

Client::Client(const Client& s)  : id(s.id), name(s.name), callDuration(s.callDuration),
callTime(s.callTime){}


// Getters Implementation
std::string Client::getID() {
    return id;
}

Name& Client::getName() {
    return name;
}

Time& Client::getCallTime() {
    return callTime;
}
Time& Client::getCallDuration() {
    return callDuration;
}


// Setters Implementation
void Client::setID(const std::string newID) {
    id = newID;
}

void Client::setName(const Name &newName) {
    name = newName;
}

void Client::setCallDuration(const Time &newCallDuration) {
    callDuration = newCallDuration;
}

void Client::setCallTime(const Time &newCallTime) {
    callTime = newCallTime;
}


// Func to make a string of whatever object type Client
std::string Client::toString() {
    string infoClient;
    unsigned long int auxInt;

    infoClient = " ";
    infoClient += id;
    for (auxInt = id.length(); auxInt < 4; auxInt++) {
        infoClient += " ";
    }

    infoClient += " | ";
    infoClient += name.toString();
    for (auxInt = name.toString().length(); auxInt < 21; auxInt++) {
        infoClient += " ";
    }

    infoClient += " | ";
    infoClient += callTime.toStringWithoutSeconds();


    infoClient += " | ";
    infoClient += callDuration.toString();

    return infoClient;
}


// Operators Overload Implementation
Client& Client::operator = (const Client& s) {
    id = s.id;
    name = s.name;
    callDuration = s.callDuration;
    callTime = s.callTime;

    return *this;
}

bool Client::operator == (Client& s) {
    return id == s.id;
}
bool Client::operator != (Client& s) {
    return id != s.id;
}
bool Client::operator < (Client& s) {
    return id < s.id;
}
bool Client::operator > (Client& s) {
    return id > s.id;
}
bool Client::operator <= (Client& s) {
    return  id <= s.id;
}
bool Client::operator >= (Client& s) {
    return id >= s.id;
}


ostream& operator << (ostream& os, Client& c) {
    os << c.id << endl;
    os << c.name << endl;
    os << c.callDuration << endl;
    os << c.callTime;

    return os;
    
}


istream& operator >> (istream& is, Client& c) {
    getline(is, c.id);
    is >> c.name;
    is >> c.callDuration;
    is >> c.callTime;
    return is;
}

