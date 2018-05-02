#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string brouillage(string mot)
{
    srand(time(0));
    string enigme("");
    int lettre;

    while (mot.size()!=0)
    {
        lettre=rand()%mot.size();
        enigme+=mot[lettre];
        mot.erase(lettre,1);
    }

    return enigme;
}
