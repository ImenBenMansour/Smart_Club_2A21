#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personnel.h"
#include "role.h"
#include "evenements.h"
#include "sponsor.h"
#include "login.h"
#include "widget.h"
#include"equipement.h"
#include"fournisseur.h"
#include"animal.h"
#include"nourriture.h"
#include"excel.h"
#include"abonne.h"
#include"abonnement.h"
#include"statis1.h"

//#include "chat.h"
#include <QMainWindow>
#include <QtMultimedia/QSound>


#include <QDebug>
#include <QSqlTableModel>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>


#include <QMediaPlayer>
#include <QSystemTrayIcon>
#include <QFuture>
#include <QSound>

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
 void on_jouer_clicked();




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

//login
void on_login_button_clicked ();
void on_signup_button_clicked();
void on_mail_clicked();

void on_comboBox_3_activated(const QString &arg1);


//eya et cynda
void on_pb_ajouter_eq_clicked();
void on_ajouter_fournisseur_clicked();

void on_pb_supp_eq_clicked();

void on_pushButton_29_clicked();

void on_pushButton_27_clicked();

void on_radioButton_triNomE_clicked();

void on_radioButton_triMarqueE_clicked();

void on_radioButton_tri_daE_clicked();

void on_pushButton_30_clicked();

void sendMail();
void mailSent(QString);
void browse();


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


void on_pushButton_31_clicked();

void on_sendBtn_clicked();

void on_pushButton_21_clicked();

void on_pushButton_22_clicked();

void on_pushButton_23_clicked();

void on_pushButton_25_clicked();

void on_pushButton_24_clicked();

void on_pushButton_26_clicked();

void on_Maryem_clicked();

void on_boutheina_clicked();

void on_eya_clicked();

void on_cynda_clicked();

void on_checkBox_RefE_stateChanged(int arg1);

//sidhom




void on_le_Modifier_clicked();



void on_radioButton_3_clicked();

// void on_le_id_cursorPositionChanged(int arg1, int arg2);



void on_le_modifier_2_clicked();

void on_le_recherche_abonne_textChanged(const QString &arg1);

void on_pb_recherche_abonne_clicked();

void on_combo_client_activated(const QString &arg1);



void on_pushButton_pdf_clicked();

void on_le_stat_clicked();

void on_le_id_textChanged(const QString &arg1);

void on_le_id_sup_textChanged(const QString &arg1);

void on_le_id_sup_2_textChanged(const QString &arg1);


void on_pb_ajouter_3_clicked();



void on_radioButton_10_clicked();

void on_radioButton_11_clicked();

void on_pb_supprimer_3_clicked();

void on_pushButton_32_clicked();

void on_pb_ajouter_4_clicked();

void on_pb_supprimer_4_clicked();

void on_youssef_clicked();

void on_radioButton_12_clicked();

void on_logout_button_clicked();

void on_mdp_oublie_label_linkActivated(const QString &link);

void on_radioButton_jour_toggled(bool checked);

void on_radioButton_nuit_toggled(bool checked);

void on_confirmer_langue_clicked();



//son config mimi
void on_ouvrir_media_clicked();
void on_play_media_clicked();
void on_pause_media_clicked();

void on_stop_media_clicked();

void on_mute_media_clicked();

void on_volume_media_valueChanged(int value);

void on_annuler_chan_mdp_clicked();

void on_confirmer_chan_mdp_clicked();

void on_ajouter_image_clicked();

void on_cant_touch_this_pressed();

void on_configuration_clicked();

private:
    Ui::MainWindow *ui;
    personnel tmppersonnel;
    role tmprole;
    QRegExp cin_regex;
    QSound *sound;
    evenements tmpevenements;
    participant tmpparticpant;


    Equipement E;
    fournisseur f;
    QStringList files;
    QByteArray data;
    Animal A;
    Nourriture N_temp;


    Abonne a;
    Abonnement b;
     projeth tmph;

     QTranslator *translator=new QTranslator;

    login *log;
    QString current_user;
    QString myid="";
    int counter=0;
    bool test=false;
    int initial_width;
    int initial_height;
    int login_width;
    int login_height;
    int center_main_x=0;
    int center_main_y=0;
    int center_login_x=0;
    int center_login_y=0;




    QMediaPlayer *player;

    QSystemTrayIcon *mSystemTrayIcon;
    QMediaPlayer *mMediaPlayer;
    QSound *son;
    QMediaPlayer musicAdd;
};
#endif // MAINWINDOW_H
