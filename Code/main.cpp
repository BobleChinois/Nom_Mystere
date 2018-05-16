#include <fstream>
#include "brouillage.h"
#include "verification.h"

using namespace std;

int nbreJoueurs(1);
string mot; //mot à découvrir, saisie du P1 ou sélectionner au hasard dans la liste
string motMystere; //mot saisi par P1 après brouillage
string reponse; //mot saisi par P2, si identique à "mot", alors P2 gagne
bool gagne(false);//P2 a-t-il gagné ?
int essais(5);//P2 n'a que 5 essais pour deviner le mot
string ouiNon;//P2 choisit de jouer à nouveau ou non

int main()
{
    do {//boucle permet de refaire une partie
            cout<<"Nombre de joueurs :"<<"1 ou 2 ?"<<endl;
            cin>>nbreJoueurs;
            switch(nbreJoueurs){
                case 2:{
                    cout << "Veuillez saisir un mot :" << endl;
                    cin>>mot;
                    for (int i(0);i<50;i++)//permet de masquer la saisie du P1
                        {
                            cout<<endl;
                        }
                    break;}
                case 1:{
                    srand(time(0));
                    ifstream listeMot("/home/sosthene/Github/Nom_Mystere.git/dico.txt");
                    int taille;
                    listeMot.seekg(0,ios::end);//on déplace le curseur à la fin du fichier
                    taille=listeMot.tellg();//on enregistre le nombre total de caractère du fichier
                    if (listeMot)//on ouvre le fichier de la liste de mots
                    {
                        listeMot.seekg(rand()%taille,ios::beg);//on déplace le curseur sur un emplace aléatoire en partant du début du fichier
                        listeMot>>mot;//on importe un premier mot
                        listeMot>>mot;//puis un 2eme pour être sûr de ne pas avoir un mot coupé en 2
                        break;
                    }
                    else
                    {
                        cout<<"Impossible d'ouvrir le fichier"<<endl;
                        return 0;
                    }
                    }
                default:{//en cas de saisie invalide
                    cout<<"Erreur"<<endl;
                    return 0;
                }
            }

    motMystere=brouillage(mot);
    essais=5;

    do//boucle tant que P2 n'a pas trouvé le mot et qu'il n'a pas utilisé tous ses essais
    {
        cout<<"Il vous reste "<<essais<<" essais."<<endl;
        cout<<motMystere<<endl;
        cout<<"Quel est ce mot ?"<<endl;
        cin>>reponse;
        essais--;
        gagne=verification(reponse, mot);
        }
    while (gagne!=true && essais>0);

    switch(gagne){
        case true:
            cout<<"Félicitations !"<<endl;
            break;
        case false:
            cout<<"Le mot-mystère était "<<mot<<endl<<"Game over !"<<endl;
            break;
        }

        cout<<"Nouvelle partie ? oui/non"<<endl;
        cin>>ouiNon;//case sensitive, à améliorer ?
    for (int i(0);i<50;i++)//permet de retrouver un écran vierge
        {
            cout<<endl;
        }
    }
    while (ouiNon=="oui");//condition du 1er do

    return 0;
}
