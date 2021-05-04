#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQueryModel>



class Abonne
{
public:
    Abonne();
    Abonne(int,QString,QString,int,int,QString);
        int getid_ab();
        QString getnom();
        QString getprenom();
        int getpayemet();
        int getnbr_chats();
        QString getsexe();

        void setid_ab(int);
        void setnom(QString);
        void setprenom(QString);
        void setpayement(int);
        void setnbr_chats(int);
        void setsexe(QString);
        bool ajouter();
      QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(const QString &aux);
      bool update(int , QString ,QString ,int ,int, QString );
      bool supprimer(int);

    private:
        int id_ab,payement,nbr_chats;
        QString nom,prenom,sexe;
};
class projeth
{
public:
       projeth() ;
       projeth(QString,QString,QString) ;
       QString get_nom();
       QString get_datee();
       QString get_fn();
       QSqlQueryModel * afficherhis() ;
       bool ajoutehis();
       bool modifierhis() ;
private:

    QString nom,datee,fn ;
};
#endif // ETUDIANT_H
