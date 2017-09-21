//
//  agentlist.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 10/03/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "agentlist.h"

using namespace std;


/*--------------- INICIO ENTREGABLE 7 ---------------*/

AgentList::AgentList() {
    header = new AgentNode;

    if (header == nullptr) {
        throw ListException("memoria no disponible, inicializando lista");
    }

    header -> setPrev (header);
    header -> setNext(header);
}


bool AgentList::isEmpty() {
    return header -> getNext() == header;
}


std::string AgentList::toString() {
    string dataToPrint;

    AgentNode* aux(header -> getNext());

    while (aux != header) {
        dataToPrint += aux -> getData().toString() + "\n";
        aux = aux -> getNext();
    }

    return dataToPrint;
}


bool AgentList::isValidPos(AgentNode* p) {
    AgentNode* aux(header -> getNext());

    while (aux != header) {
        if (aux == p) {
            return true;
        }

        aux = aux -> getNext();
    }

    return false;
}


AgentNode* AgentList::insertData(AgentNode* p, const Agent &e) {
    if(p != nullptr and !isValidPos(p)) {
        throw ListException("posicion invalida al tratar de insertar");
    }

    AgentNode* aux;

    try{
        aux  = new AgentNode(e);
    } catch(NodeException ex) {
        string message = "error al tratar de crear un nuevo nodo, ";
        message += ex.what();
        throw ListException(&message);
    }

    if (aux == nullptr) {
        throw ListException("memoria no disponible, tratando de insertar");
    }
    if(p == nullptr) {
        p = header;
    }

    aux ->setPrev(p);
    aux ->setNext(p->getNext());

    p->getNext() -> setPrev(aux);
    p->setNext(aux);

    return aux;

}


/*---------------- FIN ENTREGABLE 7 -----------------*/



/*--------------- INICIO ENTREGABLE 8 ---------------*/


AgentNode* AgentList::getPrevPos(AgentNode* p) {
    if (!isValidPos(p) or p == header -> getNext()) {
        return nullptr;
    }

    return p -> getPrev();
}


AgentNode* AgentList::getNextPos(AgentNode* p) {
    if (!isValidPos(p) or p == header -> getPrev()) {
        return nullptr;
    }

    return p -> getNext();
}


void AgentList::deleteData(AgentNode* p) {
    if (!isValidPos(p)) {
        throw ListException ("Posición invalida, eliminando");
    }

    p -> getPrev() -> setNext(p -> getNext());
    p -> getNext() -> setPrev(p -> getPrev());

    delete p;
}


AgentNode* AgentList::findData(Agent& e) {
    AgentNode* aux = header -> getNext();

    while (aux != header) {
        if (aux -> getData() == e) {
            return aux;
        }
        aux = aux -> getNext();
    }

    return nullptr;
}


AgentNode* AgentList::findDataByName(Agent& e) {
    AgentNode* aux = header -> getNext();

    while (aux != header) {
        if (aux -> getData().getName().toString() == e.getName().toString()) {
            return aux;
        }
        aux = aux -> getNext();
    }

    return nullptr;
}

void AgentList::deleteAll() {
    AgentNode* aux;

    while (header -> getNext() != header) {
        aux = header -> getNext();
        header -> setNext(header -> getNext() -> getNext());
        delete aux;
    }
    header -> setPrev(header);
}

AgentList::~AgentList() {
    deleteAll();
    delete header;
}

/*---------------- FIN ENTREGABLE 8 -----------------*/

AgentNode* AgentList::getFirstPos() {
    if (header -> getNext() == header) {
        return nullptr;
    }
    return header -> getNext();
}


AgentNode* AgentList::getLastPos() {
    if (header -> getPrev() == header) {
        return nullptr;
    }
    return header -> getPrev();
}


Agent AgentList::retrieve(AgentNode *p) {
    if (!isValidPos(p)) {
        throw ListException ("Posicion invalida en retrieve");
    }

    return p -> getData();
}


void AgentList::copyAll(const AgentList &l) {
    AgentNode* aux = l.header->getNext();
    AgentNode* lastInserted = header;
    AgentNode* newNode;

    deleteAll();

    while (aux != l.header) {
        try {
            newNode = new AgentNode(aux -> getData());
        } catch (NodeException ex) {
            string message = "Problema al crear nodo nuevo, copiando lista\n";
            message += "El sistema informa: ";
            message += ex.what();

            throw ListException(&message);
        }

        if (newNode == nullptr) {
            throw ListException("Memoria no disponible, copiando lista");
        }

        aux -> setPrev(lastInserted);
        aux -> setNext(lastInserted -> getNext());

        lastInserted -> getNext() -> setPrev(aux);
        lastInserted -> setNext(newNode);

        lastInserted = newNode;
        aux = aux -> getNext();
    }
}


AgentList::AgentList(const AgentList &l) {
    copyAll(l);
}

AgentList& AgentList::operator = (const AgentList& l) {
    copyAll(l);
    
    return *this;
}


