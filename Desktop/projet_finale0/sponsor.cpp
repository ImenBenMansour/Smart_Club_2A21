#include "sponsor.h"

participant::participant()
{

}
participant::participant(int id, QString nom,QString prenom,QString offre,int numero)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
     this->offre=offre;
    this->numero=numero;

}

bool participant::supprimer(int id)
{
QSqlQuery query;
query.prepare("DELETE FROM participant WHERE id = :id");
query.bindValue(":id", id);
return    query.exec();
}



bool participant::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO participant (id,nom, prenom, offre,numero ) "
                        "VALUES (:id, :nom,:prenom, :offre, :numero)");
    query.bindValue(":id",id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    query.bindValue(":offre", offre);
    query.bindValue(":numero",numero );


    return    query.exec();

}
QSqlQueryModel * participant::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from participant");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("offre"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
return model;
}
bool participant::update(int id, QString nom,QString prenom,QString offre,int numero)
{
    QSqlQuery query;
    query.prepare("UPDATE participant SET id= :id,nom= :nom,prenom=:prenom,offre= :offre,numero=:numero WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom",nom );
    query.bindValue(":prenom", prenom);
    query.bindValue(":offre", offre);
    query.bindValue(":numero", numero);

    return    query.exec();
}
QSqlQueryModel* participant::affichercid()
{
    QSqlQuery query;
    query.prepare("SELECT id FROM participant"); //remplir le combo Box
    QSqlQueryModel *modal=new QSqlQueryModel();
    query.exec();
    modal->setQuery(query);
    return modal;
}

