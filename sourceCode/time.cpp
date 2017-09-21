//
//  time.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 15/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "time.h"

using namespace std;


// Func to valid the value of the variables
bool Time::IsValid(const int &h, const int &m, const int &s) {
    return h >= 0 and h <= 23 and m >= 0 and m <= 59 and s >= 0 and s <= 59;
}


// Default Constructor that initialize whit system's time
Time::Time() {
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal= *localtime(&now);
    hour = nowLocal.tm_hour;
    minute = nowLocal.tm_min;
    second = nowLocal.tm_sec;
}

// Constructor Copy Implementation
Time::Time(const Time& t) : hour(t.hour), minute(t.minute), second(t.second){}

// Constructor Parameterized Implementation
// with a validation of the valus received

Time::Time(const int &h, const int &m, const int &s) : Time() {
    if (IsValid(h,m,s)) {
        hour = h;
        minute = m;
        second = s;
    }
}


// Getters Implementation
int Time::getHour() {
    return hour;
}
int Time::getMinute() {
    return minute;
}

int Time::getSecond() {
    return second;
}


// Setters Implementation
void Time::setHour(const int &h) {
    if (IsValid(h, minute, second)) {
        hour = h;
    }
}
void Time::setMinute(const int &m) {
    if (IsValid(hour, m, second)) {
        minute = m;
    }
}

void Time::setSecond(const int &s) {
    if (IsValid(hour, minute, s)) {
        second = s;
    }
}


// Func to make the type of data into a stirng
std::string Time::toString() {
    char textTime[6];

    sprintf(textTime, "%02d:%02d:%02d", hour, minute, second);

    return textTime;
}


std::string Time::toStringWithoutSeconds() {
    char textTime[6];

    sprintf(textTime, "%02d:%02d", hour, minute);

    return textTime;
}

int Time::timeInSeconds() {
    int totalSeconds = 0;

    totalSeconds = (hour * 60) + minute;
    totalSeconds = (totalSeconds * 60) + second;

    return totalSeconds;
}

// Operator orverload = implementation
Time& Time::operator = (const Time& t) {
    hour = t.hour;
    minute = t.minute;
    second = t.second;
    return *this;
}


bool Time::operator == (Time& t) {
    return hour == t.hour and minute == t.minute and second == t.second;
}
bool Time::operator != (Time& t) {
    return hour != t.hour and minute != t.minute and second != t.second;
}
bool Time::operator < (Time& t) {
    return hour < t.hour and minute < t.minute and second < t.second;
}
bool Time::operator > (Time& t) {
    return hour > t.hour and minute > t.minute and second > t.second;
}
bool Time::operator <= (Time& t) {
    return hour <= t.hour and minute <= t.minute and second <= t.second;
}
bool Time::operator >= (Time& t) {
    return hour >= t.hour and minute >= t.minute and second >= t.second;
}


ostream& operator << (ostream& os, Time& t) {
    os << t.toString();
    return os;
}


istream& operator >> (istream& is, Time& t) {
    string auxStr;
    getline(is, auxStr, ':');
    t.hour = atoi(auxStr.c_str());
    getline(is, auxStr, ':');
    t.minute = atoi(auxStr.c_str());
    getline(is, auxStr);
    t.second = atoi(auxStr.c_str());
    return is;
}
