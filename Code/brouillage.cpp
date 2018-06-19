#include "brouillage.h"

using namespace std;

string brouillage(string mot)
{
    srand(time(0));//initialisation du générateur de nombre aléatoire
    string enigme("");//déclaration de la variable retournée par la fonction
    int lettre;//position de la lettre dans le mot à brouiller

    while (mot.size() != 0)//tant qu'il reste des lettres dans le mot d'origine
    {
        lettre = rand()%mot.size();//on sélectionne une lettre au hasard
        enigme += mot[lettre];//on ajoute cette lettre au mot à renvoyer par la fonction
        mot.erase(lettre,1);//on efface la lettre que l'on vient d'ajouter pour éviter de l'utiliser à nouveau
    }

    return enigme;
}
