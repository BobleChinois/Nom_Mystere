#include <iostream>

using namespace std;

bool verification(string reponse, string const& mot)
{
    if (reponse==mot)
    {
        cout<<"Bravo !"<<endl;
        return true;
    }
    else
    {
        cout<<"Faux !"<<endl;
        return false;
    }
}
