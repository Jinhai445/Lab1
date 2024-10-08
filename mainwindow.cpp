#include "mainwindow.h"
#include "ui_mainwindow.h"

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnNumClicked()
{
    QString str = ui->lineEdit->text() + qobject_cast<QPushButton*>(sender())->text();
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

