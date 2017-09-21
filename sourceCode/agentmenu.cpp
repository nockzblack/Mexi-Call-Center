//
//  agentmenu.cpp
//  MexiCallCenter
//
//  Created by Fernando Benavides Rodriguez on 16/03/17.
//  Copyright © 2017 Fernando Benavides Rodriguez. All rights reserved.
//

#include "agentmenu.h"

using namespace std;

AgentMenu::AgentMenu(AgentList* p) : AgentListRef(p) {
    mainMenu();
}

void AgentMenu::mainMenu() {
    char selec;
    do {
        system("clear");
        cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;

        cout << "*** MENU DE AGENTES ***" << endl << endl;
        cout << "1.Nuevo Agente" << endl;
        cout << "2.Eliminar Agente" << endl;
        cout << "3.Modificar Agente" << endl;
        cout << "4.Mostrar Agente en especiico" << endl;
        cout << "5.Mostrar Lista de Agentes" << endl;
        cout << "6.Eliminar todos los Agentes" << endl;
        cout << "7.Guardar a Disco" << endl;
        cout << "8.Leer de Disco" << endl;
        cout << "s.Salir" << endl << endl;

        cout << "Elige una opción (1,2,3,4,5,6,7,8,s): ";
        cin >> selec;
        cin.ignore();
        selec = toupper(selec);

        switch (selec) {
            case '1':
                addAgent();
                break;

            case '2':
                deleteAgent();
                break;

            case '3':
                modifyAgent();
                break;

            case '4':
                showAgent();
                break;

            case '5':
                showAgentList();
                break;

            case '6':
                deleteAll();
                break;

            case '7':
                saveInfo();
                break;

            case '8':
                readInfo();
                break;

            case 'S':
                exit();
                break;

            default:
                cout << "Opción Invalida" << endl;
                enterToContinue();
                break;
        }

    } while (selec != 'S');
}


// This func has the objective to save code
// every time is called
void  AgentMenu::enterToContinue() {
    cout << "Presione <enter> para continuar....";
    cin.get();
}


