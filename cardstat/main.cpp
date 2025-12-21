#include <iostream>
#include <windows.h> //Per system("cls") e per dare colori alle carte
#include <ctime> //Per il random
#include <cstdlib> //Per il random
#include <io.h> // Per stampare le carte
#include <fcntl.h> // Per stampare le carte
#include <graphics.h> // Per aprire la console grafica

using namespace std;

void menu ();                                                                                                                                                      //-------|
void scelte(int &scelta ,int &nEstrazioni ,int &grafica);                                                                                                          //       |
void random(int &seme ,int &valore ,int &scelta ,double &nCuori ,double &nSpade ,double &nFiori ,double &nPick ,double &nNere ,double &nRosse ,double &nFigure);   //       |------> Le varie funzioni
void confronti (int &scelta ,int &nEstrazioni ,int grafica ,int &riniziare);                                                                                       //       |
void disengaCarte(int scelta ,int valore ,int valorePrecedente ,int seme ,int semePrecedentedouble);                                                              //-------|
void easter_egg();

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    keybd_event(VK_MENU, 0x36,0,0);                  // ---------|
    keybd_event(VK_RETURN, 0x1c,0,0);                //          | ------> Per mettere lo
    keybd_event(VK_RETURN, 0x1c,KEYEVENTF_KEYUP,0);  //          | ------> schermo intero all'avvio
    keybd_event(VK_MENU, 0x38,KEYEVENTF_KEYUP,0);    // ---------|
    SetConsoleOutputCP(CP_UTF8); // ------> Per i simboli
    SetConsoleCP(CP_UTF8);       // ------> delle carte
    srand(time(NULL));
    menu();
    system("color F0"); // Per colorare la console di bianco
    while(true)
    {
        int scelta = 0,nEstrazioni = 0,grafica = 0,riniziare = 0;
        scelte(scelta,nEstrazioni,grafica);
        confronti(scelta,nEstrazioni,grafica,riniziare);
        if (riniziare !=1)
        {
            break;
        }
    }
    return 0;
}

//funzione per il menu
void menu ()
{
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
    Sleep(4000);
    system("cls");
}

//funzione delle scelte
void scelte (int &scelta ,int &nEstrazioni ,int &grafica)
{
    while(true){ //menu iniziale per le scelte con un easter egg
        cout <<R"(┌──────────────────────────────────────────────────────────────────────────┐
│Come si vuole la rappresentazione grafica?                                │
│ - 1 Rappresentazione grafica delle carte (massimo 50 estrazioni)         │
│ - 2 Risultato della quantita' di coppie (nessun limite sulle estrazioni) │
└──────────────────────────────────────────────────────────────────────────┘
)";
        cout << " ";
        cin >> grafica;
        system("cls");
        switch (grafica) {
        case 1:
            do {
                cout << " Inserisci il numero di estrazione" << endl;
                cout << " ";
                cin >> nEstrazioni;
                system("cls");
                if (nEstrazioni <= 1 || nEstrazioni >50) {
                    cout <<"Valore non valido! Riprovare"<<endl;
                    Sleep(2000);
                    system("cls");
                }
            } while (nEstrazioni <= 1 || nEstrazioni >50);
            break;
        case 2:
            do {
                cout << " Inserisci il numero di estrazione" << endl;
                cout << " ";
                cin >> nEstrazioni;
                system("cls");
                if(nEstrazioni <= 1) {
                    cout <<" Valore non valido! Riprovare"<<endl;
                    Sleep(2000);
                    system("cls");
                }
            } while (nEstrazioni <= 1);
            break;
        case 67:
            easter_egg();
        default:
            cout <<" Scelta non valida! Riprovare"<<endl;
            Sleep(2000);
            system("cls");
            continue;
        }
        break;
    }
    while(true) {
        cout <<R"(┌────────────────────────────────────────────────────────────────┐
│ Si vuole giocare con il mazzo da 40 o 52 carte?                │
│   - Digita 1 per il mazzo da 40 carte                          │
│   - Digita 2 per il mazzo da 52 carte                          │
└────────────────────────────────────────────────────────────────┘
)";
        cout << " ";
        cin >>scelta;
        system ("cls");
        switch(scelta) {
        case 1 :
            break;
        case 2:
            break;
        default:
            cout <<" Il valore inserito e' sbagliato riprovare"<<endl;
            Sleep(2000);
            system("cls");
            continue;
        }
        break;
    }
}

void random(int &seme,int &valore, int &scelta ,double &nCuori ,double &nSpade ,double &nFiori ,double &nPick ,double &nNere ,double &nRosse ,double &nFigure) {

    if (scelta == 1) {
        valore = rand () %10+1;
        seme = rand () %4+1;
        if (valore >= 8){
            nFigure++;
        }
    } else if (scelta == 2) {
        valore = rand () %13+1;
        seme = rand () %4+1;
        if (valore >= 11){
            nFigure++;
        }
    }
    if (seme == 1){
        nRosse++;
        nCuori++;
    }else if (seme == 2){
        nRosse++;
        nSpade++;
    }else if (seme == 3){
        nNere++;
        nFiori++;
    }else if (seme == 4){
        nNere++;
        nPick++;
    }
}

