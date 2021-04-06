#include "connexion.h"
#include "QSqlDatabase"
connexion::connexion()
{

}

bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("boutheina");//inserer nom de l'utilisateur
db.setPassword("boutheina");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
