#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Checkpoint_Restart() {

    QString _restartPath;
    QString _checkpointPath;

    _restartPath = checkpointDir + "/dmtcp_restart_script.sh";
    _checkpointPath = checkpointDir;

    if(!QDir(checkpointDir).exists() || checkpointDir == ""){
        QMessageBox::information(this, "Error", "Checkpoint directory does not exist", "OK");
        return -1;
    }

    if(QFile::exists(_restartPath)){

        if(RestartProcess == NULL){
            RestartProcess = new QProcess(this);
        }

        std::string _workingPath = _checkpointPath.toStdString();
        RestartProcess->setWorkingDirectory(QString::fromStdString(_workingPath));

        RestartProcess->start(_restartPath);
    }
    else{
        QMessageBox::information(this, "Error", "Checkpoint file is not found", "OK");
    }
/*
    Process = new QProcess(this);
    Process->start("/usr/local/bin/dmtcp_coordinator");
*/
    return 0;

}
