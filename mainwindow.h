#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"equipement.h"
#include"fournisseur.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "smtp.h"
#include "arduino.h"


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
    void on_pb_ajouter_eq_clicked();
    void on_pushButton_2_clicked();    
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pb_supp_eq_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void sendMail();
    void mailSent(QString);
    void browse();

private:
    Ui::MainWindow *ui;
    Equipement E;
    fournisseur f;
    QStringList files;
    QByteArray data;
    Arduino A;

};
#endif // MAINWINDOW_H
