//POP_2019_12_10_projekt_1_Mierzwa_Wojciech_AIR_3_176824 GNU GCC COMPILER CODEBLOCKS mingw32-g++
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
const string tabelaWszystkichDat[] = {"3 Feb 2017	","	4 Feb 2017	","	5 Feb 2017	","10 Feb 2017	","	11 Feb 2017	","	12 Feb 2017	","17 Feb 2017	","	18 Feb 2017	",
"	19 Feb 2017	","24 Feb 2017	","	25 Feb 2017	","	26 Feb 2017	","3 Mar 2017	","	4 Mar 2017	","	5 Mar 2017	","10 Mar 2017	",
"	11 Mar 2017	","	12 Mar 2017	","17 Mar 2017	","	18 Mar 2017	","	19 Mar 2017	","24 Mar 2017	","	25 Mar 2017	","	26 Mar 2017	",
"31 Mar 2017	","	1 Apr 2017	","	2 Apr 2017	","7 Apr 2017	","	8 Apr 2017	","	9 Apr 2017	","14 Apr 2017	","	15 Apr 2017	",
"	16 Apr 2017	","21 Apr 2017	","	22 Apr 2017	","	23 Apr 2017	","28 Apr 2017	","	29 Apr 2017	","	30 Apr 2017	","5 May 2017	",
"	6 May 2017	","	7 May 2017	","12 May 2017	","	13 May 2017	","	14 May 2017	","19 May 2017	","	20 May 2017	","	21 May 2017	",
"26 May 2017	","	27 May 2017	","	28 May 2017	","2 Jun 2017	","	3 Jun 2017	","	4 Jun 2017	","9 Jun 2017	","	10 Jun 2017	",
"	11 Jun 2017	","16 Jun 2017	","	17 Jun 2017	","	18 Jun 2017	","23 Jun 2017	","	24 Jun 2017	","	25 Jun 2017	","30 Jun 2017	",
"	1 Jul 2017	","	2 Jul 2017	","7 Jul 2017	","	8 Jul 2017	","	9 Jul 2017	","14 Jul 2017	","	15 Jul 2017	","	16 Jul 2017	",
"21 Jul 2017	","	22 Jul 2017	","	23 Jul 2017	","28 Jul 2017	","	29 Jul 2017	","	30 Jul 2017	","4 Aug 2017	","	5 Aug 2017	",
"	6 Aug 2017	","11 Aug 2017	","	12 Aug 2017	","	13 Aug 2017	","18 Aug 2017	","	19 Aug 2017	","	20 Aug 2017	","25 Aug 2017	",
"	26 Aug 2017	","	27 Aug 2017	","1 Sep 2017	","	2 Sep 2017	","	3 Sep 2017	","8 Sep 2017	","	9 Sep 2017	","	10 Sep 2017	",
"15 Sep 2017	","	16 Sep 2017	","	17 Sep 2017	","22 Sep 2017	","	23 Sep 2017	","	24 Sep 2017	","29 Sep 2017	","	30 Sep 2017	",
"	1 Oct 2017	","6 Oct 2017	","	7 Oct 2017	","	8 Oct 2017	","13 Oct 2017	","	14 Oct 2017	","	15 Oct 2017	","20 Oct 2017	",
"	21 Oct 2017	","	22 Oct 2017	","27 Oct 2017	","	28 Oct 2017	","	29 Oct 2017	","3 Nov 2017	","	4 Nov 2017	","	5 Nov 2017	",
"10 Nov 2017	","	11 Nov 2017	","	12 Nov 2017	","17 Nov 2017	","	18 Nov 2017	","	19 Nov 2017	","24 Nov 2017	","	25 Nov 2017	",
"	26 Nov 2017	","1 Dec 2017	","	2 Dec 2017	","	3 Dec 2017	","8 Dec 2017	","	9 Dec 2017	","	10 Dec 2017	","15 Dec 2017	",
"	16 Dec 2017	","	17 Dec 2017	","22 Dec 2017	","	23 Dec 2017	","	24 Dec 2017	","29 Dec 2017	","	30 Dec 2017	","	31 Dec 2017	",
"	5 Jan 2018	","	6 Jan 2018	","	7 Jan 2018	","12 Jan 2018	","	13 Jan 2018	","	14 Jan 2018	","19 Jan 2018	","	20 Jan 2018	",
"	21 Jan 2018	","26 Jan 2018	","	27 Jan 2018	","	28 Jan 2018	","2 Feb 2018	","	3 Feb 2018	","	4 Feb 2018	","9 Feb 2018	",
"	10 Feb 2018	","	11 Feb 2018	","16 Feb 2018	","	17 Feb 2018	","	18 Feb 2018	","23 Feb 2018	","	24 Feb 2018	","	25 Feb 2018	",
"	2 Mar 2018	","	3 Mar 2018	","	4 Mar 2018	","9 Mar 2018	","	10 Mar 2018	","	11 Mar 2018	","16 Mar 2018	","	17 Mar 2018	",
"	18 Mar 2018	","23 Mar 2018	","	24 Mar 2018	","	25 Mar 2018	","30 Mar 2018	","	31 Mar 2018	","	1 Apr 2018	","6 Apr 2018	",
"	7 Apr 2018	","	8 Apr 2018	","13 Apr 2018	","	14 Apr 2018	","	15 Apr 2018	","20 Apr 2018	","	21 Apr 2018	","	22 Apr 2018	",
"27 Apr 2018	","	28 Apr 2018	","	29 Apr 2018	","4 May 2018	","	5 May 2018	","	6 May 2018	","11 May 2018	","	12 May 2018	",
"	13 May 2018	","18 May 2018	","	19 May 2018	","	20 May 2018	","25 May 2018	","	26 May 2018	","	27 May 2018	","1 Jun 2018	",
"	2 Jun 2018	","	3 Jun 2018	","8 Jun 2018	","	9 Jun 2018	","	10 Jun 2018	","15 Jun 2018	","	16 Jun 2018	","	17 Jun 2018	",
"22 Jun 2018	","	23 Jun 2018	","	24 Jun 2018	","29 Jun 2018	","	30 Jun 2018	","	1 Jul 2018	","6 Jul 2018	","	7 Jul 2018	",
"	8 Jul 2018	","13 Jul 2018	","	14 Jul 2018	","	15 Jul 2018	","20 Jul 2018	","	21 Jul 2018	","	22 Jul 2018	","27 Jul 2018	",
"	28 Jul 2018	","	29 Jul 2018	","3 Aug 2018	","	4 Aug 2018	","	5 Aug 2018	","10 Aug 2018	","	11 Aug 2018	","	12 Aug 2018	",
"17 Aug 2018	","	18 Aug 2018	","	19 Aug 2018	","24 Aug 2018	","	25 Aug 2018	","	26 Aug 2018	","31 Aug 2018	","	1 Sep 2018	",
"	2 Sep 2018	","7 Sep 2018	","	8 Sep 2018	","	9 Sep 2018	","14 Sep 2018	","	15 Sep 2018	","	16 Sep 2018	","21 Sep 2018	",
"	22 Sep 2018	","	23 Sep 2018	","28 Sep 2018	","	29 Sep 2018	","	30 Sep 2018	","5 Oct 2018	","	6 Oct 2018	","	7 Oct 2018	",
"12 Oct 2018	","	13 Oct 2018	","	14 Oct 2018	","19 Oct 2018	","	20 Oct 2018	","	21 Oct 2018	","26 Oct 2018	","	27 Oct 2018	",
"	28 Oct 2018	","2 Nov 2018	","	3 Nov 2018	","	4 Nov 2018	","9 Nov 2018	","	10 Nov 2018	","	11 Nov 2018	","16 Nov 2018	",
"	17 Nov 2018	","	18 Nov 2018	","23 Nov 2018	","	24 Nov 2018	","	25 Nov 2018	","30 Nov 2018	","	1 Dec 2018	","	2 Dec 2018	",
"	7 Dec 2018	","	8 Dec 2018	","	9 Dec 2018	","14 Dec 2018	","	15 Dec 2018	","	16 Dec 2018	","21 Dec 2018	","	22 Dec 2018	",
"	23 Dec 2018	","28 Dec 2018	","	29 Dec 2018	","	30 Dec 2018	","4 Jan 2019	","	5 Jan 2019	","	6 Jan 2019	"};

