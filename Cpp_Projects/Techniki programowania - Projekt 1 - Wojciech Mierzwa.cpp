#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
//rozmiar tablicy
const int X = 100, Y = 100;

struct City{
    char citySymbol;
    bool visited;
    int x;
    int y;

    bool neighbourUP;
    bool neighbourLEFT;
    bool neighbourRIGHT;
    bool neighbourDOWN;

    bool pipeUP;
    bool pipeLEFT;
    bool pipeRIGHT;
    bool pipeDOWN;
};

struct Node{
    City* current;
    Node* next;
    Node* prev;
};
Node* head = NULL;

City cities[X][Y];

//deklaracje funkcji
char generateCitySign();
void randomizeNeighboours(int, int);
int BFS(int, int);

//printing
void printCities(int, int);
void printPiping(int,int);
void printMap(int, int);

//queue
void insertToQueue(City*);
City* getFromQueue();
bool removeFromQueue();

int main()
{
    srand(time(NULL));
    cout << "Podaj ilosc miast na osi X i ilosc miast na osi Y!" << endl;
    int x, y;
    cin >> x >> y;

    randomizeNeighboours(x,y);
    cout << "Oto wygenerowana mapa miast i drog\n" << endl;
    printMap(x,y);

    if(BFS(x,y) == (x * y)){
        cout << "Siec jest spojna" << endl;
        cout << "Oto mapa wodociagu:" << endl;
        printPiping(x,y);

    }else{
        cout << "Siec nie jest spojna\n";
    }

    return 0;
}

char generateCitySign(){
    char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','E','S','T','U','V','W','X','Y','Z'};
    return letters[rand()%26];
}

void printMap(int x, int y){
    for(int i=0; i<x; ++i){
        for(int j=0; j<y; ++j){
            if(cities[i][j].neighbourRIGHT == true){
                cout << left << setw(5) << std::setfill('-')<< cities[i][j].citySymbol;
            }
            else{
                cout << left << setw(5) << std::setfill(' ')<< cities[i][j].citySymbol;
            }
        }
        cout << endl;
        for(int k=0; k<4; ++k){
            for(int j=0; j<y; ++j){
                if(cities[i][j].neighbourDOWN == true){
                    cout << "|"<<"    ";
                }
                else
                    cout << "     ";
            }
        cout << endl;
        }
    }
}

void printPiping(int x, int y){
    for(int i=0; i<x; ++i){
        for(int j=0; j<y; ++j){
            if(cities[i][j].pipeRIGHT == true){
                cout << left << setw(5) << std::setfill('=')<< cities[i][j].citySymbol;
            }
            else{
                cout << left << setw(5) << std::setfill(' ')<< cities[i][j].citySymbol;
            }
        }
        cout << endl;
        for(int k=0; k<4; ++k){
            for(int j=0; j<y; ++j){
                if(cities[i][j].pipeDOWN == true){
                    //cout << "||"<<"   ";
                    cout << left << setw(5) << std::setfill(' ')<< "||";
                }
                else
                   cout << left << setw(5) << std::setfill(' ');
            }
        cout << endl;
        }
    }
}

void randomizeNeighboours(int x, int y){
    int probablity = 3;
    for(int i=0; i<x; ++i){
        for(int j=0; j<y; ++j){
            cities[i][j].citySymbol = generateCitySign();
            cities[i][j].x = i;
            cities[i][j].y = j;
            if(j == (y-1) && !(i == (x-1))){
                cities[i][j].neighbourDOWN = rand()%probablity;
                cities[i+1][j].neighbourUP = cities[i][j].neighbourDOWN;
            }else if(i == (x-1) && !(j == (y-1))){
                cities[i][j].neighbourRIGHT = rand()%probablity;
                cities[i][j+1].neighbourLEFT = cities[i][j].neighbourRIGHT;
            }
            else if(j == (y-1) && i == (x-1)){
                //do nothing
            }
            else{
                cities[i][j].neighbourRIGHT = rand()%probablity;
                cities[i][j+1].neighbourLEFT = cities[i][j].neighbourRIGHT;
                cities[i][j].neighbourDOWN = rand()%probablity;
                cities[i+1][j].neighbourUP = cities[i][j].neighbourDOWN;
            }
        }
    }
}

void printCities(int x, int y){
    for(int i=0; i<x; ++i){
        for(int j=0; j<y; ++j){
            std::cout << cities[i][j].citySymbol;
            std::cout << ", UP: " <<cities[i][j].neighbourUP;
            std::cout << ", DOWN: " <<cities[i][j].neighbourDOWN;
            std::cout << ", RIGHT: " <<cities[i][j].neighbourRIGHT;
            std::cout << ", LEFT: " <<cities[i][j].neighbourLEFT << std::endl;
        }
        std::cout<< std::endl;
    }
}

void insertToQueue(City* city){
    if(head == NULL){
        //queue is empty, initialize
        head = new Node;
        head->current = city;
        head->next = NULL;
        head->prev = NULL;
    }else{
        //queue is not empty
        Node* temp = new Node;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
        head->current = city;
    }
}

City* getFromQueue(){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp->current;
}

bool removeFromQueue(){
    //returns true if element was last
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev == NULL){
        //last element in a queue
        delete head;
        return true;
    }else{
        temp->prev->next = NULL;
        delete temp;
        return false;
    }
}

int BFS(int x, int y){
    head = NULL;
    bool finish = false;
    City* currentCity;
    int numberOfVisitedCities = 1;

    int i = 0 , j = 0;
    while(!finish){
        cities[i][j].visited = true;
        //check up
        if(i > 0 && cities[i][j].neighbourUP){
            if(!cities[i-1][j].visited){
                cities[i-1][j].visited = true;
                insertToQueue(&cities[i-1][j]);
                ++numberOfVisitedCities;
				cities[i][j].pipeUP = true;
                cities[i-1][j].pipeDOWN= true;
            }
        }
        //check right
        if(j < y && cities[i][j].neighbourRIGHT){
            if(!cities[i][j+1].visited){
                cities[i][j+1].visited = true;
                insertToQueue(&cities[i][j+1]);
                ++numberOfVisitedCities;
                cities[i][j].pipeRIGHT = true;
                cities[i][j+1].pipeLEFT = true;
            }
        }
        //check down
        if(i < x && cities[i][j].neighbourDOWN){
            if(!cities[i+1][j].visited){
                cities[i+1][j].visited = true;
                insertToQueue(&cities[i+1][j]);
                ++numberOfVisitedCities;
                cities[i][j].pipeDOWN = true;
                cities[i+1][j].pipeUP = true;
            }
        }
        //check left
        if(j > 0 && cities[i][j].neighbourLEFT){
            if(!cities[i][j-1].visited){
                cities[i][j-1].visited = true;
                insertToQueue(&cities[i][j-1]);
                ++numberOfVisitedCities;
                cities[i][j].pipeLEFT = true;
                cities[i][j-1].pipeRIGHT = true;
            }
        }

        //all children are visited, now we can check children of cities from queue
        if(head != NULL){
            currentCity = getFromQueue();
        }else
            finish = true;
        if(head != NULL && removeFromQueue()){
            head = NULL;
        }
        //set x and y of children to visit

        if(!finish){
            i = currentCity->x;
            j = currentCity->y;
        }
    }
    return numberOfVisitedCities;
}