// Func to add an Agente to the Agentlist
void AgentMenu::addAgent() {
    Agent auxAgent;
    AgentNode* pos;
    Name auxName;
    Time auxTime;
    string auxStr;
    int auxInt;
    char auxChar;

    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "AGREGANDO NUEVO AGENTE" << endl << endl;
    cout << "Id: ";
    getline(cin, auxStr);
    auxAgent.setID(auxStr);

    // Valid if the id seted for the user is unique
    // is isn't value, do not let insert
    pos = AgentListRef -> findData(auxAgent);
    if (pos != nullptr) {
        cout << "Ese Agente ya existe dentro de la lista" << endl;
        cout << "por favor intenta de nuevo con otro id" << endl << endl;
        cout << "Regresare al menu anterior" << endl;
        enterToContinue();
        return;
    }

    cout << endl;

    cout << "Apellidos: ";
    getline(cin, auxStr);
    auxName.setLast(auxStr);
    cout << "Nombre/s: ";
    getline(cin, auxStr);
    auxName.setFirst(auxStr);
    auxAgent.setName(auxName);

    cout << endl;
    cout << "Numero de Extension: ";
    getline(cin, auxStr);
    auxAgent.setNumOfExt(atoi(auxStr.c_str()));

    cout << endl;

    cout << "Desea añadir Horas Extras ahora?" << endl;
    do {
        cout << "[s/n]: ";
        cin >> auxChar;
        cin.ignore();
        auxChar = toupper(auxChar);

        if (auxChar != 'S' and auxChar != 'N') {
            cout << "opcion invalida, por favor ingrese [s/n], para continuar" << endl;
        }
    } while (auxChar != 'S' and auxChar != 'N');

    if (auxChar == 'S') {
        cout << "Numero de Horas Extras: ";

        getline(cin, auxStr);
        auxAgent.setExtraHours(atoi(auxStr.c_str()));

    } else {
        auxAgent.setExtraHours(0);
    }

    cout << endl << endl;
    string areas[] = {"Servidores", "De escritorio", "Portatiles", "Linux", "Impresoras", "Redes"};

    for (int i = 0; i < 6; i++) {
        cout << i + 1 << "." << areas[i] << "   ";
        if (i == 2) {
            cout << endl;
        }
    }
    cout << endl << endl;
    cout << "Arriba tienes las diferentes areas" << endl;
    cout << "Seleciona una opcion: ";
    do{
        cout << "[1,2,3,4,5,6]: ";
        getline(cin, auxStr);
        auxInt = atoi(auxStr.c_str());
        cout << endl;

        if (auxInt != 1 and auxInt != 2 and auxInt != 3 and auxInt != 4 and auxInt != 5 and auxInt != 6) {
            cout << "opcion invalida, por favor ingrese [1,2,3,4,5,6], para continuar" << endl;
        }

    } while (auxInt != 1 and auxInt != 2 and auxInt != 3 and auxInt != 4 and auxInt != 5 and auxInt != 6);

    auxAgent.setDepartment(areas[auxInt-1]);

    cout << endl;
    cout << "Hora de Entrada (HH:MM): ";
    getline(cin, auxStr, ':');
    auxTime.setHour(atoi(auxStr.c_str()));
    getline(cin, auxStr);
    auxTime.setMinute(atoi(auxStr.c_str()));
    auxTime.setSecond(0);
    auxAgent.setStartingTime(auxTime);

    cout << endl;
    cout << "Hora de Salida (HH:MM): ";
    getline(cin, auxStr, ':');
    auxTime.setHour(atoi(auxStr.c_str()));
    getline(cin, auxStr);
    auxTime.setMinute(atoi(auxStr.c_str()));
    auxTime.setSecond(0);
    auxAgent.setEndingTime(auxTime);

    cout << endl;
    // Manage with possibles failures that system could throw
    try {
        pos = AgentListRef -> insertData(AgentListRef -> getLastPos(), auxAgent);
    } catch (ListException ex) {
        cout << "Hubo un error" << endl;
        cout << "El Agente no se epudo insertar" << endl;
        cout << "El sisema infora el siguiente error " << ex.what();
        cout << "Si este problema persiste, por favor informelo a soporte" << endl;
        cout << "Regresare al menu principal" << endl;
        enterToContinue();
        return;
    }

    cout << "Agente insertado exitosamente!" << endl << endl;
    cout << "Desea añadir Clientes ahora?" << endl;
    do {
        cout << "[s/n]: ";
        cin >> auxChar;
        cin.ignore();
        auxChar = toupper(auxChar);

        if (auxChar != 'S' and auxChar != 'N') {
            cout << "opcion invalida, por favor ingrese [s/n], para continuar" << endl;
        }
    } while (auxChar != 'S' and auxChar != 'N');

    if (auxChar == 'S') {
        new ClientMenu(&pos -> getData().getClientList());
        cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
        cout << "AGREGANDO NUEVO AGENTE" << endl << endl;
        cout << "TODO LISTO, AGENTE AGREGADO CON EXITO" << endl;
        enterToContinue();
    } else {
        cout << endl;
        cout << "Te recuerdo que siempre puedes modificar cualquier dato\n";
        cout << "del Agente en la parte modificar, incuyendo la lista de Clientes" << endl;
        enterToContinue();
    }
}


void AgentMenu::deleteAgent() {
    Agent auxAgent;
    Name auxName;
    AgentNode* pos;
    string auxStr;

    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "ELIMINADO AGENTE" << endl << endl;
    cout << "Dame el Nombre del Agente" << endl;
    cout << "Apellidos: ";
    getline(cin, auxStr);
    auxName.setLast(auxStr);
    cout << "Nombre/s: ";
    getline(cin, auxStr);
    auxName.setFirst(auxStr);
    auxAgent.setName(auxName);


    // Valid if the client finded for the client exist
    pos = AgentListRef -> findDataByName(auxAgent);
    if (pos == nullptr) {
        cout << "No existe un Agente dentro de la lista con ese nombre" << endl;
        cout << "por favor intenta de nuevo con otro id" << endl;
        cout << "Regresaré al menu anterior" << endl << endl;
        enterToContinue();
        return;
    } else {
        AgentListRef -> deleteData(pos);
        cout << "Agente eliminado extosamente... " << endl << endl;
        enterToContinue();
    }
}