void confronti (int &scelta,int &nEstrazioni,int grafica,int &riniziare) {
    int valore = 0 ,seme = 0 ,semePrecedente = 0 ,valorePrecedente = 0 ,coppiaSeme = 0 ,coppiaValore = 0 ,coppiaColore = 0 ,coppiaFigure = 0 ;
    double nCuori = 0 ,nSpade = 0 ,nFiori = 0 ,nPick = 0 ,nNere = 0 ,nRosse = 0 ,nFigure = 0 ,coppiaGenerale = 0 ;
    random (semePrecedente, valorePrecedente, scelta ,nCuori ,nSpade ,nFiori ,nPick ,nNere ,nRosse ,nFigure);
    for (int i = 1; i<nEstrazioni; i++) {
        random (seme, valore, scelta ,nCuori ,nSpade ,nFiori ,nPick ,nNere ,nRosse ,nFigure);
        if (grafica == 1) {
            disengaCarte(scelta,valore,valorePrecedente,seme,semePrecedente);
        }

        if (semePrecedente != seme && valorePrecedente == valore) {
            coppiaGenerale++;
        }

        if (semePrecedente == seme) {
            coppiaSeme++;
        }

        if (valorePrecedente == valore) {
            coppiaValore++;
        }

        if((semePrecedente <=2 && seme <=2) || (semePrecedente>2 && seme>2)) {
            coppiaColore++;
        }

        if(scelta == 1 && valorePrecedente >=8 && valore >=8) {
            coppiaFigure++;
        } else if (scelta == 2 && valorePrecedente >=11 && valore >=11) {
            coppiaFigure++;
        }

        if (grafica == 1) {
            cout <<endl;
            cout <<" Numero di coppie dello stesso seme: "<<coppiaSeme<<endl;
            cout <<" Numero di coppie dello stesso valore: "<<coppiaValore<<endl;
            cout <<" Numero di coppie dello stesso colore: "<<coppiaColore<<endl;
            cout <<" Numero di coppie di figure: "<<coppiaFigure<<endl;
            cout <<" Numero di coppie generale: "<<coppiaGenerale<<endl;
            Sleep(2000);
            system("cls");
        }
        semePrecedente = seme;
        valorePrecedente = valore;
    }
    system("cls");
    cout << " Su un totale di " << nEstrazioni << " sono state calcolate le seguenti:" << endl;
    cout <<" ┌─────────────────────────────────────────────────────────────────────────────────────────┐"<<endl;
    cout <<" │Numero di coppie dello stesso seme: "<<coppiaSeme<<endl;
    cout <<" │";
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
    cout <<"Sono state estratte "<<nCuori<<" carte con i cuori. Frequenza relativa " << (nCuori/nEstrazioni) << " (" <<(nCuori/nEstrazioni)*100<<"%)"<<endl;
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout <<" │";
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
    cout <<"Sono state estratte "<<nSpade<<" carte con i quadri. Frequenza relativa " << (nSpade/nEstrazioni) << " (" <<(nSpade/nEstrazioni)*100<<"%)"<<endl;
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout <<" │";
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
    cout <<"Sono state estratte "<<nFiori<<" carte con i fiori. Frequenza relativa " << (nFiori/nEstrazioni) << " (" <<(nFiori/nEstrazioni)*100<<"%)"<<endl;
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout <<" │";
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
    cout <<"Sono state estratte "<<nPick<<" carte con i picche. Frequenza relativa " << (nPick/nEstrazioni) << " (" <<(nPick/nEstrazioni)*100<<"%)"<<endl;
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout <<" │─────────────────────────────────────────────────────────────────────────────────────────"<<endl;
    cout <<" │Numero di coppie dello stesso valore: "<<coppiaValore<<endl;
    cout <<" │─────────────────────────────────────────────────────────────────────────────────────────"<<endl;
    cout <<" │Numero di coppie dello stesso colore: "<<coppiaColore<<endl;
    cout <<" │";
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
    cout <<"Sono state estratte "<<nRosse<<" carte con rosse. Frequenza relativa " << (nRosse/nEstrazioni) << " (" <<(nRosse/nEstrazioni)*100<<"%)"<<endl;
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout <<" │";
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
    cout <<"Sono state estratte "<<nNere<<" carte con Nere. Frequenza relativa " << (nNere/nEstrazioni) << " (" <<(nNere/nEstrazioni)*100<<"%)"<<endl;
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout <<" │─────────────────────────────────────────────────────────────────────────────────────────"<<endl;
    cout <<" │Numero di coppie di figure: "<<coppiaFigure<<endl;
    cout <<" │";
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
    cout <<"Sono state estratte "<<nFigure<<" carte con Figure. Frequenza relativa " << (nFigure/nEstrazioni) << " (" <<(nFigure/nEstrazioni)*100<<"%)"<<endl;
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout <<" │─────────────────────────────────────────────────────────────────────────────────────────"<<endl;
    cout <<" │Numero di coppie generale: "<<coppiaGenerale<<". Frequenza relativa "<<(coppiaGenerale/nEstrazioni)<<"("<<(coppiaGenerale/nEstrazioni)*100<<"%)"<<endl;
    cout <<" └─────────────────────────────────────────────────────────────────────────────────────────┘"<<endl;
    cout <<endl;
    cout <<" Premere 1 per riniziare "<<endl;
    cout <<" Premere qualsiasi altro numero per uscire"<<endl;
    cout << " ";
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

void disengaCarte(int scelta ,int valore ,int valorePrecedente ,int seme ,int semePrecedente) {
    if (scelta == 1) {
        if (valorePrecedente >=8) {
            switch (valorePrecedente) {
            case 8:
                switch (semePrecedente) {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♥    │
│         │
│        U│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♦    │
│         │
│        U│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♣    │
│         │
│        U│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♠    │
│         │
│        U│
└─────────┘
                )";
                    break;
                }
                break;
            case 9:
                switch (semePrecedente)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♥    │
│         │
│        D│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♦    │
│         │
│        D│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♣    │
│         │
│        D│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♠    │
│         │
│        D│
└─────────┘
                )";
                    break;
                }
                break;
            case 10:
                switch (semePrecedente)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♥    │
│         │
│        R│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♦    │
│         │
│        R│
└─────────┘
                )" << endl;
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♣    │
│         │
│        R│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♠    │
│         │
│        R│
└─────────┘
                )";
                    break;
                }
                break;
            }
        }
        else
        {
            switch (semePrecedente)
            {
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
        if (valore>=8)
        {
            switch (valore)
            {
            case 8:
                switch (seme)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♥    │
│         │
│        U│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♦    │
│         │
│        U│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♣    │
│         │
│        U│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♠    │
│         │
│        U│
└─────────┘
                )";
                    break;
                }
                break;
            case 9:
                switch (seme)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♥    │
│         │
│        D│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♦    │
│         │
│        D│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♣    │
│         │
│        D│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♠    │
│         │
│        D│
└─────────┘
                )";
                    break;
                }
                break;
            case 10:
                switch (seme)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♥    │
