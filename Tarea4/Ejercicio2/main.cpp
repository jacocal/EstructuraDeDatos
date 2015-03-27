#include<iostream>
#include<string.h>
#include"Node.h"
#include"CircularLinkedList.h"


using namespace std;
using namespace vcn;

void print(CircularLinkedList<bool>* , string);


int main()
{
    CircularLinkedList<bool> * team = new CircularLinkedList<bool>();
    int numTeam = 0;
    cout << "Numero de equipos: ";
    cin >> numteam;
    for (int i = 0; i < numteam-1; i++){
        team->LinkedList::insert(false,0);
    }
    team->LinkedList::insert(true,0);

    cout << "Configuracion inicial" << endl;
    print(team,"t");
    Node<bool> * node = team->at(true);
    int pos = team->LinkedList::at(node)-1;


    int first,last;
    cin >> first;
    cin >> last;
    first--;
    last--;

    cout << endl;
    for (int i = 0; i < team->size(); i++)
        cout << i+1 << " ";
    cout << endl;

    print(team,"t");
    while (pos%team->size() != ini){
        team->at(pos%team->size())->setInfo(false);
        team->at((pos+1)%team->size())->setInfo(true);
        print(team,"t");
        pos++;
    }

    print(team,">");
    while (pos%team->size() != fin){
        team->at(pos%team->size())->setInfo(false);
        team->at((pos+1)%team->size())->setInfo(true);
        print(team,">");
        pos++;
    }

    return 0;

}


void print(CircularLinkedList<bool>* team, string txt)
{
    for (int i = 0; i < team->size(); i++)
        if (team->at(i)->getInfo())
            cout << txt << " ";
        else
            cout << "." <<  " ";
    cout << endl << endl;

}
