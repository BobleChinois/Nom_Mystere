#include <iostream>
#include "motMystere.h"
#include "verification.h"

using namespace std;

int main()
{
    string mot;
    string reponse;
    cout << "Veuillez saisir un mot :" << endl;
    cin>>mot;
    //string motMystere(mot);

    do
    {
        //cout<<motMystere<<end;
        cin>>reponse;
        bool verification(reponse, mot);
    }
    while (verification=false);
    return 0;
}
