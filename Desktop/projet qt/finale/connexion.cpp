#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("PROJET_2A");
db.setUserName("maryem");//inserer nom de l'utilisateur
db.setPassword("turki");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;






    return  test;
}
