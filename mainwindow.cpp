#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stati.h"
#include <QMessageBox>
#include "equipement.h"
#include "fournisseur.h"
#include "smtp.h"
#include <QFile>
#include <QFileDialog>
#include <QIntValidator>
#include <QSqlTableModel>
#include<QSqlRelationalTableModel>
#include <QTableView>
#include <QItemSelectionModel>
#include <QTableWidgetItem>
#include <QPrinter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Arduino
    int ret=A.connect_arduino();
    switch(ret)
    {
    case(0):qDebug()<<"arduino is not available and conected to : "<< A.getarduino_port_name();break;
    case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();break;
    case(-1):qDebug()<<"arduino is not available";


    }

     ui->stackedWidget->setCurrentIndex(0);
     ui->stackedWidget_2->setCurrentIndex(0);
     //ui->stackedWidget->setCurrentIndex(1);

     //for email tab
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    ui->lineEdit->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_7->setValidator(new QIntValidator(0,9999999,this));
    ui->tableView->setModel(E.afficher());
    ui->tableView_4->setModel(f.afficher());
    ui->tableView_2->setModel(E.afficher());
    ui->tableView_3->setModel(E.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_eq_clicked()
{
    int ref= ui->lineEdit->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString marque= ui->lineEdit_3->text();
    QString prix= ui->lineEdit_4->text();
    int quantite= ui->lineEdit_5->text().toInt();
    QString gamme=ui->comboBox->currentText();
    QString type=ui->comboBox_2->currentText();
    QDate date_ajout=ui->dateEdit->date();
    int fournisseur= ui->lineEdit_9->text().toInt();


    Equipement E(ref,nom,marque,prix,quantite,gamme,type,date_ajout,fournisseur);

    bool test=E.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(E.afficher());
     }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "Click Cancel to exit."),
                               QMessageBox::Cancel);

}


void MainWindow::on_pushButton_2_clicked()
{
    int id_f=ui->lineEdit_7->text().toInt();
    QString nom=ui->lineEdit_8->text();
    QString prenom=ui->lineEdit_10->text();
    int tel=ui->lineEdit_11->text().toInt();
    QString adresse=ui->lineEdit_12->text();
    int rib=ui->lineEdit_13->text().toInt();
    QString mail=ui->lineEdit_14->text();

    fournisseur f(id_f,nom,prenom,tel,adresse,rib,mail);

    bool test=f.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_4->setModel(f.afficher());

     }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "Click Cancel to exit."),
                               QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{

    stati *w = new stati();
    w->make();
    w->show();

}

