//
//  clientmenu.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 23/02/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "clientmenu.h"

using namespace std;


// Constructor of Menu Object and calls func mainMenu at the same time
ClientMenu::ClientMenu(ClientList* p) : ClientListRef(p) {
    mainMenu();
}

// This menu interacs with the user and calls the others submenus!
void ClientMenu::mainMenu() {
    char selec;
    do {
        system("clear");
        cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;

        cout << "*** MENU DE CLIENTES ***" << endl;
        cout << "1.Nuevo Cliente" << endl;
        cout << "2.Eliminar Cliente" << endl;
        cout << "3.Modificar Duracion de Llamada" << endl;
        cout << "4.Mostrar Clientes" << endl;
        cout << "5.Borrar todos los Clientes" << endl;
        cout << "6.Regresar" << endl << endl;

        cout << "Elige una opción (1,2,3,4,5,6): ";
        cin >> selec;
        cin.ignore();

        switch (selec) {
            case '1':
                addClient();
                break;

            case '2':
                deleteClient();
                break;

            case '3':
                modifyClient();
                break;

            case '4':
                showClientsList();
                break;

            case '5':
                deleteAll();
                break;

            case '6':
                exit();
                break;

            default:
                cout << "Opción Invalida" << endl;
                enterToContinue();
                break;
        }
    } while (selec != '6');
}


// This func has the objective to save code
// every time is called
void  ClientMenu::enterToContinue() {
    cout << "Presione <enter> para continuar....";
    cin.get();
}


// Func to add a Client to the Clientlist
void ClientMenu::addClient() {
    string auxStr;
    Client auxClient;
    ClientNode* pos;
    Name auxName;
    Time auxTime;
    char auxChar;

    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "AGREGANDO NUEVO CLIENTE" << endl << endl;
    cout << "Id: ";
    getline(cin, auxStr);
    auxClient.setID(auxStr);

    // Valid if the id seted for the user is unique
    // is isn't value, do not let insert
    pos = ClientListRef -> findData(auxClient);
    if (pos != nullptr) {
        cout << "Ese Cliente ya existe dentro de la lista" << endl;
        cout << "por favor intenta de nuevo con otro id" << endl << endl;
        enterToContinue();
        return;
    }

    cout << "Apellidos: ";
    getline(cin, auxStr);
    auxName.setLast(auxStr);

    cout << "Nombre/s: ";
    getline(cin, auxStr);
    auxName.setFirst(auxStr);
    auxClient.setName(auxName);


    cout << "Hora de la Llamada (HH:MM): ";
    getline(cin, auxStr, ':');
    auxTime.setHour(atoi(auxStr.c_str()));
    getline(cin, auxStr);
    auxTime.setMinute(atoi(auxStr.c_str()));
    auxTime.setSecond(0);
    auxClient.setCallTime(auxTime);


    cout << "La llamada duró más de una hora?" << endl;
    do {
        cout << "[s/n]: ";
        cin >> auxChar;
        auxChar = toupper(auxChar);
        if (auxChar != 'S' and auxChar != 'N') {
            cout << "opción invalida, por favor ingrese [s/n], para continuar" << endl;
        }
    } while (auxChar != 'S' and auxChar != 'N');

    if (auxChar == 'S') {
        cout << "Tiempo de Duración de Llamada (HH:MM:SS): ";
        getline(cin, auxStr, ':');
        auxTime.setHour(atoi(auxStr.c_str()));
        getline(cin, auxStr,':');
        auxTime.setMinute(atoi(auxStr.c_str()));
        getline(cin, auxStr);
        auxTime.setSecond(atoi(auxStr.c_str()));
    } else {
        cout << "Tiempo de Duración de Llamada (MM:SS): ";
        getline(cin, auxStr, ':');
        auxTime.setMinute(atoi(auxStr.c_str()));
        getline(cin, auxStr);
        auxTime.setSecond(atoi(auxStr.c_str()));
        auxTime.setHour(0);
    }

    auxClient.setCallDuration(auxTime);

    cout << endl;

    // Manage with possibles failures that system could throw
    try {
        ClientListRef -> insertSorted(auxClient);
    } catch (ListException ex) {
        cout << "Hubo un error" << endl;
        cout << "El cliente no se epudo insertar" << endl;
        cout << "El sisema infora el siguiente error " << ex.what();
        cout << "Si este problema persiste, por favor informelo a soporte" << endl;
        enterToContinue();
        return;
    }

    cout << "Cliente insertado exitosamente" << endl << endl;
    enterToContinue();
}


