#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personnel.h"
#include "role.h"
#include "chat.h"
#include <QMainWindow>
#include <QtMultimedia/QSound>


#include <QDebug>
#include <QSqlTableModel>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>

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
    void on_pushButton_2_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();



    void on_ajouter2_clicked();

    void on_supprimer_role_clicked();

    void on_modifier_role_clicked();

   // void on_lineEdit_4_textChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_salaire_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();






 void on_pushButton_5_clicked();



 void on_checkBox_stateChanged(int arg1);

 void on_checkBox_2_stateChanged(int arg1);

 void on_checkBox_3_stateChanged(int arg1);

 void on_checkBox_4_stateChanged(int arg1);

 void on_pushButton_6_clicked();

 void on_tabWidget_currentChanged(int index);


 void on_azzerty_textChanged(const QString &arg1);

 void on_chat_clicked();

 void on_envoyer_clicked();

 void on_actionSound_clicked();

 void on_muteSound_clicked();

private:
    Ui::MainWindow *ui;
    personnel tmppersonnel;
    role tmprole;
    QRegExp cin_regex;
    QSound *sound;

};
#endif // MAINWINDOW_H
