#ifndef STAT_H
#define STAT_H
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>


#include <QWidget>

namespace Ui {
class statis2;
}

class statis2 : public QWidget
{
    Q_OBJECT

public:
    explicit statis2(QWidget *parent = nullptr);
    void make();

    ~statis2();

private:
    Ui::statis2 *ui;
};

#endif // STAT_H


