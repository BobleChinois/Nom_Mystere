#include <iostream>
#include <string>
#include "brouillage.h"
#include "verification.h"

using namespace std;

string mot; //mot à découvrir, saisie du P1
string motMystere; //mot saisi par P1 après brouillage
string reponse; //mot saisi par P2, si identique à "mot", alors P2 gagne
bool gagne(false);//P2 a-t-il gagné ?
char ouiNon;
bool nllePartie;

int main()
{
    cout << "Veuillez saisir un mot :" << endl;
    cin>>mot;
    for (int i(0);i<50;i++)
    {
        cout<<endl;
    }
    motMystere=brouillage(mot);

    do
    {
        cout<<motMystere<<endl;
        cout<<"Quel est le mot à deviner ?"<<endl;
        cin>>reponse;
        gagne=verification(reponse, mot);
    }
    while (gagne!=true);

    return 0;
}