void AgentMenu::modifyAgent() {
    Agent auxAgent;
    AgentNode* pos;
    Name auxName;
    Time auxTime;
    string auxStr;
    int auxInt;
    char auxChar;

    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "MODIFICANDO AGENTE" << endl << endl;
    cout << "Dame el Nombre del Agente" << endl;
    cout << "Apellidos: ";
    getline(cin, auxStr);
    auxName.setLast(auxStr);
    cout << "Nombre/s: ";
    getline(cin, auxStr);
    auxName.setFirst(auxStr);
    auxAgent.setName(auxName);


    // Valid if the Agent finded for the client exist in the Agent List
    pos = AgentListRef -> findDataByName(auxAgent);

    if (pos == nullptr) {
        cout << endl;
        cout << "No existe un Agente dentro de la lista con ese nombre" << endl;
        cout << "por favor intenta de nuevo con otro id" << endl;
        cout << "Regresaré al menu anterior" << endl << endl;
        enterToContinue();
        return;
    } else {
        system("clear");
        cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
        cout << "MODIFICANDO AGENTE" << endl << endl;
        cout << "AGENTE ENCONTRADO:" << endl << endl;
        cout << "                                                  | HH:MM | HH:MM |" << endl;
        cout << " ID   | Nombre                    | Deparmento    | Entr. | Sali. | EXT  | Horas Extras" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;


        // Show data
        cout << pos -> getData().toString() << endl;
        cout << endl;
        // If the finded agent's ClientList is empty
        // it gives the posibility of add Clients now

        if (pos -> getData().getClientList().isEmpty()) {
            cout << "La lista de Clientes de este Agente esta vacia..." << endl;
            cout << "Desea agregar Clientes a este Agente?" << endl;
            do {
                cout << "[s/n]: ";
                cin >> auxChar;
                cin.ignore();
                auxChar = toupper(auxChar);
                if (auxChar != 'S' and auxChar != 'N') {
                    cout << "opcion invalida, por favor ingrese [s/n], para continuar" << endl;
                }

            } while (auxChar != 'S' and auxChar != 'N');

            if (auxChar == 'S') {
                new ClientMenu(&pos -> getData().getClientList());
                cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
                cout << "MODIFICANDO AGENTE" << endl << endl;
                cout << "TODO LISTO, LOS CLIENTES DEL AGENTE HAB SIDO MANEJADOS CON EXITO" << endl;
                enterToContinue();
            }
        }

        cout << endl << endl;
        cout << "Que caracteristica del Agente desea modificar?" << endl;
        cout << "1.ID   2.No de Ext   3.No de Horas Extras" << endl;
        cout << "4.Nombre   5.Departamento" << endl;
        cout << "6.Hora de Entrada   7.Hora de Salida" << endl;
        cout << "8.Ir al menu de la Lista de Clientes del Agente" << endl;
        cout << "9.Regresar el Menu Anterior" << endl;
        cout << "Seleciona una opción [1/2/3/4/5/6/7/8/9]: ";
        cin >> auxChar;
        cin.ignore();
        cout << endl << endl;

        switch (auxChar) {

            case '1':
            {
                AgentNode* findedPos;
                string saveStr;

                auxAgent = AgentListRef -> retrieve(pos);
                // Saving the current ID in case that the user write a exiting one
                // and return the current ID at the end
                saveStr = pos -> getData().getID();

                cout << "Ingrese el nuevo dato: " << endl;
                cout << "Id: ";
                getline(cin, auxStr);
                pos -> getData().setID(auxStr);

                // Valid if the ID seted for the user is unique
                // is isn't value, do not let change
                findedPos = AgentListRef -> findData(auxAgent);

                if (findedPos != nullptr) {
                    pos -> getData().setID(saveStr);
                    cout << "Ese Agente ya existe dentro de la lista" << endl;
                    cout << "por favor intenta de nuevo con otro id" << endl << endl;
                    cout << "Regresaré al menu anterior" << endl;
                    enterToContinue();
                    return;
                }

            }
                break;


            case '2':
                cout << "Ingrese el nuevo dato: " << endl;
                cout << "Numero de Extension: ";
                getline(cin, auxStr);
                pos -> getData().setNumOfExt(atoi(auxStr.c_str()));
                break;


            case '3':
                cout << "Ingrese el nuevo dato: " << endl;
                cout << "Numero de Horas Extras: ";
                getline(cin, auxStr);
                pos -> getData().setExtraHours(atoi(auxStr.c_str()));
                break;


            case '4':
                cout << "Ingrese el nuevo dato: " << endl;
                cout << "Apellidos: ";
                getline(cin, auxStr);
                auxName.setLast(auxStr);
                cout << "Nombre/s: ";
                getline(cin, auxStr);
                auxName.setFirst(auxStr);
                pos -> getData().setName(auxName);
                break;


            case '5':
            {
                cout << endl << endl;
                cout << "Ingrese el nuevo dato: " << endl;
                string areas[] = {"Servidores", "De escritorio", "Portatiles", "Linux", "Impresoras", "Redes"};

                for (int i = 0; i < 6; i++) {
                    cout << i + 1 << "." << areas[i] << "   ";
                    if (i == 2) {
                        cout << endl;
                    }
                }
                cout << endl << endl;
                cout << "Arriba tienes las diferentes areas" << endl;
                cout << "Seleciona una opcion: ";
                do{
                    cout << "[1,2,3,4,5,6]: ";
                    getline(cin, auxStr);
                    auxInt = atoi(auxStr.c_str());
                    cout << endl;

                    if (auxInt != 1 and auxInt != 2 and auxInt != 3 and auxInt != 4 and auxInt != 5 and auxInt != 6) {
                        cout << "opcion invalida, por favor ingrese [1,2,3,4,5,6], para continuar" << endl;
                    }

                } while (auxInt != 1 and auxInt != 2 and auxInt != 3 and auxInt != 4 and auxInt != 5 and auxInt != 6);

                pos -> getData().setDepartment(areas[auxInt-1]);
            }
                break;


            case '6':
                cout << "Ingrese el nuevo dato: " << endl;
                cout << "Hora de Entrada (HH:MM): ";
                getline(cin, auxStr, ':');
                auxTime.setHour(atoi(auxStr.c_str()));
                getline(cin, auxStr);
                auxTime.setMinute(atoi(auxStr.c_str()));
                auxTime.setSecond(0);
                pos -> getData().setStartingTime(auxTime);
                break;


            case '7':
                cout << "Ingrese el nuevo dato: " << endl;
                cout << "Hora de Salida (HH:MM): ";
                getline(cin, auxStr, ':');
                auxTime.setHour(atoi(auxStr.c_str()));
                getline(cin, auxStr);
                auxTime.setMinute(atoi(auxStr.c_str()));
                auxTime.setSecond(0);
                pos -> getData().setEndingTime(auxTime);
                break;


            case '8':
                new ClientMenu(&pos -> getData().getClientList());
                break;

            case '9':
                enterToContinue();
                return;
                break;

            default:
                cout << "Opción Invalida" << endl;
                enterToContinue();
                break;
        }

        cout << endl;
        cout << "Agente modificado extiosamente" << endl;
        enterToContinue();
    }
}


