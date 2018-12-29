#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Checkpoint_Start_Coordinator() {

    QString _coordinatorPath;
    QString _checkpointPath;

    QString _launchArg1;
    QString _launchArg2;
    QString _launchArg3;
    QString _launchArg4;
    QStringList _arguments;

    _coordinatorPath = "/usr/local/bin/dmtcp_coordinator";
    _checkpointPath = checkpointDir;

    _launchArg1 = "--ckptdir";
    _launchArg2 = checkpointDir;
    _launchArg3 = "-i";
    _launchArg4 = checkpointInterval;

    _arguments << _launchArg1 << _launchArg2 << _launchArg3 << _launchArg4;

    if(!QDir(checkpointDir).exists() || checkpointDir == ""){
        QMessageBox::information(this, "Error", "Checkpoint directory does not exist", "OK");
        return -1;
    }

    if(checkpointInterval == ""){
        QMessageBox::information(this, "Error", "Interval unknown", "OK");
        return -1;
    }

    if(QFile::exists(_coordinatorPath)){

        if(CoordinatorProcess == NULL){
            CoordinatorProcess = new QProcess(this);
        }

        std::string _workingPath = _checkpointPath.toStdString();
        CoordinatorProcess->setWorkingDirectory(QString::fromStdString(_workingPath));

        CoordinatorProcess->start(_coordinatorPath, _arguments);
    }
    else{
        QMessageBox::information(this, "Error", "dmtcp is not found", "OK");
        return -1;
    }
/*
    Process = new QProcess(this);
    Process->start("/usr/local/bin/dmtcp_coordinator");
*/
    return 0;

}