int tabelaDat[6][2];

void wczytaj(int);
void sprawdz(int);
bool sprawdzPrzedmiot(int,int);
void zaznaczPrzedmiot(int);
void zaliczPrzedmioty(int);
void sprawdzPoprzednikow(int,int);
void wypiszTerminy(int);
void zerujTablice();
void wypisz(int);


struct przedmiot{
    string nazwa;
    string skrot;
    int dataRozpoczecia;
    int dataZakonczenia;
    int dlugoscTrwania;
};

const int var = 15;
przedmiot tablicaPrzedmiotow[var];

int tab[var][var];
int tabRef[var][var];

int main()
{
    cout << "Podaj liczbe przedmiotow!";
    int liczbaPrzedmiotow;
    cin>>liczbaPrzedmiotow;

    wczytaj(liczbaPrzedmiotow);
    wypisz(liczbaPrzedmiotow);
    cout << "Informacja o przedmiotach" << endl;



    for(int i=0; i<liczbaPrzedmiotow; ++i){
        sprawdz(liczbaPrzedmiotow);
    }
    cout << "\n\n\n";
    wypiszTerminy(liczbaPrzedmiotow);

    return 0;
}




void sprawdz(int liczbaPrzedmiotow){
    for(int i=0; i<liczbaPrzedmiotow; ++i){
    bool czyZaznaczyc = true;
        for(int j=0; j<liczbaPrzedmiotow;++j){
            if(tab[i][j] == 1){
                if(sprawdzPrzedmiot(liczbaPrzedmiotow,j)){
                    //przedmiot wypelniony "2",zostal zaliczony mozna kontynuowac
                    czyZaznaczyc = true;
                }
                else{
                    //przedmiot nie zostal zaliczony, nalezy przerwac petle i sprawdzic kolejny przedmiot
                    czyZaznaczyc = false;
                    continue;
                }
            }
        }
        if(czyZaznaczyc){
            zaznaczPrzedmiot(i);
        }
    }
    zaliczPrzedmioty(liczbaPrzedmiotow);
}

