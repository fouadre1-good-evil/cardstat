#include <iostream>
#include <windows.h> //Per system("cls") e per dare colori alle carte
#include <ctime> //Per il random
#include <cstdlib> //Per il random
#include <io.h> // Per stampare le carte
#include <fcntl.h> // Per stampare le carte

using namespace std;

void menu ();                                                                                   //-------|
void scelte(int &scelta, int &nEstrazioni);                                                     //       |
void random(int &seme,int &valore, int &scelta);                                                //       |------> Le varie funzioni
void confronti (int &scelta, int &nEstrazioni);                                                 //       |
void disegna_carte(int scelta ,int valore ,int valorePrecedente ,int seme ,int semePrecedente); //-------|
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(NULL));
    system("color F0");
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
    cout << "HI" << endl;
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout << "HELLO" << endl;
    while(true){
        int scelta = 0;
        int nEstrazioni = 0;
        menu();
        scelte(scelta, nEstrazioni);
        confronti (scelta ,nEstrazioni);
    }
    return 0;
}

void menu ()
{
    cout <<R"()";
}

void scelte (int &scelta, int &nEstrazioni)
{
    while(true){
        cout <<"Si vuole giocare con il mazzo da 40 o 52 carte inserire"<<endl;
        cout <<"- 1 per il mazzo da 40 carte"<<endl;
        cout <<"- 2 per il mazzo da 52 carte"<<endl;
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
                continue;
        }
        system ("cls");
        do {
            cout << "Inserisci il numero di estrazione" << endl;
            cin >> nEstrazioni;
            Sleep(2000);
            system("cls");
        } while (nEstrazioni <= 1);
        break;
    }
}

void random(int &seme,int &valore, int &scelta)
{

    if (scelta == 1) {
        valore = rand () %10+1;
        seme = rand () %4+1;
    } else if (scelta == 2) {
        valore = rand () %13+1;
        seme = rand () %4+1;
    }
}

void confronti (int &scelta, int &nEstrazioni)
{
    int valore = 0, seme = 0, semePrecedente = 0, valorePrecedente = 0 ,coppia = 0;
    random (semePrecedente, valorePrecedente, scelta);
    for (int i = 1; i<nEstrazioni; i++) {
        random (seme, valore, scelta); // 3 e 4 (valori) sono neri
        disegna_carte(scelta ,valore ,valorePrecedente ,seme ,semePrecedente);
        if (semePrecedente != seme && valorePrecedente == valore) {
            coppia++;
            }
        cout <<endl;
        cout <<"numero di coppie: "<<coppia<<endl;
        Sleep(2000);
        system("cls");
            semePrecedente = seme;
            valorePrecedente = valore;
        }
}

void disegna_carte(int scelta ,int valore ,int valorePrecedente ,int seme ,int semePrecedente)
{
    bool carta_disegnata = true;
    if (scelta == 1){
            if (valorePrecedente >=8){
                switch (valorePrecedente){
                case 8:
                    switch (semePrecedente){
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
                    switch (semePrecedente){
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
                    switch (semePrecedente){
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
                }else{
                        switch (semePrecedente){
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
            if (valore>=8){
                switch (valore){
                case 8:
                    switch (seme){
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
                    switch (seme){
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
                        switch (seme){
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
            }else{
                switch (seme){
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
        }else{
    }
}

