#ifndef ANIMAL_H
#define ANIMAL_H

#include<QString>

class Animal
{
public:
    Animal();
    Animal(int,int,float,QString,QString,QString,QString);

    int getid_A();
    int getage();
    float getpoid();
    QString getprenom();
    QString getetat();
    QString gettype();
    QString getrace();

    void setid_A(int);
    void setage(int);
    void setpoid(float);
    void setprenom(QString);
    void setetat(QString);
    void settype(QString);
    void setrace(QString);
    bool ajouter();


 private:
int id_A;
int age;
float poid;
QString prenom,etat,type,race;




};

#endif // ANIMAL_H