bool sprawdzPrzedmiot(int liczbaPrzedmiotow,int x){
//funkcja sprawdza czy dany przedmiot zostal zaliczony (wiersz jest wypelniony "2")
//jezeli przedmiot jest zdany zwraca true
    for(int j=0; j<6; ++j){
        if(tab[x][j] != 2)
            return false;
    }
    return true;
}

void zaliczPrzedmioty(int liczbaPrzedmiotow){
    for(int i=0; i<liczbaPrzedmiotow; ++i){
        if(tab[i][0] == 2){
            //sprawdz poprzednikow, w tym miejscu zaczniemy uzupelniac tabele z czasem rozpoczecia i zakonczenia przedmiotu
            sprawdzPoprzednikow(liczbaPrzedmiotow,i);
            //wypelnij dwojkami cala tablice
            for(int j=1; j<liczbaPrzedmiotow; ++j){
                tab[i][j] = 2;
            }
        }
    }
}

void zaznaczPrzedmiot(int i){
    tab[i][0] = 2;
}

void sprawdzPoprzednikow(int liczbaPrzedmiotow,int x){
//ta funkcja dostaje indeks przedmiotu, sprawdza jego poprzednikow i uzupelnia tabele z datami rozpoczecia i zakonczenia przedmiotu
    bool nieMaPoprzednika = true;

    for(int j=0; j<liczbaPrzedmiotow; ++j){
        if(tabRef[x][j] == 1){
            //znalezlismy indeks poprzednika (liczba j)
            nieMaPoprzednika = false;
            int rozpoczecie = tablicaPrzedmiotow[j].dataZakonczenia + 1;
            int zakonczenie = rozpoczecie + tablicaPrzedmiotow[x].dlugoscTrwania - 1;

            //zabezpieczenie, w przypadku gdy przedmiot ma doch poprzednikow, sprawdzamy czy nie jest juz przechowywana wieksza liczba
            if(rozpoczecie > tablicaPrzedmiotow[x].dataRozpoczecia){
                tablicaPrzedmiotow[x].dataRozpoczecia = rozpoczecie;
                tablicaPrzedmiotow[x].dataZakonczenia = zakonczenie;
            }
        }
    }
    if(nieMaPoprzednika){
        tablicaPrzedmiotow[x].dataRozpoczecia = 0;
        tablicaPrzedmiotow[x].dataZakonczenia = tablicaPrzedmiotow[x].dlugoscTrwania - 1;
    }
}

void sprawdzPoprzednikow(int);
void wypiszTerminy(int liczbaPrzedmiotow){
    int maxDate = tablicaPrzedmiotow[0].dataZakonczenia;
    cout << "--------------------------------------\n";
    cout << "|  przedmiot  |  poczatek  |  koniec |\n";
    cout << "--------------------------------------\n";
    for(int i=0; i<liczbaPrzedmiotow; ++i){
        int roz = tablicaPrzedmiotow[i].dataRozpoczecia;
        int zak = tablicaPrzedmiotow[i].dataZakonczenia;
        cout << "|" << tablicaPrzedmiotow[i].skrot << "|" << tabelaWszystkichDat[roz] << "|" << tabelaWszystkichDat[zak] << "|\n";

        //znajdz date zakonczenia (najwyzsza date)
        if(maxDate < tablicaPrzedmiotow[i].dataZakonczenia)
            maxDate = tablicaPrzedmiotow[i].dataZakonczenia;
    }

    cout << "Studia beda trwaly do: " << tabelaWszystkichDat[maxDate] << "\n";
}


