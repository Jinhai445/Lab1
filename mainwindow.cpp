#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tinyexpr.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->num0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->num1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->num2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->num3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->num4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->num5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->num6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->num7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->num8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->num9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->add,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->sub,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->mul,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->div,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->mod,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->C,SIGNAL(clicked()),this,SLOT(on_ce_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnNumClicked()
{

    QString ori = ui->lineEdit->text();
    QString operand = qobject_cast<QPushButton*>(sender())->text();
    if(operand == "*" || operand == "+" ||operand == "-" ||operand == "/" ||operand == "%" ||
        operand =="^" || operand == "√" || operand == "1/x"){
        int lkuohao = ori.count("(");
        int rkuohao = ori.count(")");
        if(lkuohao > rkuohao){
            ori += ")";
        }
    }
    QString str = ori + qobject_cast<QPushButton*>(sender())->text();

    ui->lineEdit->setText(str);
    qDebug()<<str;
}

void MainWindow::on_dot_clicked()
{
    QString str = ui->lineEdit->text();
    if(!str.contains(".")){
        str +=  qobject_cast<QPushButton*>(sender())->text();
         ui->lineEdit->setText(str);
    }
}


void MainWindow::on_del_clicked()
{
    QString str = ui->lineEdit->text();
    ui->lineEdit->setText(str.left(str.length() - 1));
}


void MainWindow::on_finish_clicked()
{


    QString input = ui->lineEdit->text();
    QString result;
    // input  = "10%4+5^2+sqrt(2)";
    double resultnum =  te_interp(input.toStdString().c_str(), 0);
    ui->lineEdit->setText(QString::number(resultnum));
}




void MainWindow::on_square_clicked()
{

     QString str = ui->lineEdit->text() + "^" ;
     ui->lineEdit->setText(str);
}


void MainWindow::on_squareRoot_clicked()
{
    QString str = ui->lineEdit->text() + "sqrt(" ;
    ui->lineEdit->setText(str);
}


void MainWindow::on_ce_clicked()
{
    ui->lineEdit->setText("");
}



void MainWindow::on_inver_clicked()
{
    QString ori = ui->lineEdit->text();
    QString str = "1/(" + ori +")";
    ui->lineEdit->setText(str);
}


void MainWindow::on_pre_clicked()
{
    QString ori = ui->lineEdit->text();
    if(ori.startsWith("-(")){
        ori =  ori.mid(2,ori.length() - 3);
    }else{
        ori = "-(" + ori +")";
    }
    ui->lineEdit->setText(ori);
}

