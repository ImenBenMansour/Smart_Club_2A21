#ifndef EVENEMENTS_H
#define EVENEMENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class evenements
{
    int id;
  QString nom;
  QString type;
  QString lieu;
  QDate dateEvent;
public:
    evenements();
    evenements(int, QString ,QString ,QString ,QDate);
    bool supprimer(int );


    bool ajouter();

    int getId(){return id;}


    QString getNom(){return nom;}


    QString getType(){return type;}


    QString getLieu(){return lieu;};


    QDate getDate(){return dateEvent;};

        QSqlQueryModel * afficher();
        void CREATION_PDF();
       QSqlQueryModel * chercher(QString rech);
        bool update (int, QString ,QDate,QString,QString);


};

#endif // EVENEMENTS_H
