#ifndef STATIS_H
#define STATIS_H


#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>

#include <QWidget>


namespace Ui {
class statis1;
}

class statis1 : public QWidget
{
    Q_OBJECT

public:
    explicit statis1(QWidget *parent = nullptr);
     void make();
    ~statis1();

private:
    Ui::statis1 *ui;
};

#endif // STATIS_H
