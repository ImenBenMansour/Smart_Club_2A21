#include "role.h"
#include "QDebug"
#include <QFileDialog>
#include <QString>


role::role()
{

}

role::role(QString description, QString nom,int nb_employes)
{

this->description=description;
this->nom=nom;
this->nb_employes=nb_employes;


}




bool role::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO departements (description, nom, nb_employes)"
                  "VALUES (:description, :nom, :nb_employes)");
    query.bindValue(":description",description);
    query.bindValue(":nom",nom);
    query.bindValue(":nb_employes",nb_employes);




    return query.exec();


}



QSqlQueryModel * role::afficher()
{
QSqlQueryModel * model = new QSqlQueryModel();

model->setQuery("select *from departements");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("description"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_employes"));


    return model;
}





bool role::supprimer(QString description)
{

    QSqlQuery qry;
        //QString mat = QString::number(nom);
        qry.prepare("Delete from departements where description = :description");
        qry.bindValue(":description",description);
        return qry.exec();
}




bool role::update(  QString nom, QString description,int nb_employes)
{
    QSqlQuery query;
    query.prepare("UPDATE departements SET  nom= :nom, description= :description , nb_employes= :nb_employes WHERE nom = :nom");

    query.bindValue(":nom",nom );
    query.bindValue(":description", description);

    query.bindValue(":nb_employes", nb_employes);



    return    query.exec();
}

