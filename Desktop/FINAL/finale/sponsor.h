#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class participant
{
    int id;
  QString nom;
  QString prenom;
  int numero;
  QString offre;
public:
    participant();
    participant(int , QString ,QString ,QString,int);
   // bool supprimer(int );
    bool supprimer(int );



    bool ajouter();

    int getId(){return id;}


    QString getNom(){return nom;}


    QString getprenom(){return prenom;}


   int getnumero(){return numero;}


    QString getOffre(){return offre;}

        QSqlQueryModel * afficher();
        bool update(int , QString ,QString ,QString ,int );
        QSqlQueryModel* affichercid();

};

#endif // PARTICIPANT_H
