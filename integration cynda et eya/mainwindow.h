#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"equipement.h"
#include"fournisseur.h"
#include"animal.h"
#include"nourriture.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "smtp.h"
#include "arduino.h"
#include "excel.h"


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
    void on_ajouter_fournisseur_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pb_supp_eq_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_radioButton_triNomE_clicked();

    void on_radioButton_triMarqueE_clicked();

    void on_radioButton_tri_daE_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void sendMail();
    void mailSent(QString);
    void browse();

    void on_vers_ayou_clicked();

    void on_vers_cycy_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_reset_clicked();

    void on_pb_supprimer_clicked();

    void on_rechercher_anim_clicked();

    void on_reafficher_anim_clicked();

    void on_stat_clicked();

    void on_exporter_clicked();

    void on_le_id_supp_textChanged(const QString &arg1);

    void on_pb_ajouter_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_reset_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_le_id_supp_2_textChanged(const QString &arg1);

    void on_radioButton_typeN_clicked();

    void on_radioButton_quantiteN_clicked();

    void on_radioButton_idN_clicked();

    void on_pushButton_exporter_f_clicked();


private:
    Ui::MainWindow *ui;
    Equipement E;
    fournisseur f;
    QStringList files;
    QByteArray data;
    Arduino AR;
    Animal A;
    Nourriture N_temp;

};
#endif // MAINWINDOW_H