// Func to delete an especific client
void ClientMenu::deleteClient() {
    Client auxClient;
    ClientNode* pos;
    string auxStr;

    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "ELIMINADO CLIENTE" << endl << endl;
    cout << "Dame el numero de ID del cliente" << endl;
    getline(cin,auxStr);
    auxClient.setID(auxStr);

    // Valid if the client finded for the client exist
    pos = ClientListRef -> findData(auxClient);
    if (pos == nullptr) {
        cout << "No existe un Cliente dentro de la lista con ese id" << endl;
        cout << "por favor intenta de nuevo con otro id" << endl << endl;
        enterToContinue();
        return;
    } else {
        ClientListRef -> deleteData(pos);
        cout << "Cliente eliminado extosamente... " << endl << endl;
        enterToContinue();
    }
}


// Func to modify the duration of the attribute callDuration
void ClientMenu::modifyClient() {
    Client auxClient;
    ClientNode* pos;
    Time auxTime;
    string auxStr;

    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "Dame el numero de ID del cliente" << endl;
    getline(cin,auxStr);
    auxClient.setID(auxStr);
    pos = ClientListRef -> findData(auxClient);

    if (pos == nullptr) {
        cout << "No existe un Cliente dentro de la lista con ese id" << endl;
        cout << "por favor intenta de nuevo con otro id" << endl << endl;
        enterToContinue();
        return;
    } else {
        cout << "                              | HH:MM | HH:MM:SS |" << endl;
        cout << " ID   | Nombre                | Hora  | Duracion |" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << ClientListRef -> retrieve(pos).toString() << endl << endl;
        auxClient = ClientListRef -> retrieve(pos);
        ClientListRef -> deleteData(pos);
    }


    cout << "MODIFICANDO CLIENTE" << endl << endl;

    cout << "Tiempo de Duracion de Llamada (HH:MM:SS): ";
    getline(cin, auxStr, ':');
    auxTime.setHour(atoi(auxStr.c_str()));
    getline(cin, auxStr,':');
    auxTime.setMinute(atoi(auxStr.c_str()));
    getline(cin, auxStr);
    auxTime.setSecond(atoi(auxStr.c_str()));
    auxClient.setCallDuration(auxTime);
    cout << endl;

    // Manage with possibles failures that system could throw
    try {
        ClientListRef -> insertSorted(auxClient);
    } catch (ListException ex) {
        cout << "Hubo un error" << endl;
        cout << "El cliente no se epudo insertar" << endl;
        cout << "El sisema infora el siguiente error " << ex.what();
        cout << "Si este problema persiste, por favor informelo a soporte" << endl;
        enterToContinue();
    }

    cout << "Cliente modificado exitosamente" << endl << endl;
    enterToContinue();

}


// Just shows the list of the clients, always sorted by tiime of call
void ClientMenu::showClientsList() {
    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "LISTADO DE CLIENTES" << endl << endl;

    if (ClientListRef -> isEmpty()) {
        cout << "La lista esta vacia" << endl;
        cout << "inserte algún Cliente" << endl << endl;
        enterToContinue();
    } else {
        cout << "La lista está ordenada por hora de atencion!" << endl << endl;
        cout << "                              | HH:MM | HH:MM:SS |" << endl;
        cout << " ID   | Nombre                | Hora  | Duracion |" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << ClientListRef -> toString() << endl << endl;
        enterToContinue();
    }
}


// Simple ending screen of bye
void ClientMenu::exit() {
    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "Saliendo del menu de Clientes" << endl;
    cout << "Regresare al menu anterior" << endl;
    enterToContinue();
    system("clear");
}

// Func to delete all the clients
void ClientMenu::deleteAll() {
    char answer;
    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "ELIMINADO LISTA DE CLIENTES" << endl << endl;
    cout << "Esta seguro de BORRAR toda la LISTA de Clientes:?" << endl;
    cout << "Presione (S/s) para BORRAR, cualquier otro devuelve al menu anterior" << endl;
    cin >> answer;
    cin.ignore();
    if (answer == 's' or answer == 'S') {
        ClientListRef -> ~ClientList();
        cout << "Lista Borrada exitosamente" << endl;
        enterToContinue();
    } else {
        return;
    }
}


