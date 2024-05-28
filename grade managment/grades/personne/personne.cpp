#include "personne.h"

personne::personne() {}
personne::personne(int id, string nom, string prenom, string mail)
    : Nom(nom), Prenom(prenom), Mail(mail), ID(id) {}
