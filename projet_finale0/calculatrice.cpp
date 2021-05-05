#include "calculatrice.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle("Super Calculatrice");

    // IHM
    Number1 = new QDoubleSpinBox();
    Number2 = new QDoubleSpinBox();
    //Interaction
    ButtonAdd = new QPushButton("+");
    ButtonRemove = new QPushButton("-");
    ButtonMulty = new QPushButton("*");
    ButtonDiv = new QPushButton("/");
    // Result
    LabelResult= new QLabel("???");

    //layout
    QGridLayout *layout = new QGridLayout;
    //IHM
    layout->addWidget(Number1,1,1,1,2);
    layout->addWidget(Number2,1,3,1,2);
    //Interaction
    layout->addWidget(ButtonAdd,2,1,1,1);
    layout->addWidget(ButtonRemove,2,2,1,1);
    layout->addWidget(ButtonMulty,2,3,1,1);
    layout->addWidget(ButtonDiv,2,4,1,1);
    // Result
    layout->addWidget(LabelResult,3,1,1,4);

    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    widget->setLayout(layout);


    // Signel et slot :
    QObject::connect(ButtonAdd,SIGNAL(clicked()),this,SLOT(Add()));
    QObject::connect(ButtonRemove,SIGNAL(clicked()),this,SLOT(Remove()));
    QObject::connect(ButtonMulty,SIGNAL(clicked()),this,SLOT(Multy()));
    QObject::connect(ButtonDiv,SIGNAL(clicked()),this,SLOT(Div()));
}

MainWindow::~MainWindow()
{

}


void MainWindow::Add()
{
    LabelResult->setText(QString::number(Number1->value()+Number2->value()));
}
void MainWindow::Remove()
{
    LabelResult->setText(QString::number(Number1->value()-Number2->value()));
}
void MainWindow::Multy()
{
    LabelResult->setText(QString::number(Number1->value()*Number2->value()));
}
void MainWindow::Div()
{
    if(Number2->value()==0.0) {
        LabelResult->setText("inf");
    }
    else
    {
        LabelResult->setText(QString::number(Number1->value()/Number2->value()));
    }

}
