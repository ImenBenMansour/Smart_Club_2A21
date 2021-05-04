#ifndef STATIS3_H
#define STATIS3_H

#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>

#include <QWidget>

namespace Ui {
class Statis3;
}

class Statis3 : public QWidget
{
    Q_OBJECT

public:
    explicit Statis3(QWidget *parent = nullptr);
    void make();
    ~Statis3();

private:
    Ui::Statis3 *ui;
};

#endif // STAT_H


