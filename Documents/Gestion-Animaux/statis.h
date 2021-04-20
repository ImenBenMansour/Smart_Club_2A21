#ifndef STATIS_H
#define STATIS_H

#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>

#include <QWidget>

namespace Ui {
class Statis;
}

class Statis : public QWidget
{
    Q_OBJECT

public:
    explicit Statis(QWidget *parent = nullptr);
     void make();
    ~Statis();

private:
    Ui::Statis *ui;
};

#endif // STATIS_H