│         │
│        R│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♦    │
│         │
│        R│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♣    │
│         │
│        R│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♠    │
│         │
│        R│
└─────────┘
                )";
                    break;
                }
            }
        }
        else
        {
            switch (seme)
            {
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
    else
    {
        if (valorePrecedente >=11)
        {
            switch (valorePrecedente)
            {
            case 11:
                switch (semePrecedente)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♥    │
│         │
│        U│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♦    │
│         │
│        U│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♣    │
│         │
│        U│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♠    │
│         │
│        U│
└─────────┘
                )";
                    break;
                }
                break;
            case 12:
                switch (semePrecedente)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♥    │
│         │
│        D│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♦    │
│         │
│        D│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♣    │
│         │
│        D│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♠    │
│         │
│        D│
└─────────┘
                )";
                    break;
                }
                break;
            case 13:
                switch (semePrecedente)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♥    │
│         │
│        R│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♦    │
│         │
│        R│
└─────────┘
                )" << endl;
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♣    │
│         │
│        R│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♠    │
│         │
│        R│
└─────────┘
                )";
                    break;
                }
                break;
            }
        }
        else
        {
            if (valorePrecedente == 10)
            {
                switch (semePrecedente)
                {
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
            }
            else
            {
                switch (semePrecedente)
                {
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
        if (valore>=11)
        {
            switch (valore)
            {
            case 11:
                switch (seme)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♥    │
│         │
│        U│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♦    │
│         │
│        U│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♣    │
│         │
│        U│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│U        │
│         │
│    ♠    │
│         │
│        U│
└─────────┘
                )";
                    break;
                }
                break;
            case 12:
                switch (seme)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♥    │
│         │
│        D│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♦    │
│         │
│        D│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♣    │
│         │
│        D│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│D        │
│         │
│    ♠    │
│         │
│        D│
└─────────┘
                )";
                    break;
                }
                break;
            case 13:
                switch (seme)
                {
                case 1:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♥    │
│         │
│        R│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 2:
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | BACKGROUND_INTENSITY);
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♦    │
│         │
│        R│
└─────────┘
                )";
                    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    break;
                case 3:
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♣    │
│         │
│        R│
└─────────┘
                )";
                    break;
                case 4:
                    cout << R"(
┌─────────┐
│R        │
│         │
│    ♠    │
│         │
│        R│
└─────────┘
                )";
                    break;
                }
            }
        }
        else
        {
            if (valore == 10)
            {
                switch (seme)
                {
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
            }
            else
            {
                switch (seme)
                {
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

void easter_egg()
{
    initwindow(320,410,"Easter Egg");
    readimagefile("EasterEgg\\AlberoNatale.jpg", 60, 50, 260, 350);
    getch();
    Sleep(2000);
    cleardevice();

}
