#include <iostream>
#include <windows.h> //Per system("cls") e per dare colori alle carte
#include <ctime> //Per il random
#include <cstdlib> //Per il random
#include <io.h> // Per stampare le carte
#include <fcntl.h> // Per stampare le carte
using namespace std;

void menu ();                                                                                   //-------|
void scelte(int &scelta,int &nEstrazioni,int &grafica);                                         //       |
void random(int &seme,int &valore,int &scelta);                                                 //       |------> Le varie funzioni
void confronti (int &scelta,int &nEstrazioni,int grafica,int &riniziare);                       //       |
void disegna_carte(int scelta,int valore,int valorePrecedente,int seme,int semePrecedente);     //-------|

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(NULL));
    menu();
    system("color F0");
    while(true) {
        int scelta = 0,nEstrazioni = 0,grafica = 0,riniziare = 0;
        scelte(scelta,nEstrazioni,grafica);
        confronti(scelta,nEstrazioni,grafica,riniziare);
        if (riniziare !=1) {
            break;
        }
    }
    return 0;
}

void menu () {
    cout <<R"(
                        ____  ______ _   ___      ________ _   _ _    _ _______ ____      _   _ ______ _
                        |  _ \|  ____| \ | \ \    / /  ____| \ | | |  | |__   __/ __ \    | \ | |  ____| |
                        | |_| | |__  |  \| |\ \  / /| |__  |  \| | |  | |  | | | |  | |   |  \| | |__  | |
                        |  _ <|  __| | . ` | \ \/ / |  __| | . ` | |  | |  | | | |  | |   | . ` |  __| | |
                        | |_| | |____| |\  |  \  /  | |____| |\  | |__| |  | | | |__| |   | |\  | |____| |____
                        |____/|______|_| \_|_  \/  _|______|_| \_|\____/   |_|__\____/__  |_|_\_|______|______|
                             _____          _      _____ ____  _            _______ ____  _____  ______
                            / ____|   /\   | |    / ____/ __ \| |        /\|__   __/ __ \|  __ \|  ____|
                           | |       /  \  | |   | |   | |  | | |       /  \  | | | |  | | |__| | |__
                           | |      / /\ \ | |   | |   | |  | | |      / /\ \ | | | |  | |  _  /|  __|
                           | |____ / ____ \| |___| |___| |__| | |____ / ____ \| | | |__| | | \ \| |____
                            \_____/_/___ \_\______\_____\____/|______/_/___ \_\_|_ \____/|_|__\_\______|
  _____  ______ _      _      ______     _____ ____  _____  _____ _____ ______    _____ _____     _____          _____ _______ ______
 |  __ \|  ____| |    | |    |  ____|   / ____/ __ \|  __ \|  __ \_   _|  ____|  |  __ \_   _|   / ____|   /\   |  __ \__   __|  ____|
 | |  | | |__  | |    | |    | |__     | |   | |  | | |__| | |__| || | | |__     | |  | || |    | |       /  \  | |__| | | |  | |__
 | |  | |  __| | |    | |    |  __|    | |   | |  | |  ___/|  ___/ | | |  __|    | |  | || |    | |      / /\ \ |  _  /  | |  |  __|
 | |__| | |____| |____| |____| |____   | |___| |__| | |    | |    _| |_| |____   | |__| || |_   | |____ / ____ \| | \ \  | |  | |____
 |_____/|______|______|______|______|   \_____\____/|_|    |_|   |_____|______|  |_____/_____|   \_____/_/    \_\_|  \_\ |_|  |______|

)";
    Sleep(6000);
    system("cls");
}

void scelte (int &scelta ,int &nEstrazioni ,int &grafica)
{
    while(true){
        cout <<R"(┌──────────────────────────────────────────────────────────────────────────┐
│Come si vuole la rappresentazione grafica?                                │
│ - 1 Rappresentazione grafica delle carte (massimo 50 estrazioni)         │
│ - 2 Risultato della quantita' di coppie (nessun limite sulle estrazioni) │
└──────────────────────────────────────────────────────────────────────────┘
)";
        cin >> grafica;
        system("cls");
        switch (grafica) {
        case 1:
            do {
                cout << "Inserisci il numero di estrazione" << endl;
                cin >> nEstrazioni;
                system("cls");
                if (nEstrazioni <= 1 || nEstrazioni >=50) {
                    cout <<"Valore non valido! Riprovare"<<endl;
                    Sleep(2000);
                    system("cls");
                }
            } while (nEstrazioni <= 1 || nEstrazioni >=50);
            break;
        case 2:
            do {
                cout << "Inserisci il numero di estrazione" << endl;
                cin >> nEstrazioni;
                system("cls");
                if(nEstrazioni <= 1) {
                    cout <<"Valore non valido! Riprovare"<<endl;
                    Sleep(2000);
                    system("cls");
                }
            } while (nEstrazioni <= 1);
            break;
        default:
            cout <<"Scelta non valida! Riprovare"<<endl;
            Sleep(2000);
            system("cls");
            continue;
        }
        break;
    }
    while(true) {
        cout <<R"(┌────────────────────────────────────────────────────────────────┐
│ Si vuole giocare con il mazzo da 40 o 52 carte inserire        │
│   - Digita 1 per il mazzo da 40 carte                          │
│   - Digita 2 per il mazzo da 52 carte                          │
└────────────────────────────────────────────────────────────────┘
)";

        cin >>scelta;
        system ("cls");
        switch(scelta) {
        case 1 :
            break;
        case 2:
            break;
        default:
            cout <<"il valore inserito e' sbagliato riprovare"<<endl;
            Sleep(2000);
            system("cls");
            continue;
        }
        break;
    }
}

void random(int &seme,int &valore, int &scelta) {

    if (scelta == 1) {
        valore = rand () %10+1;
        seme = rand () %4+1;
    } else if (scelta == 2) {
        valore = rand () %13+1;
        seme = rand () %4+1;
    }
}

void confronti (int &scelta,int &nEstrazioni,int grafica,int &riniziare) {
    int valore = 0, seme = 0, semePrecedente = 0, valorePrecedente = 0,coppia_generale = 0,coppia_seme = 0,coppia_valore = 0,coppia_colore = 0,coppia_figure = 0;
    random (semePrecedente, valorePrecedente, scelta);
    for (int i = 1; i<nEstrazioni; i++) {
        random (seme, valore, scelta);

        if (grafica == 1) {
            disegna_carte(scelta,valore,valorePrecedente,seme,semePrecedente);
        }

        if (semePrecedente != seme && valorePrecedente == valore) {
            coppia_generale++;
        }

        if (semePrecedente == seme) {
            coppia_seme++;
        }

        if (valorePrecedente == valore) {
            coppia_valore++;
        }

        if((semePrecedente <=2 && seme <=2) || (semePrecedente>2 && seme>2)) {
            coppia_colore++;
        }

        if(scelta == 1 && valorePrecedente >=8 && valore >=8) {
            coppia_figure++;
        } else if (scelta == 2 && valorePrecedente >=11 && valore >=11) {
            coppia_figure++;
        }

        if (grafica == 1) {
            cout <<endl;
            cout <<"numero di coppie dello stesso seme: "<<coppia_seme<<endl;
            cout <<"numero di coppie dello stesso valore: "<<coppia_valore<<endl;
            cout <<"numero di coppie dello stesso colore: "<<coppia_colore<<endl;
            cout <<"numero di coppie di figure: "<<coppia_figure<<endl;
            cout <<"numero di coppie generale: "<<coppia_generale<<endl;
            Sleep(2000);
            system("cls");
        }

        semePrecedente = seme;
        valorePrecedente = valore;
    }
    system("cls");
    cout <<"|Numero di coppie dello stesso seme: "<<coppia_seme<<endl;
    cout <<"|Numero di coppie dello stesso valore: "<<coppia_valore<<endl;
    cout <<"|Numero di coppie dello stesso colore: "<<coppia_colore<<endl;
    cout <<"|Numero di coppie di figure: "<<coppia_figure<<endl;
    cout <<"|Numero di coppie generale: "<<coppia_generale<<endl;
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------------------------------"<<endl;
    cout <<endl;
    cout <<"Premere 1 per riniziare "<<endl;
    cout <<"Premere qualsiasi altro numero per uscire"<<endl;
    cin >>riniziare;
    switch(riniziare) {
    case 1:
        system("cls");
        break;
    default:
        system("cls");
        break;
    }
}

void disegna_carte(int scelta,int valore,int valorePrecedente,int seme,int semePrecedente) {
    if (scelta == 1) {
        if (valorePrecedente >=8) {
            switch (valorePrecedente) {
            case 8:
                switch (semePrecedente) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♥    │
│         │
│        J│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♦    │
│         │
│        J│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♣    │
│         │
│        J│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♠    │
│         │
│        J│
└─────────┘
                )";
                    break;
                }
                break;
            case 9:
                switch (semePrecedente) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♥    │
│         │
│        Q│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♦    │
│         │
│        Q│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♣    │
│         │
│        Q│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♠    │
│         │
│        Q│
└─────────┘
                )";
                    break;
                }
                break;
            case 10:
                switch (semePrecedente) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♥    │
│         │
│        K│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♦    │
│         │
│        K│
└─────────┘
                )" << endl;
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♣    │
│         │
│        K│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♠    │
│         │
│        K│
└─────────┘
                )";
                    break;
                }
                break;
            }
        } else {
            switch (semePrecedente) {
            case 1:
                SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(        │
│         │
│    ♥    │
│         │
│        )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                break;
            case 2:
                SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(        │
│         │
│    ♦    │
│         │
│        )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                break;
            case 3:
                cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(        │
│         │
│    ♣    │
│         │
│        )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                break;
            case 4:
                cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(        │
│         │
│    ♠    │
│         │
│        )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                break;
            }
        }
        if (valore>=8) {
            switch (valore) {
            case 8:
                switch (seme) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♥    │
│         │
│        J│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♦    │
│         │
│        J│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♣    │
│         │
│        J│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♠    │
│         │
│        J│
└─────────┘
                )";
                    break;
                }
                break;
            case 9:
                switch (seme) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♥    │
│         │
│        Q│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♦    │
│         │
│        Q│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♣    │
│         │
│        Q│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♠    │
│         │
│        Q│
└─────────┘
                )";
                    break;
                }
                break;
            case 10:
                switch (seme) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♥    │
│         │
│        K│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♦    │
│         │
│        K│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♣    │
│         │
│        K│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♠    │
│         │
│        K│
└─────────┘
                )";
                    break;
                }
            }
        } else {
            switch (seme) {
            case 1:
                SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                cout << R"(
┌─────────┐
│)"<<valore<< R"(        │
│         │
│    ♥    │
│         │
│        )"<<valore<< R"(│
└─────────┘
                        )";
                SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                break;
            case 2:
                SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                cout << R"(
┌─────────┐
│)"<<valore<< R"(        │
│         │
│    ♦    │
│         │
│        )"<<valore<< R"(│
└─────────┘
                        )";
                SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                break;
            case 3:
                cout << R"(
┌─────────┐
│)"<<valore<< R"(        │
│         │
│    ♣    │
│         │
│        )"<<valore<< R"(│
└─────────┘
                        )";
                break;
            case 4:
                cout << R"(
┌─────────┐
│)"<<valore<< R"(        │
│         │
│    ♠    │
│         │
│        )"<<valore<< R"(│
└─────────┘
                        )";
                break;
            }
        }
    } else {
        if (valorePrecedente >=11) {
            switch (valorePrecedente) {
            case 11:
                switch (semePrecedente) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♥    │
│         │
│        J│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♦    │
│         │
│        J│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♣    │
│         │
│        J│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♠    │
│         │
│        J│
└─────────┘
                )";
                    break;
                }
                break;
            case 12:
                switch (semePrecedente) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♥    │
│         │
│        Q│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♦    │
│         │
│        Q│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♣    │
│         │
│        Q│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♠    │
│         │
│        Q│
└─────────┘
                )";
                    break;
                }
                break;
            case 13:
                switch (semePrecedente) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♥    │
│         │
│        K│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♦    │
│         │
│        K│
└─────────┘
                )" << endl;
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♣    │
│         │
│        K│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♠    │
│         │
│        K│
└─────────┘
                )";
                    break;
                }
                break;
            }
        } else {
            if (valorePrecedente == 10) {
                switch (semePrecedente) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(       │
│         │
│    ♥    │
│         │
│       )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(       │
│         │
│    ♦    │
│         │
│       )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(       │
│         │
│    ♣    │
│         │
│       )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(       │
│         │
│    ♠    │
│         │
│       )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                    break;
                }
            } else {
                switch (semePrecedente) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(        │
│         │
│    ♥    │
│         │
│        )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(        │
│         │
│    ♦    │
│         │
│        )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(        │
│         │
│    ♣    │
│         │
│        )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│)"<<valorePrecedente<< R"(        │
│         │
│    ♠    │
│         │
│        )"<<valorePrecedente<< R"(│
└─────────┘
                        )";
                    break;
                }
            }
        }
        if (valore>=11) {
            switch (valore) {
            case 11:
                switch (seme) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♥    │
│         │
│        J│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♦    │
│         │
│        J│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♣    │
│         │
│        J│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│J        │
│         │
│    ♠    │
│         │
│        J│
└─────────┘
                )";
                    break;
                }
                break;
            case 12:
                switch (seme) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♥    │
│         │
│        Q│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♦    │
│         │
│        Q│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♣    │
│         │
│        Q│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│Q        │
│         │
│    ♠    │
│         │
│        Q│
└─────────┘
                )";
                    break;
                }
                break;
            case 13:
                switch (seme) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♥    │
│         │
│        K│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♦    │
│         │
│        K│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♣    │
│         │
│        K│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│K        │
│         │
│    ♠    │
│         │
│        K│
└─────────┘
                )";
                    break;
                }
            }
        } else {
            if (valore == 10) {
                switch (seme) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│)"<<valore<< R"(       │
│         │
│    ♥    │
│         │
│       )"<<valore<< R"(│
└─────────┘
                        )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│)"<<valore<< R"(       │
│         │
│    ♦    │
│         │
│       )"<<valore<< R"(│
└─────────┘
                        )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│)"<<valore<< R"(       │
│         │
│    ♣    │
│         │
│       )"<<valore<< R"(│
└─────────┘
                        )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│)"<<valore<< R"(       │
│         │
│    ♠    │
│         │
│       )"<<valore<< R"(│
└─────────┘
                )";
                    break;
                }
            } else {
                switch (seme) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│)"<<valore<< R"(        │
│         │
│    ♥    │
│         │
│        )"<<valore<< R"(│
└─────────┘
                        )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│)"<<valore<< R"(        │
│         │
│    ♦    │
│         │
│        )"<<valore<< R"(│
└─────────┘
                        )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│)"<<valore<< R"(        │
│         │
│    ♣    │
│         │
│        )"<<valore<< R"(│
└─────────┘
                        )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│)"<<valore<< R"(        │
│         │
│    ♠    │
│         │
│        )"<<valore<< R"(│
└─────────┘
                )";
                    break;
                }
            }
        }
    }
}

