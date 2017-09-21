//
//  name.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 15/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "name.h"

using namespace std;

Name::Name() {}

Name::Name(const Name& n) : last(n.last), first(n.first) {}

Name::Name(const string& newfirst, const string& newlast) : last(newlast), first(newfirst) {}

string Name::getLast() {
    return last;
}

string Name::getFirst() {
    return first;
}

void Name::setLast(const string& newLast) {
    last = newLast;
}

void Name::setFirst(const string & newFirst) {
    first = newFirst;
}

string Name::toString() {
    return last + " " + first;
}

Name& Name::operator = (const Name& n) {
    first = n.first;
    last = n.last;

    return *this;
}

bool Name::operator == (Name& n) {
    return toString() == n.toString();
}
bool Name::operator != (Name& n) {
    return toString() != n.toString();
}
bool Name::operator < (Name& n) {
    return toString() < n.toString();
}
bool Name::operator > (Name& n) {
    return toString() > n.toString();
}
bool Name::operator <= (Name& n) {
    return toString() <= n.toString();
}
bool Name::operator >= (Name& n) {
    return toString() >= n.toString();
}

ostream& operator << (ostream& os, Name& n) {
    os << n.toString();
    return os;
}


istream& operator >> (istream& is, Name& n) {
    getline(is, n.last, ' ');
    getline(is, n.first);
    return is;
}
