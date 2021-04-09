#include "statis.h"
#include "ui_statis.h"
#include <QString>
#include"abonne.h"
#include<qsqlquery.h>


statis::statis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statis)
{
    ui->setupUi(this);
}

statis::~statis()
{
    delete ui;
}
void statis::make()
{
        int male;
        int femelle;
        int total;
        QString Male;
        QString Femelle;

        QSqlQuery q;

        q.prepare("SELECT COUNT(id_ab) FROM etudiant where etat ='Male' ");
        q.exec();
        q.first() ;
        Male=(q.value(0).toInt());

        q.prepare("SELECT COUNT(id_ab) FROM etudiant where etat ='Femelle' ");
        q.exec();
        q.first() ;
        Femelle=(q.value(0).toInt());
        q.prepare("SELECT COUNT(id_ab) FROM etudiant ");
        q.exec();
        q.first() ;
        total=(q.value(0).toInt());

        femelle=(((double)femelle)*100/(double)total);
        male=femelle-100;

        Male= QString::number(male);
        Femelle=QString::number(femelle);
        QPieSeries *series;
         series= new  QPieSeries();
         series->append("MALE"+Male+"%",male);
         series->append("FEMELLE"+Femelle+"%",femelle);
         QPieSlice *slice0 = series->slices().at(0);
          slice0->setLabelVisible();

          QPieSlice *slice1 = series->slices().at(1);
             slice1->setExploded();
             slice1->setLabelVisible();
             slice1->setPen(QPen(Qt::darkRed, 2));
             slice1->setBrush(Qt::black);

              QChart *chart = new QChart();
              chart->addSeries(series);
              chart->setTitle("Statistiques sur l'etat des animaux ");
              chart->legend()->show();
              QChartView *chartView = new QChartView(chart);
              chartView->setRenderHint(QPainter::Antialiasing);
              ui->verticalLayout->addWidget(chartView);

}
