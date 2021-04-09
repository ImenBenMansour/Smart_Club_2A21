#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abonne.h"

#include <QtDebug>
#include <QString>
#include <QDate>
#include <QMessageBox>
#include <QIntValidator>

#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <qsqlquery.h>
#include<statis.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->le_id->setValidator(new QIntValidator(100, 9999999, this));
  ui->tab_etudiant->setModel(a.afficher());
  ui->tab_etudiant_2->setModel(b.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id_ab=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int payement=ui->le_payement->text().toInt();
    int nbr_chats=ui->le_nbr_chats->text().toInt();
     QString sexe=ui->le_sexe->currentText();

    Abonne a(id_ab,nom,prenom,payement,nbr_chats,sexe);




bool test=a.ajouter();
if(test){
    QMessageBox::information(nullptr,QObject::tr("Abonne"),QObject::tr("abonne ajouté\n" "click ok to exit"),QMessageBox::Ok);
    ui->le_id->setText("");//bech ba3ed mankamel l ajout yarja3 a 0
    ui->le_nom->setText("");
    ui->le_prenom->setText("");
    ui->le_payement->setText("");
    ui->le_nbr_chats->setText("");
     ui->le_sexe->setCurrentText("");

    ui->tab_etudiant->setModel(a.afficher());//actualisation


}
else{
    QMessageBox::critical(nullptr,QObject::tr("Abonne"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
}


}

void MainWindow::on_pb_supprimer_clicked()
{ Abonne a1;a1.setid_ab(ui->le_id_sup->text().toInt());
    bool test=a1.supprimer(a1.getid_ab());
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Suppression avec succes.");
        ui->tab_etudiant->setModel(a.afficher());
}
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}


void MainWindow::on_le_Modifier_clicked()
{
            int id_ab= ui->le_id->text().toInt();
            QString nom=ui->le_nom->text();
            QString prenom=ui->le_prenom->text();
            int payement=ui->le_payement->text().toInt();
            int nbr_chats= ui->le_nbr_chats->text().toInt();
            QString sexe=ui->le_sexe->currentText();

                           Abonne a(id_ab,nom,prenom,payement,nbr_chats,sexe);


                           ui->le_id->setText("");



                bool test = a.update(id_ab,nom,prenom,payement,nbr_chats,sexe);


                if(test)

                {
                     ui->tab_etudiant->setModel(a.afficher());
                    QMessageBox::information(nullptr, QObject::tr("update "),
                                QObject::tr("Abonne modifie\n"
                "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_radioButton_clicked()
{
    {QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();


               model->setQuery("select * from etudiant order by CAST(id_ab as INT) desc");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_ab"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("payement"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_chats"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));

                        ui->tableView->setModel(model);
                        ui->tableView->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();

        }
}

void MainWindow::on_radioButton_2_clicked()
{
    QMessageBox msgBox ;
        QSqlQueryModel * model= new QSqlQueryModel();



           model->setQuery("select * from etudiant order by nom");

           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_ab"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("payement"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_chats"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));

                    ui->tableView->setModel(model);
                    ui->tableView->show();
                    msgBox.setText("Tri avec succés.");
                    msgBox.exec();
}

void MainWindow::on_radioButton_3_clicked()
{
    QMessageBox msgBox ;
        QSqlQueryModel * model= new QSqlQueryModel();



           model->setQuery("select * from etudiant order by prenom");

           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_ab"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("payement"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_chats"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));

                    ui->tableView->setModel(model);
                    ui->tableView->show();
                    msgBox.setText("Tri avec succés.");
                    msgBox.exec();
}
void MainWindow::on_pb_ajouter_2_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QDate date_deb=ui->le_date_deb->date();
   QDate date_fin=ui->le_date_fin->date();

    Abonnement b(id,date_deb,date_fin);

bool test=b.ajouter();
if(test){
    QMessageBox::information(nullptr,QObject::tr("Abonnement"),QObject::tr("abonnement ajouté\n" "click ok to exit"),QMessageBox::Ok);
    ui->le_id_2->setText("");//bech ba3ed mankamel l ajout yarja3 a 0

    ui->tab_etudiant_2->setModel(b.afficher());//actualisation


}
else{
    QMessageBox::critical(nullptr,QObject::tr("Abonnement"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
}




}

void MainWindow::on_pb_supprimer_2_clicked()
{
    Abonnement b1;
    b1.setid(ui->le_id_sup_2->text().toInt());
        bool test=b1.supprimer(b1.getid());
        QMessageBox msgBox;
        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->tab_etudiant_2->setModel(b.afficher());
    }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_le_modifier_2_clicked()
{
    int id= ui->le_id_2->text().toInt();

            QDate date_deb=ui->le_date_deb->date();
            QDate date_fin=ui->le_date_fin->date();
                           Abonnement b(id,date_deb,date_fin);
                           ui->le_id_2->setText("");


                bool test = b.update(id,date_deb,date_fin);


                if(test)

                {
                     ui->tab_etudiant_2->setModel(b.afficher());
                    QMessageBox::information(nullptr, QObject::tr("update "),
                                QObject::tr("Participant modifie\n"
                "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_le_recherche_abonne_textChanged(const QString &arg1)
{
    Abonne a;
        if(ui->le_recherche_abonne->text() == "")
            {
                ui->tableView->setModel(a.afficher());
            }
            else
            {
                 ui->tableView->setModel(a.rechercher(ui->le_recherche_abonne->text()));
            }
}





void MainWindow::on_pushButton_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tab_etudiant->model()->rowCount();
    const int columnCount = ui->tab_etudiant->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"

        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste Des abonnee </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_etudiant->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_etudiant->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tab_etudiant->isColumnHidden(column))
            {
                QString data = ui->tab_etudiant->model()->data(ui->tab_etudiant->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table> </center>\n"
        "</body>\n"
        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

void MainWindow::on_le_stat_clicked()
{
    statis *w=new statis();
    w->make();
    w->show();
}
