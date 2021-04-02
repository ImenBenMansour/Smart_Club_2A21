#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"evenements.h"
#include"stat.h"

#include<QMessageBox>
#include"sponsor.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(157,0,79);");

    ui->lineEdit_id->setPlaceholderText("id ...");
    ui->lineEdit_idp->setPlaceholderText("id ...");
    ui->lineEdit_nom->setPlaceholderText("nom ...");
    ui->lineEdit_nomp->setPlaceholderText(" prenom...");

    ui->lineEdit_prenomp->setPlaceholderText(" prenom...");
    ui->lineEdit_numerop->setPlaceholderText(" numero...");
    ui->lineEdit_lieu->setPlaceholderText("lieu...");
     ui->tableView_4->setModel(tmpevenements.afficher());
     ui->tableView_3->setModel(tmpparticpant.afficher());
    ui->lineEdit_id->setMaxLength(8);
     ui->lineEdit_idp->setMaxLength(8);
     ui->lineEdit_numerop->setMaxLength(8);
     ui->lineEdit_nomp->setMaxLength(10);
     ui->lineEdit_prenomp->setMaxLength(10);
     ui->lineEdit_lieu->setMaxLength(8);
     ui->lineEdit_id->setStyleSheet("QLineEdit { color: red;}");
     ui->lineEdit_nom->setStyleSheet("QLineEdit { color: blue;}");
     ui->lineEdit_nomp->setStyleSheet("QLineEdit { color: blue;}");
     ui->lineEdit_prenomp->setStyleSheet("QLineEdit { color: blue;}");
     ui->lineEdit_numerop->setStyleSheet("QLineEdit { color: blue;}");
     ui->lineEdit_lieu->setStyleSheet("QLineEdit { color: blue;}");
     ui->dateEdit_Event->setStyleSheet("QDateEdit { color: blue;}");
     ui->lineEdit_offre->setStyleSheet("QDateEdit { color: blue;}");
     ui->lineEdit_idp->setStyleSheet("QLineEdit { color: red;}");
     ui->comboBox->setStyleSheet("QComboBox { color: blue;}");
     ui->comboBox_2->setModel(tmpparticpant.affichercid());

















}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_quitter_clicked()
{
    int id= ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QDate dateEvent= ui->dateEdit_Event->date();
    QString lieu= ui->lineEdit_lieu->text();

    QString type= ui->comboBox->currentText();


    QString msg_nom ="impossible";





    evenements e(id,nom,type,lieu,dateEvent);

    ui->lineEdit_id->setText("");
    ui->lineEdit_nom->setText("");
    ui->lineEdit_lieu->setText("");

    if(nom.size()>13)
    {
         ui->lineEdit_nom->setText( msg_nom);

            QMessageBox::information(nullptr, QObject::tr("ajout evenement"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    else
{
        e.ajouter();
        ui->tableView_4->setModel(tmpevenements.afficher());

        QMessageBox::information(nullptr, QObject::tr("ajout evenement"),
                              QObject::tr("ajout ressuie.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);}





}




void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QDate dateEvent= ui->dateEdit_Event->date();
    QString lieu= ui->lineEdit_lieu->text();

    QString type= ui->comboBox->currentText();


    bool test=tmpevenements.supprimer(id);
    evenements e(id,nom,type,lieu,dateEvent);


    if(test)
    {     ui->tableView_4->setModel(tmpevenements.afficher());

        QMessageBox::information(nullptr, QObject::tr("supprimer evenement"),
                              QObject::tr("supp ressuie.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                {  QMessageBox::information(nullptr, QObject::tr("supprimer evenement"),
                              QObject::tr("supp echouèe.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
}











void MainWindow::on_pushButton_6_clicked()
{
    evenements e;
     e.CREATION_PDF();
}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    evenements e;
    ui->tableViewRECH->setModel(e.chercher(ui->lineEdit_6->text()));
}

void MainWindow::on_pushButton_12_clicked()
{
    int id= ui->lineEdit_idp->text().toInt();
    QString nom= ui->lineEdit_nomp->text();
    QString prenom= ui->lineEdit_prenomp->text();

    QString offre= ui->lineEdit_offre->text();
    int numero= ui->lineEdit_numerop->text().toInt();


    ui->lineEdit_idp->setText("");
    ui->lineEdit_nomp->setText("");
    ui->lineEdit_prenomp->setText("");
    ui->lineEdit_numerop->setText("");

    participant p(id,nom,prenom,offre,numero);
    bool test=p.ajouter();
    if(test)
    {ui->tableView_3->setModel(tmpparticpant.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout sponsor"),
                              QObject::tr("ajout reussi.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                 { QMessageBox::information(nullptr, QObject::tr(" ajout sponsor "),
                              QObject::tr("ajout echouèe.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_13_clicked()
{
    int id=ui->lineEdit_idp->text().toInt();
    QString nom= ui->lineEdit_nomp->text();
    QString prenom= ui->lineEdit_prenomp->text();

    QString offre= ui->lineEdit_offre->text();
    int numero= ui->lineEdit_numerop->text().toInt();
    participant p(id,nom,prenom,offre,numero);

    bool test=tmpparticpant.supprimer(id);

    if(test)
    {             ui->tableView_3->setModel(tmpparticpant.afficher());

        QMessageBox::information(nullptr, QObject::tr("supprimer sponsor"),
                              QObject::tr("supp ressuie.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                {  QMessageBox::information(nullptr, QObject::tr("supprimer sponsor"),
                              QObject::tr("supp echouèe.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_15_clicked()
{
    int id= ui->lineEdit_idp->text().toInt();

        QString nom=ui->lineEdit_nomp->text();
            QString prenom=ui->lineEdit_prenomp->text();

             QString offre=ui->lineEdit_offre->text();
                       int numero= ui->lineEdit_numerop->text().toInt();
                       participant p(id,nom,prenom,offre,numero);
                       ui->lineEdit_idp->setText("");
                       ui->lineEdit_nomp->setText("");
                       ui->lineEdit_prenomp->setText("");
                       ui->lineEdit_numerop->setText("");


            bool test = tmpparticpant.update(id,nom,prenom,offre,numero);


            if(test)

            {
                 ui->tableView_3->setModel(tmpparticpant.afficher());
                QMessageBox::information(nullptr, QObject::tr("update "),
                            QObject::tr("Participant modifie\n"
            "Click Cancel to exit."), QMessageBox::Cancel);}

}






void MainWindow::on_pushButton_modif_clicked()
{
    int id= ui->lineEdit_id->text().toInt();

        QString nom=ui->lineEdit_nom->text();

             QDate dateEvent=ui->dateEdit_Event->date();
             QString lieu=ui->lineEdit_lieu->text();

             QString type= ui->comboBox->currentText();


             evenements e(id,nom,type,lieu,dateEvent);
             ui->lineEdit_id->setText("");
             ui->lineEdit_nom->setText("");
             ui->lineEdit_lieu->setText("");



            bool test = tmpevenements.update(id,nom,dateEvent,lieu,type);


            if(test)

            {
                 ui->tableView_4->setModel(tmpevenements.afficher());
                QMessageBox::information(nullptr, QObject::tr("update "),
                            QObject::tr("evenement modifie\n"
            "Click Cancel to exit."), QMessageBox::Cancel);}
            else
              {  QMessageBox::information(nullptr, QObject::tr("modifier participant"),
                            QObject::tr("modifier echouèe.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}
}







void MainWindow::on_radioButton_clicked()
{
    QMessageBox msgBox ;
    QSqlQueryModel * model= new QSqlQueryModel();



       model->setQuery("select * from participant order by nom");

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("offre"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
                ui->tableView->setModel(model);
                ui->tableView->show();
                msgBox.setText("Tri avec succés.");
                msgBox.exec();
}



void MainWindow::on_radioButton_2_clicked()
{
    {QMessageBox msgBox ;
        QSqlQueryModel * model= new QSqlQueryModel();


           model->setQuery("select * from participant order by CAST(id as INT) desc");

           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("offre"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
                    ui->tableView->setModel(model);
                    ui->tableView->show();
                    msgBox.setText("Tri avec succés.");
                    msgBox.exec();

    }
}

void MainWindow::on_radioButton_3_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();


               model->setQuery("select * from participant order  by CAST(numero as INT) asc");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("offre"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
                        ui->tableView->setModel(model);
                        ui->tableView->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();

}







void MainWindow::on_pushButton_clicked()
{
    Stat *w = new Stat();
    w->make();
    w->show();
}



