#include "animal.h"
#include <QSqlQuery>
#include<QtDebug>
Animal::Animal()
{
id_A=0; age=0; poid=0; prenom=""; etat=""; type=""; race="";

}


Animal::Animal(int id_A,int age,float poid,QString prenom,QString etat ,QString type ,QString race)
{
    this->id_A=id_A;
    this->age=age;
    this->poid=poid;
    this->prenom=prenom;
    this->etat=etat;
    this->type=type;
    this->race=race;

}
int Animal::getid_A(){ return id_A;}
int Animal::getage(){return age;}
float Animal::getpoid(){return poid;}
QString Animal::getprenom(){return prenom;}
QString Animal:: getetat(){return etat;}
QString Animal:: gettype(){return type;}
QString Animal:: getrace(){return race;}


void Animal::setid_A(int id_A){this->id_A=id_A;}
void Animal::setage(int age){this->age=age;}
void Animal::setpoid(float poid){this->poid=poid;}
void Animal::setprenom(QString prenom){this->prenom=prenom;}
void Animal::setetat(QString etat){this->etat=etat;}
void Animal::settype(QString type){this->type=type;}
void Animal::setrace(QString race){this->race=race;}

bool Animal::ajouter()
{bool test=false;
    QString id_string=QString::number(id_A);
    QString age_string=QString::number(age);

    QSqlQuery query;
          query.prepare("INSERT INTO animal (id_A,type,race,prenom,etat,age,poid) "
                        "VALUES (:id_A, :type, :race,:prenom,:etat,:age,:poid)");

          query.bindValue(":id_A", id_string);
          query.bindValue(":type", type);
          query.bindValue(":race", race);
          query.bindValue(":prenom", prenom);
          query.bindValue(":etat", etat);
          query.bindValue(":age", age_string);
          query.bindValue(":poid", poid);

          query.exec();



return test;}


