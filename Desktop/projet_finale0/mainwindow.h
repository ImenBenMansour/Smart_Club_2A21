#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personnel.h"
#include "role.h"
#include "evenements.h"
#include "sponsor.h"

//#include "chat.h"
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

 void on_pushButton_11_clicked();

 void on_pushButton_9_clicked();

 void on_pushButton_12_clicked();

 void on_pushButton_7_clicked();

 void on_radioButton_5_clicked();

 void on_radioButton_6_clicked();
//maryem
 void on_pushButton_quitter_clicked();
 void on_pushButton_14_clicked();

 void on_lineEdit_6_textChanged(const QString &arg1);

 void on_pushButton_19_clicked();

 void on_pushButton_13_clicked();

 void on_pushButton_15_clicked();


 void on_pushButton_modif_clicked();


 void on_radioButton_7_clicked();


 void on_radioButton_8_clicked();

 void on_radioButton_9_clicked();





 void on_pushButton_16_clicked();

 void on_pushButton_16_windowIconTextChanged(const QString &iconText);

 void on_lineEdit_textChanged(const QString &arg1);


 void on_pushButton_18_clicked();

 void on_pushButton_17_clicked();



void on_lineEdit_6_TextChanged(const QString &arg1);

void on_checkBox_clicked();

private:
    Ui::MainWindow *ui;
    personnel tmppersonnel;
    role tmprole;
    QRegExp cin_regex;
    QSound *sound;
    evenements tmpevenements;
    participant tmpparticpant;

};
#endif // MAINWINDOW_H
