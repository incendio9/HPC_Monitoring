#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Checkpoint_Setting() {
    checkpointApp = ui->lineEdit->text();
    checkpointInterval = ui->lineEdit_2->text();
    checkpointDir = ui->lineEdit_3->text();

    return 0;
}
