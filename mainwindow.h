#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMap>
#include <QKeyEvent>
#include <QPushButton>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMap<int,QPushButton*> digitsBTNs;
private slots:
    void btnShowClicked();
    void on_dot_clicked();
    void on_del_clicked();
    void on_finish_clicked();
    void on_squareRoot_clicked();
    void on_inver_clicked();
    void on_ce_clicked();
    virtual void keyPressEvent(QKeyEvent* event) ;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
