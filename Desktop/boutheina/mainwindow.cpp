#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnel.h"
#include "role.h"

#include "stat.h"
#include <QMessageBox>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cin_regex=QRegExp("[0-9]{4}$");// controle saisie


    ui->tableViewD->setModel(tmprole.afficher());
    ui->tableView_3->setModel(tmppersonnel.afficher());
    ui->lineEditcin->setPlaceholderText("CIN...");
    ui->lineEditnom->setPlaceholderText("Nom...");
    ui->lineEditprenom->setPlaceholderText("Prenom...");
    ui->lineEditmobile->setPlaceholderText("Mobile...");

    ui->lineEdit_reference->setPlaceholderText("Reference...");

    ui->lineEdit_nb_employes->setPlaceholderText("Nbr employes...");

    ui->lineEditsalaire->setPlaceholderText("Salaire...");

    ui->lineEditcin->setMaxLength(8);
    ui->lineEditsalaire->setMaxLength(7);
    ui->lineEdit_reference->setMaxLength(10);
    ui->lineEdit_nb_employes->setMaxLength(4);
     this->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->tableView_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_3->setSelectionMode(QAbstractItemView::SingleSelection);

   ui->tableViewD->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewD->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->lineEditcin->setStyleSheet("QLineEdit { color: red;}");

    ui->lineEdit_reference->setStyleSheet("QLineEdit { color: red;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()

    {

            int cin= ui->lineEditcin->text().toInt();
            QString nom= ui->lineEditnom->text();
            QString prenom= ui->lineEditprenom->text();

             QString mobile= ui->lineEditmobile->text();
             QString role=ui->comboBox->currentText();

            QDate date_naissance=ui->dateEditdate_naissance->date();
             int salaire=ui->lineEditsalaire->text().toInt();


            personnel p(cin,nom,prenom,mobile,role,date_naissance,salaire);
            bool cin_verif=cin_regex.exactMatch(ui->lineEditcin->text());


            if((mobile.size()==8)&&(cin_verif))


          {
                p.ajouter();

                ui->tableView_3->setModel(tmppersonnel.afficher());
            QMessageBox::information(nullptr, QObject::tr("ajout personnel"),
                                      QObject::tr("Personnel ajouté.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

                  }
                      else if (!cin_verif)
            {
                QMessageBox::warning(this,"Erreur lors de l'ajout","CIN invalid");
                ui->lineEditcin->setStyleSheet("color: red");
            }
                      else
                          QMessageBox::information(nullptr, QObject::tr("ajout personnel"),
                                      QObject::tr("ajout echoué\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);}




void MainWindow::on_pushButton_4_clicked()
{
    QItemSelectionModel *select = ui->tableView_3->selectionModel();

    int cin =select->selectedRows(0).value(0).data().toInt();

    if(tmppersonnel.supprimer(cin))
    {
        ui->tableView_3->setModel(tmppersonnel.afficher());
        QMessageBox::information(nullptr, QObject::tr("supression"),
                                  QObject::tr("Personnel supprimé\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

              }
                  else
                      QMessageBox::information(nullptr, QObject::tr("supression"),
                                  QObject::tr("Supression echouée\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{         int cin= ui->azzerty->text().toInt();

          QString nom= ui->lineEditnom->text();
          QString prenom= ui->lineEditprenom->text();
          QString mobile= ui->lineEditmobile->text();
                QString role=ui->comboBox->currentText();

          QDate date_naissance=ui->dateEditdate_naissance->date();
           int salaire=ui->lineEditsalaire->text().toInt();
                 personnel p(cin,nom,prenom,mobile,role,date_naissance,salaire);

        bool test = tmppersonnel.update(cin,nom,prenom,mobile,role,date_naissance,salaire);


        if(test)

        {
             ui->tableView_3->setModel(tmppersonnel.afficher());
            QMessageBox::information(nullptr, QObject::tr("update "),
                        QObject::tr("Personnel modifié\n"
        "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("update "),
                        QObject::tr("Personnel non modifié\n"
        "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_10_clicked()
{
    personnel p;
    p.creerpdf();
}



void MainWindow::on_ajouter2_clicked()
{


        QString nom= ui->comboBox_2->currentText();
        int reference= ui->lineEdit_reference->text().toInt();

        int nb_employes= ui->lineEdit_nb_employes->text().toInt();


        role d(nom,reference,nb_employes);
        bool test=d.ajouter();


        if(test)

      {ui->tableViewD->setModel(tmprole.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout rôle"),
                                  QObject::tr("rôle ajouté.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

              }
                  else
                      QMessageBox::information(nullptr, QObject::tr("ajout rôle"),
                                  QObject::tr("ajout echoué.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}




void MainWindow::on_supprimer_role_clicked()

    {
   int reference= ui->lineEdit_reference->text().toInt();
    QString nom= ui->comboBox_2->currentText();

   int nb_employes= ui->lineEdit_nb_employes->text().toInt();



            bool test=tmprole.supprimer(reference);
            role d(nom,reference,nb_employes);
            if(test)
            {             ui->tableViewD->setModel(tmprole.afficher());

                QMessageBox::information(nullptr, QObject::tr("supprimer rôle"),
                                      QObject::tr("supp ressuie.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

                  }
                      else
                        {  QMessageBox::information(nullptr, QObject::tr("supprimer rôle"),
                                      QObject::tr("supp echouèe.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);}
    }





void MainWindow::on_modifier_role_clicked()
{
    {

              QString nom= ui->comboBox_2->currentText();
              int reference= ui->lineEdit_reference->text().toInt();

              int nb_employes = ui->lineEdit_nb_employes->text().toInt();

                     role d(nom,reference,nb_employes);

            bool test = tmprole.update(nom,reference,nb_employes);


            if(test)

            {
                 ui->tableViewD->setModel(tmprole.afficher());
                QMessageBox::information(nullptr, QObject::tr("update "),
                            QObject::tr("rôle modifié\n"
            "Click Cancel to exit."), QMessageBox::Cancel);}
            else
                QMessageBox::critical(nullptr, QObject::tr("update "),
                            QObject::tr("rôle non modifié\n"
            "Click Cancel to exit."), QMessageBox::Cancel);}

    }





void MainWindow::on_radioButton_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from personnel order by CAST(cin as INT) asc");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));

               model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mobile"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("Rôle"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date_naissance"));
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("Salaire"));
                        ui->tableViewT->setModel(model);
                        ui->tableViewT->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();
}



void MainWindow::on_radioButton_salaire_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from personnel order by CAST(salaire as INT) asc");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("mobile"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("role"));

               model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
                        ui->tableViewT->setModel(model);
                        ui->tableViewT->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();
}

void MainWindow::on_radioButton_2_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from personnel order by nom");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("mobile"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("role"));

               model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
                        ui->tableViewT->setModel(model);
                        ui->tableViewT->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEditcin->setText("");
    ui->lineEditnom->setText("");
    ui->lineEditprenom->setText("");
    ui->lineEditsalaire->setText("");
    ui->lineEditmobile->setText("");

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit_reference->setText("");
    ui->lineEdit_nb_employes->setText("");
}










void MainWindow::on_pushButton_5_clicked()
{
    personnel p;

          QString nom=ui->lineEdit->text();
          QString prenom=ui->lineEdit_3->text();
          QString mobile=ui->lineEdit_2->text();
        if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked())
        {


            ui->tableView->setModel(p.chercher(nom,prenom,mobile));


        }
}






void MainWindow::on_checkBox_stateChanged(int arg1)
{
    personnel p;
      QString nom=ui->lineEdit->text();
       ui->tableView->setModel(p.cherchernom(nom));
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    personnel p;
     QString nom=ui->lineEdit_3->text();
      ui->tableView->setModel(p.chercherprenom(nom));
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    personnel p;
        QString nom=ui->lineEdit_2->text();
         ui->tableView->setModel(p.cherchermobile(nom));
}


void MainWindow::on_pushButton_6_clicked()
{




            Stat *w = new Stat();
            w->make();
            w->show();

}



void MainWindow::on_azzerty_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM personnel WHERE cin  LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) {

         }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->azzerty->clear();}
}
