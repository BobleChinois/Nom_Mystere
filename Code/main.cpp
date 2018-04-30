#include <iostream>
//#include "brouillage.h"
#include "verification.h"

using namespace std;

string mot; //mot à découvrir, saisie du P1
string motMystere; //mot saisi par P1 après brouillage
string reponse; //mot saisi par P2, si identique à "mot", alors P2 gagne
bool gagne(false);//P2 a-t-il gagné ?

int main()
{
    cout << "Veuillez saisir un mot :" << endl;
    cin>>mot;
    //motMystere=brouillage(mot);

    do
    {
        //cout<<motMystere<<end;
        cout<<"Quel est le mot à deviner ?"<<endl;
        cin>>reponse;
        gagne=verification(reponse, mot);
    }
    while (gagne=false);

    return 0;
}
