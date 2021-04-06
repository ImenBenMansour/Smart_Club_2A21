#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>


class connexion
{
      QSqlDatabase db;
public:
    connexion();

    bool createconnection();
};

#endif // CONNEXION_H
