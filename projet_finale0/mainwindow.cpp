#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnel.h"
#include "role.h"
#include "dialog.h"
#include "stati.h"
#include "statis.h"
#include "stat.h"
#include "smtp.h"
#include <QFile>
#include<QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sound=new QSound("C:/Users/LENOVO/Desktop/boutheina lagrem/projet-test/music.wav");//lecture sound

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

//maryem

    this->setStyleSheet("background-color: rgb(157,0,79);");

    ui->lineEdit_id->setPlaceholderText("id ...");
    ui->lineEdit_idp->setPlaceholderText("id ...");
    ui->lineEdit_nom->setPlaceholderText("nom ...");
    ui->lineEdit_nomp->setPlaceholderText(" prenom...");

    ui->lineEdit_prenomp->setPlaceholderText(" prenom...");
    ui->lineEdit_numerop->setPlaceholderText(" numero...");
    ui->lineEdit_lieu->setPlaceholderText("lieu...");
     ui->tableView_4->setModel(tmpevenements.afficher());
     ui->tableView_6->setModel(tmpparticpant.afficher());

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
     ui->comboBox_3->setStyleSheet("QComboBox { color: blue;}");
     ui->comboBox_4->setModel(tmpparticpant.affichercid());
//login
     ui->passwordLineEdit_login->setEchoMode(QLineEdit::Password);
     ui->passwordLineEdit_signup->setEchoMode(QLineEdit::Password);
     ui->confimerMotDePasseLineEdit_signup->setEchoMode(QLineEdit::Password);

//cynda et eya
     //for email tab
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    ui->ld_refE->setValidator(new QIntValidator(0,9999999,this));
    ui->ld_fournisseurF->setValidator(new QIntValidator(0,9999999,this));
    ui->tv_equipement->setModel(E.afficher());
    ui->tv_fournisseur->setModel(f.afficher());
    ui->tv_rechE->setModel(E.afficher());
    ui->tv_triE->setModel(E.afficher());

    //Animal
    ui->le_id_A->setValidator(new QIntValidator(100, 9999999, this));
    ui->tab_animal->setModel(A.afficher());
    //Nourriture
     ui->le_id_N_2->setValidator(new QIntValidator(100, 9999999, this));
     ui->tab_nourriture->setModel(N_temp.afficher());

     ui->stackedWidget_5->setCurrentIndex(0);
     ui->stackedWidget_4->setCurrentIndex(0);
     ui->stackedWidget_2->setCurrentIndex(0);//redirection






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
                QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                                             notifyIcon->show();
                                             notifyIcon->setIcon(QIcon("icone.png"));

                                             notifyIcon->showMessage("GESTION Personnel   ","Personnel Ajouté",QSystemTrayIcon::Information,15000);
                             QMessageBox::information(nullptr, QObject::tr("OK"),
                                         QObject::tr("Ajout effectué.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
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




void MainWindow::on_pushButton_7_clicked()
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

void MainWindow::on_pushButton_11_clicked()
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





void MainWindow::on_radioButton_5_clicked()
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

void MainWindow::on_radioButton_6_clicked()
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

void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEditcin->setText("");
    ui->lineEditnom->setText("");
    ui->lineEditprenom->setText("");
    ui->lineEditsalaire->setText("");
    ui->lineEditmobile->setText("");

}

void MainWindow::on_pushButton_12_clicked()
{
    ui->lineEdit_reference->setText("");
    ui->lineEdit_nb_employes->setText("");
}










void MainWindow::on_pushButton_6_clicked()
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
      QString nom=ui->lineEdit_3->text();
       ui->tableView->setModel(p.cherchernom(nom));
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    personnel p;
     QString nom=ui->lineEdit_4->text();
      ui->tableView->setModel(p.chercherprenom(nom));
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    personnel p;
        QString nom=ui->lineEdit_2->text();
         ui->tableView->setModel(p.cherchermobile(nom));
}


void MainWindow::on_pushButton_8_clicked()
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


void MainWindow::on_envoyer_clicked()
{
    QItemSelectionModel *select = ui->tableView_3->selectionModel();

    QString mobile =select->selectedRows(4).value(0).data().toString();
    QString nom =select->selectedRows(1).value(0).data().toString();
    QString prenom =select->selectedRows(5).value(0).data().toString();


    QDialog *d=new Dialog(mobile,nom,prenom,this);
    d->show();
    d->exec();
}

void MainWindow::on_actionSound_clicked()
{
    sound->play();

}

