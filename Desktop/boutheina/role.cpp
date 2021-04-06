#include "role.h"
#include "QDebug"
#include <QFileDialog>
#include <QString>


role::role()
{

}

role::role(QString nom, int reference,int nb_employes)
{
this->nom=nom;
this->reference=reference;
this->nb_employes=nb_employes;


}




bool role::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO roles (nom, reference, nb_employes)"
                  "VALUES (:nom, :reference, :nb_employes)");
    query.bindValue(":nom",nom);
    query.bindValue(":reference",reference);

    query.bindValue(":nb_employes",nb_employes);




    return query.exec();


}



QSqlQueryModel * role::afficher()
{
QSqlQueryModel * model = new QSqlQueryModel();

model->setQuery("select *from roles");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nb_employes"));


    return model;
}





bool role::supprimer(int reference)
{

    QSqlQuery qry;
        QString mat = QString::number(reference);
        qry.prepare("Delete from roles where reference = :reference");
        qry.bindValue(":reference",reference);
        return qry.exec();
}




bool role::update(QString nom, int reference, int nb_employes)
{
    QSqlQuery query;
    query.prepare("UPDATE roles SET  nom= :nom, reference= :reference , nb_employes= :nb_employes WHERE nom = :nom");

    query.bindValue(":nom",nom );
    query.bindValue(":reference", reference);

    query.bindValue(":nb_employes", nb_employes);



    return    query.exec();
}