void MainWindow::on_pushButton_4_clicked()
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
   int ref=ui->lineEdit_15->text().toInt();
   bool test=E.supprimer(ref);

    if(test)
    {             ui->tableView->setModel(E.afficher());

        QMessageBox::information(nullptr, QObject::tr("supprimer equipement"),
                              QObject::tr("suppression ressuie.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                {  QMessageBox::information(nullptr, QObject::tr("supprimer equipement"),
                              QObject::tr("suppression echouée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_11_clicked()
{
    int id_f=ui->lineEdit_16->text().toInt();
    bool test=f.supprimer(id_f);

     if(test)
     {             ui->tableView->setModel(f.afficher());

         QMessageBox::information(nullptr, QObject::tr("supprimer fournisseur"),
                               QObject::tr("suppression ressuie.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

           }
               else
                 {  QMessageBox::information(nullptr, QObject::tr("supprimer fournissseur"),
                               QObject::tr("suppression echouée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_clicked()
{
    int ref= ui->lineEdit->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString marque= ui->lineEdit_3->text();
    QString prix= ui->lineEdit_4->text();
    int quantite= ui->lineEdit_5->text().toInt();
    QString gamme=ui->comboBox->currentText();
    QString type=ui->comboBox_2->currentText();
    QDate date_ajout=ui->dateEdit->date();
    int fournisseur= ui->lineEdit_9->text().toInt();


           Equipement E(ref,nom,marque,prix,quantite,gamme,type,date_ajout,fournisseur);

  bool test = E.update(ref,nom,marque,prix,quantite,gamme,type,date_ajout,fournisseur);



  if(test)

  {
       ui->tableView->setModel(E.afficher());
      QMessageBox::information(nullptr, QObject::tr("update "),
                  QObject::tr("equipement modifie\n"
  "Click Cancel to exit."), QMessageBox::Cancel);}
  else
      QMessageBox::critical(nullptr, QObject::tr("update "),
                  QObject::tr("equipement non modifie\n"
  "Click Cancel to exit."), QMessageBox::Cancel);}



void MainWindow::on_pushButton_10_clicked()
{

   int id_f=ui->lineEdit_7->text().toInt();
    QString nom=ui->lineEdit_8->text();
    QString prenom=ui->lineEdit_10->text();
    int tel=ui->lineEdit_11->text().toInt();
    QString adresse=ui->lineEdit_12->text();
    int rib=ui->lineEdit_13->text().toInt();
    QString mail=ui->lineEdit_14->text();

   fournisseur f(id_f,nom,prenom,tel,adresse,rib,mail);
    bool test = f.update(id_f,nom,prenom,tel,adresse,rib,mail);

    if(test)

    {
         ui->tableView_4->setModel(f.afficher());
        QMessageBox::information(nullptr, QObject::tr("update "),
                    QObject::tr("fournisseur modifie\n"
    "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("update "),
                    QObject::tr("fournisseur non modifie\n"
    "Click Cancel to exit."), QMessageBox::Cancel);}


void MainWindow::on_pushButton_7_clicked()
{
    if (ui->checkBox->isChecked())
        {
           int ref= ui->lineEdit->text().toInt();
            QSqlQueryModel *verif=E.rechercherref(ref);
            if (verif != nullptr)
            {
                ui->tableView_4->setModel(verif);
                QMessageBox::information(nullptr, QObject::tr("Recherche ref"),
                            QObject::tr("Recherche affecté sur la reference.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
         }

        if (ui->checkBox_3->isChecked())
        {
            QString gamme=ui->comboBox_3->currentText();
            QSqlQueryModel *verif=E.recherchergamme(gamme);
            if (verif != nullptr)
            {
                ui->tableView_4->setModel(verif);

                QMessageBox::information(nullptr, QObject::tr("Recherche gamme"),
                            QObject::tr("Recherche affecté sur la gamme.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
         }
        if (ui->checkBox_2->isChecked())
        { QString type=ui->comboBox_2->currentText();
            QSqlQueryModel *verif=E.recherchertype(type);
            if (verif != nullptr)
            {
                ui->tableView_4->setModel(verif);

                QMessageBox::information(nullptr, QObject::tr("Recherche type"),
                            QObject::tr("Recherche affecté sur le type.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
         }

     /*if ((ui->checkBox->isChecked()) && (ui->checkBox_3->isChecked()) && (ui->checkBox_2->isChecked()))
     {

         int ref= ui->lineEdit->text().toInt();
         QString  gamme=ui->comboBox_3->currentText();
         QString type=ui->comboBox_4->currentText();

                     if (ref!=0)
                       {
                         if (gamme!="")
                            {
                             if (type!="")
                             {
                     QSqlQueryModel *verif=E.rechercher(ref,gamme,type);
                     if (verif!=nullptr)
                     {
                         QMessageBox msgBox ;
                         ui->tableView_4->setModel(verif);
                         msgBox.setText("recherche bien affecté sur les 3 critéres");
                     }
                         } else
                             QMessageBox::warning(this,"erreur","Champ ref est vide");
                     } else
                         QMessageBox::warning(this,"erreur","Champ gamme est vide");
                     } else
                         QMessageBox::warning(this,"erreur","Champ type est vide");

     }  else QMessageBox::warning(this,"erreur","Aucun critére n'est coché"); */
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_radioButton_3_clicked()
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
                        ui->tableView_3->setModel(model);
                        ui->tableView_3->show();
                        msgBox.setText("Tri sur le nom avec succés.");
                        msgBox.exec();
}

void MainWindow::on_radioButton_2_clicked()
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
                        ui->tableView_3->setModel(model);
                        ui->tableView_3->show();
                        msgBox.setText("Tri sur la marque avec succés.");
                        msgBox.exec();
}

void MainWindow::on_radioButton_clicked()
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
                        ui->tableView_3->setModel(model);
                        ui->tableView_3->show();
                        msgBox.setText("Tri sur la date d'ajout avec succés.");
                        msgBox.exec();
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

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
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("cynda.zagrouba@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("cynda.zagrouba@esprit.tn", ui->rcpt->text(), ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("cynda.zagrouba@esprit.tn", ui->rcpt->text(), ui->subject->text(),ui->msg->toPlainText());
}
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
