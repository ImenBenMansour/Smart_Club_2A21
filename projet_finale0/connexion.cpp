#include "connexion.h"
#include "QSqlDatabase"
connexion::connexion()
{

}

bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("cynda");//inserer nom de l'utilisateur
db.setPassword("cynda");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}