void MainWindow::on_muteSound_clicked()
{
    sound->stop();

}
void MainWindow::on_jouer_clicked()
{
    Widget *w = new Widget();
    w->show();



}




//maryem
void MainWindow::on_pushButton_quitter_clicked()
{
    int id= ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QDate dateEvent= ui->dateEdit_Event->date();
    QString lieu= ui->lineEdit_lieu->text();

    QString type= ui->comboBox_3->currentText();


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
void MainWindow::on_pushButton_modif_clicked()
{
    int id= ui->lineEdit_id->text().toInt();

        QString nom=ui->lineEdit_nom->text();

             QDate dateEvent=ui->dateEdit_Event->date();
             QString lieu=ui->lineEdit_lieu->text();

             QString type= ui->comboBox_3->currentText();


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



void MainWindow::on_pushButton_17_clicked()
{
    int id=ui->lineEdit_idp->text().toInt();
    QString nom= ui->lineEdit_nomp->text();
    QString prenom= ui->lineEdit_prenomp->text();

    QString offre= ui->lineEdit_offre->text();
    int numero= ui->lineEdit_numerop->text().toInt();
    participant p(id,nom,prenom,offre,numero);

    bool test=tmpparticpant.supprimer(id);

    if(test)
    {             ui->tableView_6->setModel(tmpparticpant.afficher());

        QMessageBox::information(nullptr, QObject::tr("supprimer sponsor"),
                              QObject::tr("supp ressuie.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                {  QMessageBox::information(nullptr, QObject::tr("supprimer sponsor"),
                              QObject::tr("supp echouèe.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
}













void MainWindow::on_pushButton_14_clicked()
{
    evenements e;
     e.CREATION_PDF();

}
void MainWindow::on_pushButton_15_clicked()
{
    Stat *w = new Stat();
    w->make();
    w->show();

}






void MainWindow::on_pushButton_16_windowIconTextChanged(const QString &iconText)
{

        evenements e;
        ui->tableView_2->setModel(e.chercher(ui->lineEdit_6->text()));
}

void MainWindow::on_pushButton_19_clicked()
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
        {ui->tableView_6->setModel(tmpparticpant.afficher());
            QMessageBox::information(nullptr, QObject::tr("ajout sponsor"),
                                  QObject::tr("ajout reussi.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

              }
                  else
                     { QMessageBox::information(nullptr, QObject::tr(" ajout sponsor "),
                                  QObject::tr("ajout echouèe.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}


}

void MainWindow::on_pushButton_18_clicked()
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
                 ui->tableView_6->setModel(tmpparticpant.afficher());
                QMessageBox::information(nullptr, QObject::tr("update "),
                            QObject::tr("sponsor modifie\n"
            "Click Cancel to exit."), QMessageBox::Cancel);}

}


void MainWindow::on_radioButton_7_clicked()
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




void MainWindow::on_radioButton_8_clicked()
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

void MainWindow::on_radioButton_9_clicked()
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







void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM evenements WHERE ID  LIKE'"+arg1+"%' or nom  LIKE'"+arg1+"%' or type  LIKE'"+arg1+"%' or lieu LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) {
             model->setQuery(*query);
             ui->tableView_2->setModel(model);
             }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->lineEdit_6->clear();}
}


//login
void MainWindow::on_login_button_clicked()
{

    if (ui->passwordLabel->text()=="Code")
    {

        if (log->sign_in_code(ui->usernameLineEdit_login->text(),ui->passwordLineEdit_login->text()))
        {
            QString pref=log->fetch_preferences(ui->usernameLineEdit_login->text());

            qDebug()<< pref;

            current_user=ui->usernameLineEdit_login->text();
            ui->stackedWidget->setCurrentIndex(1);



            if (current_user=="sara")
                ui->stackedWidget_2->setCurrentIndex(4);
            else if (current_user=="dhia")
                ui->stackedWidget_2->setCurrentIndex(0);
            else if (current_user=="bikou")
                ui->stackedWidget_2->setCurrentIndex(1);
            else if (current_user=="iheb")
                ui->stackedWidget_2->setCurrentIndex(2);
            else if (current_user=="elaa")
                ui->stackedWidget_2->setCurrentIndex(3);
            else
                ui->stackedWidget->setCurrentIndex(3);


            ui->usernameLineEdit_login->clear();
            ui->passwordLineEdit_login->clear();
            this->setFixedSize(initial_width,initial_height);
            this->move(center_main_x, center_main_y);

            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData(log->fetch_image(current_user),"PNG");
            outPixmap = outPixmap.scaledToWidth(ui->image_pos->width(),Qt::SmoothTransformation);
            ui->image_pos->setPixmap(outPixmap.scaled(outPixmap.width(),outPixmap.height(),Qt::KeepAspectRatio));

            ui->uname_label->setText(current_user);

        }
        else
            QMessageBox::warning(this,tr("Connexion"),tr("Erreur de connexion"));
    }
    else if (ui->passwordLabel->text()=="Mot de Passe")
    {
        if (log->sign_in(ui->usernameLineEdit_login->text(),ui->passwordLineEdit_login->text()))
        {
            QString pref=log->fetch_preferences(ui->usernameLineEdit_login->text());

            qDebug()<< pref;

            current_user=ui->usernameLineEdit_login->text();
            ui->stackedWidget->setCurrentIndex(1);



            if (current_user=="sara")
                ui->stackedWidget_2->setCurrentIndex(4);
            else if (current_user=="dhia")
                ui->stackedWidget_2->setCurrentIndex(0);
            else if (current_user=="bikou")
                ui->stackedWidget_2->setCurrentIndex(1);
            else if (current_user=="iheb")
                ui->stackedWidget_2->setCurrentIndex(2);
            else if (current_user=="elaa")
                ui->stackedWidget_2->setCurrentIndex(3);
            else
                ui->stackedWidget->setCurrentIndex(3);
            ui->usernameLineEdit_login->clear();
            ui->passwordLineEdit_login->clear();
            this->setFixedSize(initial_width,initial_height);

            this->move(center_main_x, center_main_y);

            ui->uname_label->setText(current_user);

            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData(log->fetch_image(current_user),"PNG");
            outPixmap = outPixmap.scaledToWidth(ui->image_pos->width(),Qt::SmoothTransformation);
            ui->image_pos->setPixmap(outPixmap.scaled(outPixmap.width(),outPixmap.height(),Qt::KeepAspectRatio));
        }
        else
        {
            QMessageBox::warning(this,tr("Connexion"),tr("Erreur de connexion"));
            test=false;
        }

    }

}


void MainWindow::on_signup_button_clicked()
{


        bool confirm_pwd=ui->confimerMotDePasseLineEdit_signup->text()==ui->passwordLineEdit_signup->text();

        if (ui->confimerMotDePasseLineEdit_signup->text()==ui->passwordLineEdit_signup->text())
            confirm_pwd=true;
        if (log->sign_up(ui->usernameLineEdit_signup->text(),ui->passwordLineEdit_signup->text(),ui->eMailLineEdit_signup->text()) && confirm_pwd)
        {

            resize(QDesktopWidget().availableGeometry(this).size() * 1.6);

            ui->stackedWidget->setCurrentIndex(1);
            current_user=ui->usernameLineEdit_signup->text();

            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData(log->fetch_image(current_user),"PNG");
            outPixmap = outPixmap.scaledToWidth(ui->image_pos->width(),Qt::SmoothTransformation);
            ui->image_pos->setPixmap(outPixmap.scaled(outPixmap.width(),outPixmap.height(),Qt::KeepAspectRatio));

            ui->uname_label->setText(current_user);

            ui->usernameLineEdit_signup->clear();
            ui->eMailLineEdit_signup->clear();
            ui->passwordLineEdit_signup->clear();
            ui->confimerMotDePasseLineEdit_signup->clear();
        }

        else
            QMessageBox::warning(this,tr("Inscription"),tr("Erreur d'insciption"));


}

void MainWindow::on_mail_clicked()
{QItemSelectionModel *select = ui->tableView_3->selectionModel();

    QString mobile =select->selectedRows(4).value(0).data().toString();
    QString nom =select->selectedRows(1).value(0).data().toString();
    QString prenom =select->selectedRows(5).value(0).data().toString();


    QDialog *d=new Dialog(mobile,nom,prenom,this);
    d->show();
    d->exec();

}



void MainWindow::on_pushButton_13_clicked()
{

        int id=ui->lineEdit_id->text().toInt();
        QString nom= ui->lineEdit_nom->text();
        QDate dateEvent= ui->dateEdit_Event->date();
        QString lieu= ui->lineEdit_lieu->text();

        QString type= ui->comboBox_3->currentText();


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










//cynda et eya


void MainWindow::on_ajouter_fournisseur_clicked()
{
    int id_f=ui->ld_fournisseurF->text().toInt();
    QString nom=ui->ld_nomF->text();
    QString prenom=ui->ld_prenomF->text();
    int tel=ui->ld_telF->text().toInt();
    QString adresse=ui->ld_adresseF->text();
    int rib=ui->ld_ribF->text().toInt();
    QString mail=ui->ld_mailF->text();

    fournisseur f(id_f,nom,prenom,tel,adresse,rib,mail);

    bool test=f.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tv_fournisseur->setModel(f.afficher());

     }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "Click Cancel to exit."),
                               QMessageBox::Cancel);
}

void MainWindow::on_pushButton_29_clicked()
{
    int id_f=ui->ld_fournisseurF->text().toInt();
    QString nom=ui->ld_nomF->text();
    QString prenom=ui->ld_prenomF->text();
    int tel=ui->ld_telF->text().toInt();
    QString adresse=ui->ld_adresseF->text();
    int rib=ui->ld_ribF->text().toInt();
    QString mail=ui->ld_mailF->text();

   fournisseur f(id_f,nom,prenom,tel,adresse,rib,mail);
    bool test = f.update(id_f,nom,prenom,tel,adresse,rib,mail);

    if(test)

    {
         ui->tv_fournisseur->setModel(f.afficher());
        QMessageBox::information(nullptr, QObject::tr("update "),
                    QObject::tr("fournisseur modifie\n"
    "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("update "),
                    QObject::tr("fournisseur non modifie\n"
    "Click Cancel to exit."), QMessageBox::Cancel);}



void MainWindow::on_pushButton_27_clicked()
{
    int id_f=ui->ld_suppF->text().toInt();
    bool test=f.supprimer(id_f);

     if(test)
     {             ui->tv_fournisseur->setModel(f.afficher());

         QMessageBox::information(nullptr, QObject::tr("supprimer fournisseur"),
                               QObject::tr("suppression ressuie.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

           }
               else
                 {  QMessageBox::information(nullptr, QObject::tr("supprimer fournissseur"),
                               QObject::tr("suppression echouée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_30_clicked()
{
     ui->stackedWidget_5->setCurrentIndex(1);
}

void MainWindow::on_pushButton_31_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);

}

void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
/*void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("cynda.zagrouba@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("cynda.zagrouba@esprit.tn", ui->rcpt->text(), ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("cynda.zagrouba@esprit.tn", ui->rcpt->text(), ui->subject->text(),ui->msg->toPlainText());
}*/
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}



void MainWindow::on_pb_ajouter_eq_clicked()
{
    int ref= ui->ld_refE->text().toInt();
    QString nom= ui->ld_nomE->text();
    QString marque= ui->ld_marqueE->text();
    QString prix= ui->ld_prixE->text();
    int quantite= ui->ld_quantiteE->text().toInt();
    QString gamme=ui->cb_gammeE->currentText();
    QString type=ui->cb_typeE->currentText();
    QDate date_ajout=ui->dt_AjoutE->date();
    int fournisseur= ui->ld_fournisseurE->text().toInt();


    Equipement E(ref,nom,marque,prix,quantite,gamme,type,date_ajout,fournisseur);

    bool test=E.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tv_equipement->setModel(E.afficher());
     }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "Click Cancel to exit."),
                               QMessageBox::Cancel);

}


void MainWindow::on_pushButton_21_clicked()
{
    int ref= ui->ld_refE->text().toInt();
    QString nom= ui->ld_nomE->text();
    QString marque= ui->ld_marqueE->text();
    QString prix= ui->ld_prixE->text();
    int quantite= ui->ld_quantiteE->text().toInt();
    QString gamme=ui->cb_gammeE->currentText();
    QString type=ui->cb_typeE->currentText();
    QDate date_ajout=ui->dt_AjoutE->date();
    int fournisseur= ui->ld_fournisseurE->text().toInt();


           Equipement E(ref,nom,marque,prix,quantite,gamme,type,date_ajout,fournisseur);

  bool test = E.update(ref,nom,marque,prix,quantite,gamme,type,date_ajout,fournisseur);



  if(test)

  {
       ui->tv_equipement->setModel(E.afficher());
      QMessageBox::information(nullptr, QObject::tr("update "),
                  QObject::tr("equipement modifie\n"
  "Click Cancel to exit."), QMessageBox::Cancel);}
  else
      QMessageBox::critical(nullptr, QObject::tr("update "),
                  QObject::tr("equipement non modifie\n"
  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_22_clicked()
{
    stati *w = new stati();
    w->make();
    w->show();
}

void MainWindow::on_pushButton_23_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("liste_equipements.pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;
       QSqlQuery q;
       q.prepare("SELECT * FROM equipement ");
       q.exec();
       QString pdf="<br> <img src='C:/Users/HP/Documents/equipement.jpg' height='200' width='300'/> <h1  style='color:red'>       LISTE DES EQUIPEMENTS  <br></h1>\n <br> <table>  <tr>  <th> REFERENCE </th> <th> NOM </th> <th> MARQUE </th> <th> PRIX  </th> <th> QUANTITE </th> <th> GAMME </th> <th> TYPE </th> <th> DATE_AJOUT </th> <th> FOURNISSEUR </th> </tr>" ;


       while ( q.next()) {

           pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString() +"</td>  <td>" +q.value(2).toString() +"  "" " "</td>      <td>     "+q.value(3).toString()+"</td>       <td>"+"    </td>  <td>   " + q.value(4).toString() +"</td>  <td>"+"    </td>  <td>   " + q.value(5).toString() +"</td>  <td>"+"    </td>  <td>   " + q.value(6).toString() +"</td>  <td>"+"    </td>  <td>   " + q.value(7).toString() +"</td>  <td>"+q.value(8).toString()+"       </td>" ;

       }
       doc.setHtml(pdf);
       doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);
}

void MainWindow::on_pb_supp_eq_clicked()
{
   int ref=ui->ld_suppE->text().toInt();
   bool test=E.supprimer(ref);

    if(test)
    {             ui->tv_equipement->setModel(E.afficher());

        QMessageBox::information(nullptr, QObject::tr("supprimer equipement"),
                              QObject::tr("suppression ressuie.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                {  QMessageBox::information(nullptr, QObject::tr("supprimer equipement"),
                              QObject::tr("suppression echouée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_25_clicked()
{
    if (ui->checkBox_RefE->isChecked())
    {
        int ref=ui->lineEdit_6->text().toInt();
        QSqlQueryModel *verif=E.rechercherref(ref);
        if (verif != nullptr)
        {
            ui->tv_rechE->setModel(verif);
            QMessageBox::information(nullptr, QObject::tr("Recherche Equipement"),
                        QObject::tr("Recherche affecté sur la reference.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
     }

    if (ui->checkBox_gammeE->isChecked())
    { QString gamme=ui->cb_rechGE->currentText();
        QSqlQueryModel *verif=E.recherchergamme(gamme);
        if (verif != nullptr)
        {
            QMessageBox msgBox ;
            ui->tv_rechE->setModel(verif);
            msgBox.setText("recherche bien affecté sur la gamme");
        }
     }
    if (ui->checkBox_typeE->isChecked())
    { QString type=ui->cb_rechTE->currentText();
        QSqlQueryModel *verif=E.recherchertype(type);
        if (verif != nullptr)
        {
            QMessageBox msgBox ;
            ui->tv_rechE->setModel(verif);
            msgBox.setText("recherche bien affecté sur le type");
        }
     }

 if ((ui->checkBox_RefE->isChecked())&&(ui->checkBox_gammeE->isChecked())&&(ui->checkBox_typeE->isChecked()))
 {

     int ref=ui->lineEdit_6->text().toInt();
     QString gamme=ui->cb_rechGE->currentText();
     QString type=ui->cb_rechTE->currentText();

      if (ref!=0)
                   {
                     if (gamme!="")
                        {
                 QSqlQueryModel *verif=E.rechercher(ref,gamme,type);
                 if (verif!=nullptr)
                 {
                     QMessageBox msgBox ;
                     ui->tv_rechE->setModel(verif);
                     msgBox.setText("recherche bien affecté sur les 3 critéres");
                 }
                     } else
                         QMessageBox::warning(this,"erreur","Champ type est vide");
                 } else
                     QMessageBox::warning(this,"erreur","Champ age est vide");

 } // else QMessageBox::warning(this,"erreur","Aucun critére n'est coché");

}

void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);

}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);

}


void MainWindow::on_radioButton_triNomE_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from equipement order by nom");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
                model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("gamme"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));

               model->setHeaderData(6, Qt::Horizontal, QObject::tr("date_ajout"));
               model->setHeaderData(7, Qt::Horizontal, QObject::tr("fournisseur"));
                        ui->tv_triE->setModel(model);
                        ui->tv_triE->show();
                        msgBox.setText("Tri sur le nom avec succés.");
                        msgBox.exec();
}

void MainWindow::on_radioButton_triMarqueE_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from equipement order by marque");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
                model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("gamme"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));

               model->setHeaderData(6, Qt::Horizontal, QObject::tr("date_ajout"));
               model->setHeaderData(7, Qt::Horizontal, QObject::tr("fournisseur"));
                        ui->tv_triE->setModel(model);
                        ui->tv_triE->show();
                        msgBox.setText("Tri sur la marque avec succés.");
                        msgBox.exec();
}

void MainWindow::on_radioButton_tri_daE_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from equipement order by date_ajout");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
                model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("gamme"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));

               model->setHeaderData(6, Qt::Horizontal, QObject::tr("date_ajout"));
               model->setHeaderData(7, Qt::Horizontal, QObject::tr("fournisseur"));
                        ui->tv_triE->setModel(model);
                        ui->tv_triE->show();
                        msgBox.setText("Tri sur la date d'ajout avec succés.");
                        msgBox.exec();
}

















//ayouuu
void MainWindow::on_pb_ajouter_clicked()
{

    int id_A=ui->le_id_A->text().toInt();
    QString  prenom=ui->le_prenomA->text();
    QString age=ui->le_ageA->text();
    QString poid=ui->le_poidA->text();
    QString  etat=ui->cb_etatA->currentText();
    QString  type=ui->le_typeA->text();
    QString  race=ui->le_raceA->text();
    int id_N=ui->le_id_N->text().toInt();
    Animal A(id_A,age,poid,prenom,etat,type,race,id_N);

    bool test=A.ajouter();
    if(id_A==0||prenom==""||etat==""||type==""||race==""||age==""||poid==""||id_N==0)
    {
       QMessageBox::critical(nullptr, QObject::tr("vide"),
                                        QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);


    }

      else if(test==true){
       QMessageBox::information(nullptr, QObject::tr("OK"),
                       QObject::tr("Animal ajouté:\n"
            "click cancel to exit"),QMessageBox::Cancel);
 ui->tab_animal->setModel(A.afficher());

    }
    else{QMessageBox::information(nullptr, QObject::tr("chec d'ajout"),
                                  QObject::tr("Animal existe deja:\n"
                       "click cancel to exit"),QMessageBox::Cancel);}


}

void MainWindow::on_pb_modifier_clicked()
{
    int id_A= ui->le_id_A->text().toInt();
    QString age= ui->le_ageA->text();
    QString poid= ui->le_poidA->text();
    QString prenom=ui->le_prenomA->text();
    QString etat= ui->cb_etatA->currentText();
    QString type=ui->le_typeA->text();
    QString race=ui->le_raceA->text();
    int id_N= ui->le_id_N->text().toInt();

    Animal A(id_A,age,poid,prenom,etat,type,race,id_N);

       bool test = A.modifier(id_A,age,poid,prenom,etat,type,race,id_N);

            if(test)

            {
                 ui->tab_animal->setModel(A.afficher());
                QMessageBox::information(nullptr, QObject::tr("update "),
                            QObject::tr("Animal modifie\n"
            "Click Cancel to exit."), QMessageBox::Cancel);}
            else
                QMessageBox::critical(nullptr, QObject::tr("update "),
                         QObject::tr("Animal non modifie\n"
         "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_reset_clicked()
{
    ui->le_id_A->setText("");
    ui->le_ageA->setText("");
    ui->le_poidA->setText("");
    ui->le_prenomA->setText("");
    ui->cb_etatA->setCurrentText("");
    ui->le_typeA->setText("");
    ui->le_raceA->setText("");
    ui->le_id_N->setText("");
}

void MainWindow::on_pb_supprimer_clicked()
{
    Animal A1;
    //int id_A=ui->lineEdit_id->text().toInt();
    A1.setid_A(ui->le_id_suppA->text().toInt());
    bool test=A1.supprimer(A1.getid_A());

        if(test==true)
         {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                       QObject::tr("sup successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_animal->setModel(A1.afficher());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("Echec de Suppression "),
                                       QObject::tr("L'id n'existe pas dans la table.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_rechercher_anim_clicked()
{
    if (ui->checkBox_age->isChecked())
    { QString age=ui->rech_age->text();
        QSqlQueryModel *verif=A.rechercher_age(age);
        if (verif != nullptr)
        {
            ui->tab_animal->setModel(verif);
            QMessageBox::information(nullptr, QObject::tr("Recherche Animal"),
                        QObject::tr("Recherche affecté sur l'animal.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
     }

    if (ui->checkBox_type->isChecked())
    { QString type=ui->rech_type->text();
        QSqlQueryModel *verif=A.rechercher_type(type);
        if (verif != nullptr)
        {
            QMessageBox msgBox ;
            ui->tab_animal->setModel(verif);
            msgBox.setText("recherche bien affecté sur Type");
        }
     }
    if (ui->checkBox_etat->isChecked())
    { QString etat=ui->rech_etat->currentText();
        QSqlQueryModel *verif=A.rechercher_etat(etat);
        if (verif != nullptr)
        {
            QMessageBox msgBox ;
            ui->tab_animal->setModel(verif);
            msgBox.setText("recherche bien affecté sur l'état");
        }
     }
    if ((ui->checkBox_age->isChecked())&&(ui->checkBox_type->isChecked()))
    {
        QString age=ui->rech_age->text();
        QString type=ui->rech_type->text();

                    if (age!="")
                      {
                        if (type!="")
                           {
                    QSqlQueryModel *verif=A.rechercher_ageType(age,type);
                    if (verif!=nullptr)
                    {   QMessageBox msgBox ;
                        ui->tab_animal->setModel(verif);
                        msgBox.setText("recherche bien affecté sur age et type");
                    }
                        } else
                            QMessageBox::warning(this,"erreur","Champ type est vide");
                    } else
                        QMessageBox::warning(this,"erreur","Champ age est vide");
    }
    if ((ui->checkBox_age->isChecked())&&(ui->checkBox_etat->isChecked()))
    {
        QString age=ui->rech_age->text();
        QString etat=ui->rech_etat->currentText();

                    if (age!="")
                      {
                    QSqlQueryModel *verif=A.rechercher_ageEtat(age,etat);
                    if (verif!=nullptr)
                    {   QMessageBox msgBox ;
                        ui->tab_animal->setModel(verif);
                        msgBox.setText("recherche bien affecté sur age et etat");
                    }

                    } else
                        QMessageBox::warning(this,"erreur","Champ age est vide");
    }
    if ((ui->checkBox_type->isChecked())&&(ui->checkBox_etat->isChecked()))
    {
       QString type=ui->rech_type->text();
       QString etat=ui->rech_etat->currentText();

                    if (type!="")
                      {
                    QSqlQueryModel *verif=A.rechercher_typeEtat(type,etat);
                    if (verif!=nullptr)
                    {   QMessageBox msgBox ;
                        ui->tab_animal->setModel(verif);
                        msgBox.setText("recherche bien affecté sur Type et Etat");
                    }

                    } else
                        QMessageBox::warning(this,"erreur","Champ Type est vide");
    }


 if ((ui->checkBox_age->isChecked())&&(ui->checkBox_type->isChecked())&&(ui->checkBox_etat->isChecked()))
 {

     QString age=ui->rech_age->text();
     QString  type=ui->rech_type->text();
     QString etat=ui->rech_etat->currentText();

                 if (age!="")
                   {
                     if (type!="")
                        {
                 QSqlQueryModel *verif=A.rechercher_tous(age,type,etat);
                 if (verif!=nullptr)
                 {
                     QMessageBox msgBox ;
                     ui->tab_animal->setModel(verif);
                     msgBox.setText("recherche bien affecté sur les 3 critéres");
                 }
                     } else
                         QMessageBox::warning(this,"erreur","Champ type est vide");
                 } else
                     QMessageBox::warning(this,"erreur","Champ age est vide");

 } // else QMessageBox::warning(this,"erreur","Aucun critére n'est coché");
}

void MainWindow::on_reafficher_anim_clicked()
{
    ui->rech_age->setText("");
    ui->rech_type->setText("");
    ui->rech_etat->setCurrentText("");
    ui->tab_animal->setModel(A.afficher());
}

void MainWindow::on_stat_clicked()
{
    statis *w = new statis();
    w->make();
    w->show();
}

void MainWindow::on_exporter_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("liste_animaux.pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;
       QSqlQuery q;
       q.prepare("SELECT * FROM animal ");
       q.exec();
       QString pdf="<br> <img src='/C:/Users/LENOVO/Documents/build-Gestion-Animal-Desktop_Qt_5_9_9_MinGW_32bit-Debug/cc.png' height='200' width='600'/> <h1  style='color:brown'>       LISTE DES ANIMAUX  <br></h1>\n <br> <table>  <tr>  <th> Identifiant </th> <th> Type </th> <th> Race </th> <th> Prenom  </th> <th> Etat </th> <th> Age </th> <th> Poid </th> <th> Nourriture </th> </tr>" ;


       while ( q.next()) {

           pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString() +"</td>  <td>" +q.value(2).toString() +"  "" " "</td>      <td>     "+q.value(3).toString()+"--------"+"</td>       <td>"+q.value(4).toString()+" <td>"+q.value(5).toString()+" <td>"+q.value(6).toString()+" <td>   " + q.value(7).toString() +"</td>       </td>"   ;

       }
       doc.setHtml(pdf);
       doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);

}


void MainWindow::on_le_id_supp_textChanged(const QString &arg1)
{

    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM animal WHERE id_A  LIKE'"+ arg1+"%'");
         query->exec();
         if (query->next()) { }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
               ui->le_id_suppA->clear();



}
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id_N=ui->le_id_N_2->text().toInt();
    QString  consommateur=ui->le_consommateurN->text();
    QString  type=ui->le_type_N->text();
    QString  marque=ui->le_marqueN->text();
    QString  quantite=ui->le_quantiteN->text();
    Nourriture N(id_N,consommateur,type,marque,quantite);

    bool test=N.ajouter();
    if(id_N==0||consommateur==""||type==""||marque==""||quantite=="")
    {
       QMessageBox::critical(nullptr, QObject::tr("vide"),
                                        QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);


    }

      else if(test==true){
       QMessageBox::information(nullptr, QObject::tr("OK"),
                       QObject::tr("Nourriture ajouté:\n"
            "click cancel to exit"),QMessageBox::Cancel);
    ui->tab_nourriture->setModel(N_temp.afficher());

    }
    else{QMessageBox::information(nullptr, QObject::tr("chec d'ajout"),
                                  QObject::tr("Nourriture existe deja:\n"
                       "click cancel to exit"),QMessageBox::Cancel);}

}

void MainWindow::on_pb_modifier_2_clicked()
{
    int id_N= ui->le_id_N_2->text().toInt();
    QString consommateur= ui->le_consommateurN->text();
    QString type= ui->le_type_N->text();
    QString marque=ui->le_marqueN->text();
    QString quantite= ui->le_quantiteN->text();

      Nourriture N_temp (id_N,consommateur,type,marque,quantite);

     bool test = N_temp.modifier(id_N,consommateur,type,marque,quantite);

             if(test)

             {
                  ui->tab_nourriture->setModel(N_temp.afficher());
                 QMessageBox::information(nullptr, QObject::tr("update "),
                             QObject::tr("Nourriture modifie\n"
             "Click Cancel to exit."), QMessageBox::Cancel);}
             else
                 QMessageBox::critical(nullptr, QObject::tr("update "),
                          QObject::tr("Nourriture non modifie\n"
          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_reset_2_clicked()
{
    ui->le_id_N_2->setText("");
    ui->le_consommateurN->setText("");
    ui->le_type_N->setText("");
    ui->le_marqueN->setText("");
    ui->le_quantiteN->setText("");

}

void MainWindow::on_pb_supprimer_2_clicked()
{Nourriture N1;
    N1.setid_N(ui->le_id_supp_2->text().toInt());

    bool test=N1.supprimer(N1.getid_N());

        QMessageBox msgBox;
        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->tab_nourriture->setModel(N1.afficher());}
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();


}

void MainWindow::on_le_id_supp_2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM nourriture WHERE id_N  LIKE'"+ arg1+"%'");
         query->exec();
         if (query->next()) { }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->le_id_supp_2->clear();
}
}

void MainWindow::on_radioButton_typeN_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from nourriture order by type");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_N"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("consommateur"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
                model->setHeaderData(3, Qt::Horizontal, QObject::tr("marque"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
                        ui->tableViewTriN->setModel(model);
                        ui->tableViewTriN->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();
}

void MainWindow::on_radioButton_quantiteN_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from nourriture order by quantite");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_N"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("consommateur"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
                model->setHeaderData(3, Qt::Horizontal, QObject::tr("marque"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));

                        ui->tableViewTriN->setModel(model);
                        ui->tableViewTriN->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();
}

void MainWindow::on_radioButton_idN_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from nourriture order by CAST(id_N as INT) asc");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_N"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("consommateur"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("marque"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
                        ui->tableViewTriN->setModel(model);
                        ui->tableViewTriN->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();
}


void MainWindow::on_pushButton_exporter_f_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    EXCEL obj(fileName, "mydata", ui->tab_nourriture);

    //colums to export
    obj.addField(0, "id_N", "char(20)");
    obj.addField(1, "consommateur", "char(20)");
    obj.addField(2, "type", "char(20)");
    obj.addField(3, "marque", "char(20)");
    obj.addField(3, "quantite", "char(20)");

    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}





void MainWindow::on_Maryem_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_boutheina_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

void MainWindow::on_eya_clicked()
{

        ui->stackedWidget_2->setCurrentIndex(3);


}

void MainWindow::on_cynda_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);

}
