#include "evenements.h"
#include "QDebug"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>

evenements::evenements()
{

}




evenements::evenements(int id, QString nom,QString type,QString lieu,QDate dateEvent )
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->lieu=lieu;
    this->dateEvent=dateEvent;

}

bool evenements::supprimer(int id)
{
QSqlQuery query;
query.prepare("DELETE FROM evenements WHERE id = :id");
query.bindValue(":id", id);
return    query.exec();
}



bool evenements::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO evenements (id,nom,type, lieu, dateEvent) "
                        "VALUES (:id, :nom,:type, :lieu,:dateEvent)");
    query.bindValue(":id",id);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":lieu", lieu);
   query.bindValue(":dateEvent", dateEvent);
    return    query.exec();

}
QSqlQueryModel * evenements::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from evenements");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("lieu"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("dateEvent"));


return model;
}

void evenements::CREATION_PDF()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM evenements ");
    q.exec();
    QString pdf="<br><img src=src='C:/Users/Espace Info/Desktop/projet qt/chien.png' height='80' width='300'/> <h1  style='color:pink'>tableu DES evenements  <br></h1>\n <br> <table>  <tr>  <th>ID </th> <th>NOM </th>  <th>TYPE </th> <th> LIEU </th>  <th>DATEVENT</th> </tr> " ;


    while ( q.next()) {
pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td> " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" </td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(4).toString()+"<td>"+q.value(5).toString()+" </td>  </td>";

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}
QSqlQueryModel * evenements::chercher(QString r)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from evenement where upper(nom) like upper('%"+r+"%') or upper(id) like upper('%"+r+"%') or upper(lieu) like upper('%"+r+"%') ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateEvent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));


        return model;
}
bool evenements::update(int id, QString nom,QDate dateEvent,QString lieu,QString type)
{
    QSqlQuery query;
    query.prepare("UPDATE evenements SET id= :id,nom= :nom,type= :type,lieu= :lieu,dateEvent= :dateEvent WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom",nom );
    query.bindValue(":type",type);
    query.bindValue(":lieu",lieu);
    query.bindValue(":dateEvent", dateEvent);

    return    query.exec();
}



