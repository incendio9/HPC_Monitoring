#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Checkpoint_Reset() {
    checkpointApp = "";
    ui->lineEdit->setText("");
    checkpointInterval = "";
    ui->lineEdit_2->setText("");
    checkpointDir = "";
    ui->lineEdit_3->setText("");
    //Execution_Time = "";
    ui->lineEdit_4->setText("");
    //Fault_Rate = "";
    ui->lineEdit_5->setText("");

    return 0;
}
