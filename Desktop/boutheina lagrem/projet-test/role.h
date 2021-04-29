#ifndef ROLE_H
#define ROLE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class role
{


    QString nom;
    int reference;

    int nb_employes;

public:
    role();

    role(QString,int,int);
    QString getNom(){return nom;}
    int getReference(){return reference;}

    int getnb_employes(){return nb_employes;}



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update(QString,int,int);


};

#endif // ROLE_H
