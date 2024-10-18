#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tinyexpr.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    digitsBTNs = {
                  {Qt::Key_0,ui->num0},
                  {Qt::Key_1,ui->num1},
                  {Qt::Key_2,ui->num2},
                  {Qt::Key_3,ui->num3},
                  {Qt::Key_4,ui->num4},
                  {Qt::Key_5,ui->num5},
                  {Qt::Key_6,ui->num6},
                  {Qt::Key_7,ui->num7},
                  {Qt::Key_8,ui->num8},
                  {Qt::Key_9,ui->num9},
                  {Qt::Key_Plus,ui->add},
                  {Qt::Key_Minus,ui->sub},
                  {Qt::Key_Asterisk,ui->mul},
                  {Qt::Key_Slash,ui->div},
                  {Qt::Key_Percent,ui->mod},
                  {Qt::Key_Delete,ui->del},
                  {Qt::Key_ParenRight,ui->right},
                  {Qt::Key_ParenLeft,ui->left}
                  };
    foreach(auto btn,digitsBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnShowClicked()));
    connect(ui->del,SIGNAL(clicked()),this,SLOT(on_del_clicked()));
    connect(ui->dot,SIGNAL(clicked()),this,SLOT(on_dot_clicked()));
    connect(ui->power,SIGNAL(clicked()),this,SLOT(btnShowClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnShowClicked()
{

    QString ori = ui->lineEdit->text();
    QString operand = qobject_cast<QPushButton*>(sender())->text();
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
void MainWindow::keyPressEvent(QKeyEvent* event){
    if(event->text().contains('^')){
        ui->power ->animateClick();
        return;
    }
    if(event->text().contains('.')){
        ui->dot->animateClick();
        return;
    }
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Equal){
        ui->finish->animateClick();
        return;
    }
    foreach(auto key,digitsBTNs.keys()){
        if(event->key() == key){
            digitsBTNs[key] ->animateClick();
        }
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
    double resultnum =  te_interp(input.toStdString().c_str(), 0);
    ui->lineEdit->setText(QString::number(resultnum));
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


// void MainWindow::on_pre_clicked()
// {
//     QString ori = ui->lineEdit->text();
//     if(ori.startsWith("-(")){
//         ori =  ori.mid(2,ori.length() - 3);
//     }else{
//         ori = "-(" + ori +")";
//     }
//     ui->lineEdit->setText(ori);
// }


// void MainWindow::on_C_clicked()
// {
//     QString ori = ui->lineEdit->text();
//     ui->lineEdit->setText(ori+")");
// }



