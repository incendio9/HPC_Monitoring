#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"
#include <math.h>

int MainWindow::Checkpoint_Optimal() {



    QString _launchArg1;
    QString _launchArg2;
    QString _launchArg3;
    float _launchArg4;
    QString _Optimal_interval;


    _launchArg1 = ui->lineEdit_5->text();//= .toFloat();//Fault_Rate
    _launchArg2 = ui->lineEdit_4->text();//= .toFloat();//Execution_Time
    _launchArg3 = ui->lineEdit_6->text();//= .toFloat();//Checkpoint_Time
    //_Optimal_interval;//= ui->label_8->text().toFloat()
    /*
    if(!QFile::exists(Fault_Rate) || Fault_Rate == NULL){
        QMessageBox::information(this, "Error", "Fault Rate does not exist", "OK");
        return -1;
    }
    if(!!QFile::exists(Execution_Time) || Execution_Time == NULL){
        QMessageBox::information(this, "Error", "Execution Time does not exist", "OK");
        return -1;
    }
    if(!QFile::exists(Checkpoint_Time) || Checkpoint_Time == NULL){
        QMessageBox::information(this, "Error", "Execution Time does not exist", "OK");
        return -1;
    }*/
    _launchArg4 = sqrt(((_launchArg1.toFloat() * _launchArg3.toFloat() * _launchArg3.toFloat()) + _launchArg3.toFloat() + (_launchArg2.toFloat() * _launchArg3.toFloat()))/_launchArg1.toInt());
    _Optimal_interval = QString::number(_launchArg4);
    ui->label_8->setText(QString("%1 (s)").arg(_Optimal_interval));

    return 0;

}
