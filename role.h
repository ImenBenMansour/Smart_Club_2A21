#ifndef ROLE_H
#define ROLE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class role
{


    QString nom;
    QString description;

    int nb_employes;

public:
    role();

    role(QString,QString,int);
    QString getNom(){return nom;}
    QString getDescription(){return description;}

    int getnb_employes(){return nb_employes;}



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool update(QString,QString,int);


};

#endif // ROLE_H