void wczytaj(int liczbaPrzedmiotow){
     //funkcja sluzaca do wczytywania danych do struktury
    zerujTablice();
    for(int i=0; i<liczbaPrzedmiotow; ++i){
        cout << "Podaj nazwe przedmiotu nr "<< i << "." << endl;
        string str;
        cin >> tablicaPrzedmiotow[i].nazwa;
        cout << "Podaj skrot przedmiotu nr "<< i << "." << endl;
        cin >> tablicaPrzedmiotow[i].skrot;
        cout << "Podaj liczbe dni realizacji przedmiotu nr "<< i << "." << endl;
        cin >> tablicaPrzedmiotow[i].dlugoscTrwania;

        while(tablicaPrzedmiotow[i].dlugoscTrwania>15 or tablicaPrzedmiotow[i].dlugoscTrwania<=0){
            //wymog spelnienia warunku max 15 dni na przedmiot
            cout << "Zla wartosc podaj poprawna z przedzialu [1;15]: "<<endl;
            cin >> tablicaPrzedmiotow[i].dlugoscTrwania;
        }

            //dodanie zaleznosci
        cout<<"Jesli przedmiot "<<tablicaPrzedmiotow[i].nazwa<<" nie ma przedmiotu poprzedniego wpisz 1"<<endl;
        cout<<"Jesli przedmiot "<<tablicaPrzedmiotow[i].nazwa<<" ma jeden przedmiot poprzedni wpisz 2"<<endl;
        cout<<"Jesli przedmiot "<<tablicaPrzedmiotow[i].nazwa<<" ma dwa przedmioty poprzednie wpisz 3"<<endl;

        int wybor;
        cin >> wybor;

        while(wybor<1 or wybor>3){
            cout<<"Podano zla wartosc wprowadz jeszcze raz:"<<endl;
            cin>>wybor;
        }
        if(wybor == 1) continue;
        else if(wybor == 2){
            int n;
            cout << "Podaj dla przedmiotu " << tablicaPrzedmiotow[i].nazwa << " numer przedmiotu ktory ma byc poprzednikiem: " << endl;
            cin >> n;
            tab[i][n] = 1;
            tabRef[i][n] = 1;
        }
        else{
            //dwie zaleznosci
            cout << "Podaj dla przedmiotu " << tablicaPrzedmiotow[i].nazwa << " numer pierwszego przedmiotu ktory ma byc poprzednikiem: " << endl;
            int n;
            cin >> n;
            tab[i][n] = 1;
            tabRef[i][n] = 1;
            cout << "Podaj dla przedmiotu " << tablicaPrzedmiotow[i].nazwa << " numer drugiego przedmiotu ktory ma byc poprzednikiem: " << endl;
            cin >> n;
            tab[i][n] = 1;
            tabRef[i][n] = 1;
        }
    }
}

void zerujTablice(){
    for(int i=0; i<var; ++i)
        for(int j=0; j<var; ++j){
            tab[i][j] = 0;
            tabRef[i][j] = 0;
        }
}

void wypisz(int liczbaPrzedmiotow){
    cout << "Liczba przedmiotow: " << liczbaPrzedmiotow << "\n\n";
    for(int i=0; i<liczbaPrzedmiotow; i++){
            cout<<"Przedmiot "<<i<<endl;
            cout<<endl;
            cout<<"Nazwa pelna: "<< tablicaPrzedmiotow[i].nazwa<<endl;
            cout<<"Nazwa skrocona: "<< tablicaPrzedmiotow[i].skrot<<endl;
            cout<<"Liczba dni do realizacji: "<< tablicaPrzedmiotow[i].dlugoscTrwania<<endl;
            cout<<endl;
        }
            cout<<"Informacja o przedmiotach: " <<endl;
        cout<<endl;
        cout<<"----------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"|   przedmiot   |   l.dni  |  przedm. poprz."<<endl;
        cout<<endl;
        cout<<"----------------------------------------------------------"<<endl;
        cout<<endl;

    for(int i=0; i<liczbaPrzedmiotow; i++){
        cout <<setw(10)<< tablicaPrzedmiotow[i].skrot <<setw(14)<<tablicaPrzedmiotow[i].dlugoscTrwania<<setw(14);
        bool czyJestZaleznosc = false;
        bool czySaDwieZaleznosci = false;
        int a,b;
        for(int j=0; j<liczbaPrzedmiotow; j++){
            if(tabRef[i][j] == 1 && czyJestZaleznosc == false){
                czyJestZaleznosc = true;
                a = j;
            }else if(tabRef[i][j] == 1 && czyJestZaleznosc == true){
                czySaDwieZaleznosci = true;
                b = j;
            }
        }

        if(!czyJestZaleznosc)
            cout << "brak" << endl;
        else if(czyJestZaleznosc && czySaDwieZaleznosci){
            cout << tablicaPrzedmiotow[a].skrot << "," << tablicaPrzedmiotow[b].skrot << endl;
        }else{
            cout << tablicaPrzedmiotow[a].skrot << endl;
        }
    }
}
