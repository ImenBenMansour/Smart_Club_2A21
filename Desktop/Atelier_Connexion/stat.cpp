#include "stat.h"
#include "ui_stat.h"
#include <QString>
#include<qsqlquery.h>

Stat::Stat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stat)
{
    ui->setupUi(this);
}

Stat::~Stat()
{
    delete ui;
}



void Stat::make()
{
         int chatt;
        int chienn;
        int total;
        QString chat;
        QString chien;
        QSqlQuery q;

        q.prepare("SELECT COUNT(id) FROM etudiant where type='chat' ");
        q.exec();
        q.first() ;
        chatt=(q.value(0).toInt());

        q.prepare("SELECT COUNT(id) FROM etudiant where type='chien' ");
        q.exec();
        q.first() ;
        chienn=(q.value(0).toInt());
        q.prepare("SELECT COUNT(id) FROM evenements  ");
        q.exec();
        q.first() ;
        total=(q.value(0).toInt());

        chatt=((double)chatt/(double)total)*100;
        chienn=100-chatt;

        chat= QString::number(chatt);
        chien=QString::number(chienn);
        QPieSeries *series;
         series= new  QPieSeries();
         series->append("chat"+chat+"%",chatt);
         series->append("chien"+chat+"%",chienn);
         QPieSlice *slice0 = series->slices().at(0);
          slice0->setLabelVisible();

          QPieSlice *slice1 = series->slices().at(1);
             slice1->setExploded();
             slice1->setLabelVisible();
             slice1->setPen(QPen(Qt::green, 3));
             slice1->setBrush(Qt::darkYellow);

              QChart *chart = new QChart();
              chart->addSeries(series);
              chart->setTitle("Stat sur type d'evenements ");
              chart->legend()->show();
              QChartView *chartView = new QChartView(chart);
              chartView->setRenderHint(QPainter::Antialiasing);
              ui->verticalLayout->addWidget(chartView);

}
