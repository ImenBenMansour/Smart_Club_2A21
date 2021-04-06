#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenements.h"
#include "sponsor.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_quitter_clicked();



    void on_pushButton_3_clicked();





    void on_pushButton_6_clicked();

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();


    void on_pushButton_modif_clicked();


    void on_radioButton_clicked();


    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();




    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_7_windowIconTextChanged(const QString &iconText);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    evenements tmpevenements;
    participant tmpparticpant;

};
#endif // MAINWINDOW_H