void AgentList::sortByName() {
    sortByName(getFirstPos(), getLastPos());
}

void AgentList::sortByDepartment() {
    sortByDeparment(getFirstPos(), getLastPos());
}

void AgentList::exchange(AgentNode* a, AgentNode* b) {
    Agent* aux(a -> getDataPtr());
    a -> setDataPtr(b -> getDataPtr());
    b -> setDataPtr(aux);
}

void AgentList::sortByName(AgentNode* left, AgentNode* right) {
    if (left == right) {
        return;
    }

    AgentNode *i(left), *j(right);

    while (i != j) {
        while (i != j and i -> getData().getName() <= right -> getData().getName()) {
            i = i -> getNext();
        }

        while (i != j and j -> getData().getName() >= right -> getData().getName()) {
            j = j -> getPrev();
        }

        if (i != j) {
            exchange(i,j);
        }
    }

    if (i != right) {
        exchange(i, right);
    }
    
    if (i != left) {
        sortByName(left, i -> getPrev());
    }
    if (i != right) {
        sortByName(i -> getNext(), right);
    }
}


void AgentList::sortByDeparment(AgentNode* left, AgentNode* right) {
    if (left == right) {
        return;
    }

    AgentNode *i(left), *j(right);

    while (i != j) {
        while (i != j and i -> getData().getDepartment() <= right -> getData().getDepartment()) {
            i = i -> getNext();
        }

        while (i != j and j -> getData().getDepartment() >= right -> getData().getDepartment()) {
            j = j -> getPrev();
        }

        if (i != j) {
            exchange(i,j);
        }
    }

    if (i != right) {
        exchange(i, right);
    }

    if (i != left) {
        sortByDeparment(left, i -> getPrev());
    }
    if (i != right) {
        sortByDeparment(i -> getNext(), right);
    }
}


std::string AgentList::writeToDisk(const string& fileName) {
    ofstream auxFile;
    string infoAgentsSaved;
    int numOfAgentsSaved = 0;


    auxFile.open(fileName, auxFile.trunc);

    if (!auxFile.is_open()) {
        string message = "Error al tratar de escribir en el archivo: ";
        message += fileName;
        throw ListException (&message);
    }

    AgentNode* aux(header -> getNext());

    try {
        while (aux != header) {
            auxFile << aux -> getData() << endl;
            aux -> getData().getClientList().writeToDisk(aux->getData().getID());
            infoAgentsSaved += "La información de ";
            infoAgentsSaved += aux -> getData().getName().toString() + " ha sido guardada... \n";
            aux = aux -> getNext();
            numOfAgentsSaved++;
        }
    } catch (ListException ex) {
        auxFile.close();
        string message = ex.what();
        throw ListException(&message);
    }


    auxFile.close();

    char textNumOfAgents[2];
    sprintf(textNumOfAgents, "%02d", numOfAgentsSaved);
    infoAgentsSaved += "\n";
    infoAgentsSaved += "Se guardo la información de un total de: ";
    infoAgentsSaved += textNumOfAgents;
    infoAgentsSaved += " agente/s";

    return infoAgentsSaved;
}




std::string AgentList::readFromDisk(const std::string& fileName) {
    ifstream auxFile;
    string infoAgentsLoaded;
    int numOfAgentsLoaded = 0;

    auxFile.open(fileName);
    if (!auxFile.is_open()) {
        string message = "Error al tratar de leer en el archivo: ";
        message += fileName;
        throw ListException(&message);
    }

    deleteAll();
    Agent auxAgent;
    AgentNode* aux;
    AgentNode* lastInserted(nullptr);

    try {
        while (auxFile >> auxAgent) {
            infoAgentsLoaded += "La información del agente ";
            infoAgentsLoaded += auxAgent.getName().toString() + " ha sido cargada... \n";

            try{

                aux  = new AgentNode(auxAgent);

            } catch(NodeException ex) {
                string message = "error al tratar de crear un nuevo nodo, ";
                message += ex.what();
                throw ListException(&message);
            }

            if (aux == nullptr) {
                throw ListException("memoria no disponible, tratando de insertar");
            }

            if(isEmpty()) {
                lastInserted = header;
            }


            aux -> setPrev(lastInserted);
            aux -> setNext(lastInserted -> getNext());

            lastInserted -> getNext() -> setPrev(aux);
            lastInserted -> setNext(aux);

            aux -> getData().getClientList().readFromDisk(auxAgent.getID());
            numOfAgentsLoaded++;

        }

    } catch(ListException ex) {
        auxFile.close();
        string message = "Error al tratar de leer en el archivo: ";
        message += fileName;
        throw ListException(&message);
    }

    auxFile.close();

    char textNumOfAgents[2];
    sprintf(textNumOfAgents, "%02d", numOfAgentsLoaded);

    infoAgentsLoaded += "\n";
    infoAgentsLoaded += "Se cargo la información de un total de: ";
    infoAgentsLoaded += textNumOfAgents;
    infoAgentsLoaded += " agente/s";

    return infoAgentsLoaded;
}








