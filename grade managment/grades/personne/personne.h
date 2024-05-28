#ifndef PERSONNE_H
#define PERSONNE_H
#include <QWidget>
#include <string>
using namespace std;
class personne
{
protected:

    string Nom;
    string Prenom;
    string Mail;
private:
    int ID;

public:
    personne();
    personne(int ,  string,  string,  string);
};

#endif // PERSONNE_H
