#include <fstream>
#include "brouillage.h"
#include "rafraichissement.h"

using namespace std;

int nbreJoueurs(1);
string mot; //mot à découvrir, saisie du P1 ou sélectionné au hasard dans une liste
string motMystere; //mot saisi par P1 après brouillage
string reponse; //mot saisi par P2, si identique à "mot", alors P2 gagne
bool gagne(false);//P2 a-t-il gagné ?
int essais(5);//P2 n'a que 5 essais pour deviner le mot
string ouiNon;//P2 choisit de jouer à nouveau ou non

int main()
{
    do //boucle qui permet de refaire une partie
    {
        cout << "Nombre de joueurs :" << "1 ou 2 ?" << endl;
        cin >> nbreJoueurs;

        switch(nbreJoueurs)
        {
            case 2:
            {
                cout << "Veuillez saisir un mot :" << endl;
                cin >> mot;
                rafraichissement();
                break;
            }
            case 1:
            {
                srand(time(0));
                ifstream listeMot("../dico.txt");
                int taille;
                char lettre;

                listeMot.seekg(0,ios::end);//on déplace le curseur à la fin du fichier
                taille=listeMot.tellg();//on enregistre le nombre total de caractères du fichier

                if (listeMot)//on ouvre le fichier de la liste de mots
                {
                    listeMot.seekg(rand()%taille,ios::beg);//on déplace le curseur sur un emplacement aléatoire en partant du début du fichier
                    listeMot.get(lettre);
                    cout << lettre << endl;

                    if (lettre != '/n')
                    {
                        do
                        {
                            listeMot.unget();
                            listeMot.get(lettre);
                        }
                        while (lettre != '/n');
                    }
                    else
                    {
                        listeMot >> mot;
                    }

                    listeMot >> mot;//on importe le prochain mot de la liste
                }

                else
                {
                    cout<<"Impossible d'ouvrir le fichier"<<endl;
                    return 0;
                }
                break;
            }
            default : //en cas de saisie invalide
            {
                cout<<"Erreur"<<endl;
                return 0;
            }
        }

        motMystere = brouillage(mot);
        essais = 5;

        do //boucle tant que P2 n'a pas trouvé le mot et qu'il n'a pas utilisé tous ses essais
        {
            cout << "Il vous reste " << essais << " essais." << endl;
            cout << motMystere << endl;
            cout << "Quel est ce mot ?" << endl;
            cin >> reponse;
            essais--;
            gagne = reponse == mot;
        }
        while (gagne != true && essais > 0);


        if (gagne == true)
        {
            cout << "Félicitations !" << endl;
        }
        else
        {
            cout << "Le mot-mystère était " << mot << endl << "Game over !" << endl;
        }

        cout << "Nouvelle partie ? OUI/NON" << endl;
        cin >> ouiNon;//case sensitive, à améliorer ?
        rafraichissement();
    }
    while (ouiNon == "OUI");//condition du 1er do

    return 0;
}
