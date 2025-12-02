#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <io.h> // Per stampare le carte
#include <fcntl.h> // Per stampare le carte

using namespace std;



void scelte(int &scelta, int &nEstrazioni);
void random(int &seme,int &valore, int &scelta);
void confronti (int &scelta, int &nEstrazioni,int &coppia);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << "prova";
    cout << R"(
                ┌─────────┐   ┌─────────┐   ┌─────────┐   ┌─────────┐
                │4        │   │A        │   │J        │   │10       │
                │         │   │         │   │         │   │         │
                │    ♦    │   │    ♣    │   │    ♠    │   │    ♥    │
                │         │   │         │   │         │   │         │
                │        4│   │        A│   │        J│   │       10│
                └─────────┘   └─────────┘   └─────────┘   └─────────┘
            )" << endl;
    int scelta = 0;
    int nEstrazioni = 0;
    scelte(scelta, nEstrazioni);

    return 0;
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
                cout <<"inserire un qualunque numero per continuare"<<endl;
                cin >>scelta;
                continue;
        }
        system ("cls");
        do {
            cout << "Inserisci il numero di estrazione" << endl;
            cin >> nEstrazioni;
        } while (nEstrazioni <= 1);
        break;
    }
}

void random(int &seme,int &valore, int &scelta)
{

    if (scelta == 1) {
        srand(time(NULL));
        valore = rand () %10+1;
        seme = rand () %4+1;
    } else if (scelta == 2) {
        srand(time(NULL));
        valore = rand () %13+1;
        seme = rand () %4+1;
    }
}

void confronti (int &scelta, int &nEstrazioni,int &coppia)
{
    int valore = 0, seme = 0, semePrecedente = 0, valorePrecedente = 0;
    random (seme, valore, scelta);
    semePrecedente=seme;
    valorePrecedente=valore;

    for (int i = 0; i<nEstrazioni; i++) {
        random (seme, valore, scelta); // 3 e 4 (valori) sono neri
        if (semePrecedente != seme && valorePrecedente == valore) {
            coppia++;
            }
        }

}