void AgentMenu::showAgent() {
    Agent auxAgent;
    Name auxName;
    AgentNode* pos;
    string auxStr;
    char auxChar;

    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "BUSCANDO AGENTE" << endl << endl;
    cout << "Dame el Nombre del Agente" << endl;
    cout << "Apellidos: ";
    getline(cin, auxStr);
    auxName.setLast(auxStr);
    cout << "Nombre/s: ";
    getline(cin, auxStr);
    auxName.setFirst(auxStr);
    auxAgent.setName(auxName);

    // Valid if the client finded for the client exist
    pos = AgentListRef -> findDataByName(auxAgent);
    if (pos == nullptr) {
        cout << "No existe un Agente dentro de la lista con ese nombre" << endl;
        cout << "por favor intenta de nuevo con otro id" << endl;
        cout << "Regresaré al menu anterior" << endl << endl;
        enterToContinue();
        return;
    } else {
        system("clear");
        cout << "!------------------------------ MEXI-CALL-CENTER ------------------------------------!" << endl << endl;
        cout << "BUSCANDO AGENTE" << endl << endl;
        auxAgent = AgentListRef -> retrieve(pos);
        cout << "AGENTE BUSCADO:" << endl << endl;
        cout << "                                                  | HH:MM | HH:MM |" << endl;
        cout << " ID   | Nombre                    | Deparmento    | Entr. | Sali. | EXT  | Horas Extras" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << auxAgent.toString() << endl;
        cout << endl;
        if (auxAgent.getClientList().isEmpty()) {
            cout << "La lista de Clientes de este Agente esta vacia..." << endl;
            cout << "Desea agregar Clientes a este Agente?" << endl;
            do {
                cout << "[s/n]: ";
                cin >> auxChar;
                cin.ignore();
                auxChar = toupper(auxChar);

                if (auxChar != 'S' and auxChar != 'N') {
                    cout << "opcion invalida, por favor ingrese [s/n], para continuar" << endl;
                }

            } while (auxChar != 'S' and auxChar != 'N');

            if (auxChar == 'S') {
                new ClientMenu(&pos -> getData().getClientList());
                cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
                cout << "BUSCANDO AGENTE" << endl << endl;
                cout << "TODO LISTO, LA LISTA DEL AGENTE FUE MODIFICADA CON EXITO" << endl;
                enterToContinue();
            } else {
                enterToContinue();
            }
        } else {
            cout << "CLIENTES ATENDIDOS POR EL AGENTE BUSCADO:" << endl << endl;
            cout << "                              | HH:MM | HH:MM:SS |" << endl;
            cout << " ID   | Nombre                | Hora  | Duracion |" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << auxAgent.getClientList().toString() << endl;
            enterToContinue();
        }
    }
}


