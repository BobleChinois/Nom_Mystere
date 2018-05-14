#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
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
    cout<<"Nombre de joueurs :"<<"1 ou 2 ?"<<endl;
    cin>>nbreJoueurs;

    do {
            switch(nbreJoueurs){
                case 2:{
                    cout << "Veuillez saisir un mot :" << endl;
                    cin>>mot;
                    for (int i(0);i<50;i++)//permet de masquer la saisie du P1
                        {
                            cout<<endl;
                        }
                    break;
                }
                case 1:
                    {
                    srand(time(0));
                    ifstream listeMot("/home/sosthene/Github/Nom_Mystere.git/liste_mots.txt");
                    int taille;
                    listeMot.seekg(0,ios::end);
                    taille=listeMot.tellg();//on calcule la taille totale du fichier en octets
                    if (listeMot)
                    {
                        listeMot.seekg(rand()%taille,ios::beg);
                        getline(listeMot,mot);
                        cout<<mot<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"Impossible d'ouvrir le fichier"<<endl;
                        return 0;
                    }
                    }
                default:{
                    cout<<"Erreur"<<endl;
                    return 0;
                }
            }

    motMystere=brouillage(mot);
    essais=5;

    do
    {
        cout<<"Il vous reste "<<essais<<" essais."<<endl;
        cout<<motMystere<<endl;
        cout<<"Quel est le mot à deviner ?"<<endl;
        cin>>reponse;
        essais--;
        gagne=verification(reponse, mot);
        }
    while (gagne==false && essais>0);

    switch(gagne){
        case true:
            cout<<"Félicitations !"<<endl;
            break;
        case false:
            cout<<"Le mot-mystère était "<<mot<<endl<<"Game over !"<<endl;
            break;
        }

        cout<<"Nouvelle partie ? oui/non"<<endl;
        cin>>ouiNon;
    for (int i(0);i<50;i++)
        {
            cout<<endl;
        }
    }
    while (ouiNon=="oui");

    return 0;
}
