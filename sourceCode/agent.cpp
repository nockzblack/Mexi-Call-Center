//  agent.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 03/03/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "agent.h"

using namespace std;

Agent::Agent() {}

Agent::Agent(const Agent &a) : ID(a.ID), numOfExt(a.numOfExt), extraHours(a.extraHours), name(a.name), department(a.department), startingTime(a.startingTime), endingTime(a.endingTime), attendedClients(a.attendedClients){}


// Getter's Implementation
std::string Agent::getID() {
    return ID;
}

int Agent::getNumOfExt() {
    return numOfExt;
}

int Agent::getExtraHours() {
    return extraHours;
}

Name& Agent::getName() {
    return name;
}

string Agent::getDepartment() {
    return department;
}

Time& Agent::getStartingTime() {
    return startingTime;
}

Time& Agent::getEndingTime() {
    return endingTime;
}

ClientList& Agent::getClientList() {
    return attendedClients;
}

// Setter's Implementation
void Agent::setID(const std::string &newID) {
    ID = newID;
}

void Agent::setNumOfExt(const int &newNumOfExt) {
    numOfExt = newNumOfExt;
}

void Agent::setExtraHours(const int &newExtraHours) {
    extraHours = newExtraHours;
}

void Agent::setName(const Name &newName) {
    name = newName;
}

void Agent::setDepartment(const std::string &newDepartament) {
    department = newDepartament;
}

void Agent::setStartingTime(const Time &newStartingTime) {
    startingTime = newStartingTime;
}

void Agent::setEndingTime(const Time &newEndingTime) {
    endingTime = newEndingTime;
}

void Agent::setClientList(const ClientList &newClientList) {
    attendedClients = newClientList;
}


std::string Agent::toString() {
    unsigned long int auxInt;
    string infoAgent;
    char auxNumOfExt[4];
    char auxExtraHours[4];

    sprintf(auxNumOfExt, "%02d", numOfExt);
    sprintf(auxExtraHours, "%02d", extraHours);


    infoAgent = " ";
    infoAgent += ID;
    for (auxInt = ID.length(); auxInt < 4; auxInt++) {
        infoAgent += " ";
    }

    infoAgent += " | ";
    infoAgent += name.toString();
    for (auxInt = name.toString().length(); auxInt < 25; auxInt++) {
        infoAgent += " ";
    }

    infoAgent += " | ";
    infoAgent += department;
    for (auxInt = department.length(); auxInt < 13; auxInt++) {
        infoAgent += " ";
    }

    infoAgent += " | ";
    infoAgent += startingTime.toStringWithoutSeconds();

    infoAgent += " | ";
    infoAgent += endingTime.toStringWithoutSeconds();

    infoAgent += " | ";
    infoAgent += auxNumOfExt;
    for (auxInt = strlen(auxNumOfExt); auxInt < 4; auxInt++) {
        infoAgent += " ";
    }

    infoAgent += " | ";
    infoAgent += auxExtraHours;

    return infoAgent;

}


// Operators Overload Implementation
Agent& Agent::operator = (const Agent& a) {
    ID = a.ID;
    numOfExt = a.numOfExt;
    extraHours = a.extraHours;
    name = a.name;
    department = a.department;
    startingTime = a.startingTime;
    endingTime = a.endingTime;
    attendedClients = a.attendedClients;

    return *this;
}

bool Agent::operator == (Agent& s) {
    return ID == s.ID;
}
bool Agent::operator != (Agent& s) {
    return ID != s.ID;
}
bool Agent::operator < (Agent& s) {
    return ID < s.ID;
}
bool Agent::operator > (Agent& s) {
    return  ID > s.ID;;
}
bool Agent::operator <= (Agent& s) {
    return ID <= s.ID;;
}
bool Agent::operator >= (Agent& s) {
    return  ID >= s.ID;
}


ostream& operator << (ostream& os, Agent& a) {
    os << a.ID << endl;
    os << a.numOfExt << endl;
    os << a.extraHours << endl;
    os << a.name << endl;
    os << a.department << endl;
    os << a.startingTime << endl;
    os << a.endingTime;

    return os;
}


istream& operator >> (istream& is, Agent& a) {
    string auxStr;

    getline(is, a.ID);
    getline(is, auxStr);
    a.numOfExt = atoi(auxStr.c_str());
    getline(is, auxStr);
    a.extraHours = atoi(auxStr.c_str());
    is >> a.name;
    getline(is, a.department);
    is >> a.startingTime;
    is >> a.endingTime;
    return is;
}

