#ifndef CALCULATRICE_H
#define CALCULATRICE_H


#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent);
    ~MainWindow();

private:
    //IHM
    QDoubleSpinBox *Number1;
    QDoubleSpinBox *Number2;
    //Button
    QPushButton *ButtonAdd;
    QPushButton *ButtonRemove;
    QPushButton *ButtonMulty;
    QPushButton *ButtonDiv;
    //Resultat
    QLabel *LabelResult;

private slots:
    void Add();
    void Remove();
    void Multy();
    void Div();


};


#endif // CALCULATRICE_H