// Just shows the list of the Agents
void AgentMenu::showAgentList() {
    char auxChar;
    system("clear");
    cout << "!-------------------------------- MEXI-CALL-CENTER -------------------------------------!" << endl << endl;
    cout << "LISTADO DE AGENTES" << endl << endl;

    if (AgentListRef -> isEmpty()) {
        cout << "La lista esta vacia" << endl;
        cout << "inserte algún Agente" << endl << endl;
        enterToContinue();
    } else {

        cout << "Desea filtrar los agentes por especialidad? " << endl;
        cout << "Si su respuesta es no, los agentes se desplegaran ordenados por nombre" << endl;
        do {
            cout << "[s/n]: ";
            cin >> auxChar;
            auxChar = toupper(auxChar);
            cin.ignore();

            if (auxChar != 'S' and auxChar != 'N') {
                cout << "opcion invalida, por favor ingrese [s/n], para continuar" << endl;
            }

        } while (auxChar != 'S' and auxChar != 'N');

        if (auxChar == 'S') {
            AgentListRef -> sortByDepartment();
        } else {
            AgentListRef -> sortByName();
        }

        cout << "                                                  | HH:MM | HH:MM |" << endl;
        cout << " ID   | Nombre                    | Deparmento    | Entr. | Sali. | EXT  | Horas Extras" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << AgentListRef -> toString() << endl << endl;
        enterToContinue();
    }
}


// Func to delete all the Agents
void AgentMenu::deleteAll() {
    char answer;
    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << "ELIMINADO LISTA DE CLIENTES" << endl << endl;
    cout << "Esta seguro de BORRAR toda la LISTA de Clientes:?" << endl;
    cout << "Presione (s) para BORRAR, cualquier otro devuelve al menu anterior" << endl;
    cin >> answer;
    answer = toupper(answer);
    cin.ignore();
    if (answer == 'S') {
        AgentListRef -> ~AgentList();
        cout << "Lista Borrada exitosamente" << endl;
        new AgentMenu(new AgentList);
        enterToContinue();
    } else {
        return;
    }
}


void AgentMenu::exit() {
    string auxStr;
    system("clear");
    cout << "!--------- MEXI-CALL-CENTER ----------!" << endl << endl;
    cout << endl << endl;

    cout <<"GRACIAS POR USAR MEXI-CALL-CENTER" << endl << endl;
    enterToContinue();
    system("clear");

}


void AgentMenu::saveInfo() {
    string auxStr;
    system("clear");
    cout << "!-------------------------------- MEXI-CALL-CENTER ---------------------------------!" << endl << endl;
    cout << "ESCRIBIENDO A DISCO" << endl << endl;
    auxStr = AgentListRef -> writeToDisk("agents");
    cout << endl;
    cout << auxStr << endl << endl;
    cout << "INFORMACION GUARDADA CON ÉXITO" << endl;
    enterToContinue();
}

void AgentMenu::readInfo() {
    string auxStr;
    system("clear");
    cout << "!-------------------------------- MEXI-CALL-CENTER ---------------------------------!" << endl << endl;
    cout << "LEYENDO DEL DISCO" << endl << endl;

    try {
        auxStr = AgentListRef -> readFromDisk("agents");
    } catch (ListException ex) {
        cout << "Hubo un error" << endl;
        cout << "No se encontró el archivo para leer datos" << endl;
        cout << "El sisema informa: " << ex.what() << endl;
        cout << "Presione primero la opción de guardar...." << endl;
        cout << "Regresaré al menu principal" << endl;
        enterToContinue();
        return;
    }

    cout << endl;
    cout << auxStr << endl << endl;
    cout << "INFORMACION LEIDA CON ÉXITO" << endl;
    enterToContinue();
}






