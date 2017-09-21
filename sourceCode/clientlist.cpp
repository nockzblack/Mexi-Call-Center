//
//  clientlist.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 16/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "clientlist.h"

using namespace std;

/*---------------INICIO ENTREGABLE 4---------------*/

ClientList::ClientList() : anchor(nullptr) {}


bool ClientList::isEmpty() {
    return anchor == nullptr;
}


std::string ClientList::toString() {
    string dataToPrint;
    ClientNode* aux = anchor;

    while (aux != nullptr) {
        dataToPrint += aux ->getData().toString() + '\n';
        aux = aux -> getNext();
    }
    return dataToPrint;
}


bool ClientList::isValidPos(ClientNode * p){
    ClientNode* aux = anchor;

    while (aux != nullptr) {
        if (aux == p) {
            return true;
        }
        aux = aux -> getNext();
    }
    return false;
}


void ClientList::insertData(ClientNode* p, const Client& e) {
    if (p != nullptr and !isValidPos(p)) {
        // Launch Exception
        throw ListException ("Error al insertar, posicion invalida");
    }

    ClientNode* aux = new ClientNode(e);

    if (aux == nullptr) {
        // Launch Exception
        throw ListException("Memoria no disponible");
    }

    if (p == nullptr) {
        aux -> setNext(anchor);
        anchor = aux;
    } else {
        aux -> setNext(p -> getNext());
        p->setNext(aux);
    }
}


void ClientList::insertSorted(Client& e) {
    ClientNode* prev = nullptr;
    ClientNode* aux = anchor;

    while (aux != nullptr and e.getCallTime().timeInSeconds() >= aux->getData().getCallTime().timeInSeconds()) {
        prev = aux;
        aux = aux ->getNext();
    }

    insertData(prev, e);
}


/*---------------FIN ENTREGABLE 4---------------*/


/*--------------INICIO ENTREGABLE 5--------------*/

ClientList::~ClientList() {
    deleteAll();
}


ClientNode* ClientList::getPrevPos(ClientNode* p) {
    ClientNode* aux(anchor);
    while (aux != nullptr and aux -> getNext() != p) {
        aux = aux ->getNext();
    }
    return aux;
}


void ClientList::deleteAll() {
    ClientNode* aux;
    while (anchor != nullptr) {
        aux = anchor;
        anchor = anchor ->getNext();
        delete aux;
    }
}


ClientNode* ClientList::findData(Client& e) {
    ClientNode* aux(anchor);
    while (aux != nullptr and aux ->getData() != e) {
        aux = aux ->getNext();
    }
    return aux;
}


void ClientList::deleteData(ClientNode* p) {
    if (!isValidPos(p)) {
        throw ListException("Posición invalida, tratando de eliminar");
    }

    if (p == anchor) {
        anchor = anchor -> getNext();
    } else {
        getPrevPos(p) -> setNext(p ->getNext());
    }

    delete p;
}


/*--------------FIN ENTREGABLE 5--------------*/


ClientNode* ClientList::getFirstPos() {
    return anchor;
}


ClientNode* ClientList::getLastPos() {
    if(isEmpty()) {
        return  nullptr;
    }
    ClientNode* aux(anchor);
    while (aux ->getNext() != nullptr) {
        aux = aux ->getNext();
    }
    return aux;
}


ClientNode* ClientList::getNextPos(ClientNode* p) {
    if(!isValidPos(p)) {
        return nullptr;
    }
    return p ->getNext();
}


Client& ClientList::retrieve(ClientNode* p) {
    if (!isValidPos(p)) {
        throw ListException ("Posicion Invalida... tratando de recuperar");
    }

    return p->getData();
}


void ClientList::copyAll(const ClientList& l) {
    ClientNode* aux(l.anchor);
    ClientNode* lastInserted(nullptr);
    ClientNode* newNode;

    while (aux != nullptr) {
        newNode = new ClientNode(aux -> getData());
        if (lastInserted == nullptr) {
            anchor = newNode;
        } else {
            lastInserted -> setNext(newNode);
        }
        lastInserted = newNode;
        aux = aux -> getNext();
    }
}


ClientList::ClientList(const ClientList& l) : ClientList() {
    copyAll(l);
}



ClientList& ClientList::operator = (const ClientList & l) {
    deleteAll();
    copyAll(l);
    return *this;
}



void ClientList::writeToDisk(const string& fileName) {
    ofstream auxFile;

    auxFile.open(fileName, auxFile.trunc);

    if (!auxFile.is_open()) {
        string message = "Error al tratar de escribir en el archivo: ";
        message += fileName;
        throw ListException (&message);
    }

    ClientNode* aux(anchor);

    while (aux != nullptr) {
        auxFile << aux -> getData() << endl;
        aux = aux -> getNext();
    }

    auxFile.close();
}





void ClientList::readFromDisk(const string& fileName) {
    ifstream auxFile;

    auxFile.open(fileName);
    if (!auxFile.is_open()) {
        string message = "Error al tratar de leer en el archivo: ";
        message += fileName;
        throw ListException(&message);
    }

    deleteAll();
    Client auxClient;
    ClientNode* lastInserted(nullptr);

    try {
        while (auxFile >> auxClient) {
            ClientNode* aux = new ClientNode(auxClient);

            if (aux == nullptr) {
                // Launch Exception
                throw ListException("Memoria no disponible");
            }

            if (isEmpty()) {
                aux -> setNext(anchor);
                anchor = aux;
                lastInserted = anchor;

            } else {
                aux -> setNext(lastInserted -> getNext());
                lastInserted -> setNext(aux);
                lastInserted = aux;
            }
        }

    } catch(ListException ex) {
        auxFile.close();
        string message = "Error Error al tratar de leer en el archivo: ";
        message += fileName;
        throw ListException(&message);
    }

    auxFile.close();
}






