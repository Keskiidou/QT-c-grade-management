
#include "etudiant/etudiant.h"
#include"enseignant/enseignant.h"
#include "matiere/matiere.h"
#include "groupe/groupe.h"
#include "groupemodule/groupemodule.h"
#include "note/note.h"
#include "mainwindow/mainwindow.h"
#include <QApplication>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    etudiant w;
    enseignant e;
    matiere m;
    groupemodule g;
    Groupe GRP;
    Note N;
    mainwindow main;
    main.show();
    enseignant ens(1, "bachir", "boubou", "bachir@gmail.com");
    // etudiant etudiant1( "yassine", "mhirsi", "yassine@gmail.com", 21318);

    etudiant* etudiant1 = new etudiant( "yassine", "mhirsi", "yassine@gmail.com", 21318);
    etudiant* etudiant2 = new etudiant( "ahmed", "benazzouz", "ahmed@gmail.com",21399 );
    vector<etudiant*> listeEtudiants;
    listeEtudiants.push_back(etudiant1);
    listeEtudiants.push_back(etudiant2);

    matiere* mat1 = new matiere("1", "Java", 3, &ens);
    matiere* mat2 = new matiere("2", "C++", 3, &ens);
    cout<<mat2;
    vector<matiere*> listeMat;
    listeMat.push_back(mat1);
    listeMat.push_back(mat2);
    groupemodule* gm1 = new groupemodule("GM1", "Info", 6,&listeMat);
    cout<<*gm1;
    vector<groupemodule*> listegm;
    listegm.push_back(gm1);
    Groupe grp("G1", "1ere", "ING", "INF", 2, &listegm, &listeEtudiants);
    cout<<grp;
    Note n1(mat1,etudiant1,14,"TP");
    cout << n1;
    return a.exec();
}


