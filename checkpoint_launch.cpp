#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Checkpoint_Launch() {

    QString _launchPath;
    QString _checkpointPath;

    QString _launchArg1;
    QStringList _arguments;

    _launchPath = "/usr/local/bin/dmtcp_launch";
    _checkpointPath = checkpointDir;

    _launchArg1 = checkpointApp;

    _arguments << _launchArg1;

    if(!QFile::exists(checkpointApp) || checkpointApp == ""){
        QMessageBox::information(this, "Error", "Application does not exist", "OK");
        return -1;
    }

    if(!QDir(checkpointDir).exists() || checkpointDir == ""){
        QMessageBox::information(this, "Error", "Checkpoint directory does not exist", "OK");
        return -1;
    }

    if(QFile::exists(_launchPath)){

        if(LaunchProcess == NULL){
            LaunchProcess = new QProcess(this);
        }

        std::string _workingPath = _checkpointPath.toStdString();
        LaunchProcess->setWorkingDirectory(QString::fromStdString(_workingPath));

        LaunchProcess->start(_launchPath, _arguments);
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
