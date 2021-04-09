#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "abonne.h"
#include "abonnement.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();



    void on_le_Modifier_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

   // void on_le_id_cursorPositionChanged(int arg1, int arg2);

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_le_modifier_2_clicked();

    void on_le_recherche_abonne_textChanged(const QString &arg1);

    void on_pb_recherche_abonne_clicked();

    void on_combo_client_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_pdf_clicked();

    void on_le_stat_clicked();

private:
    Ui::MainWindow *ui;
   Abonne a;
   Abonnement b;
};

#endif // MAINWINDOW_H
