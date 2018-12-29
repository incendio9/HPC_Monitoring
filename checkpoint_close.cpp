#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Checkpoint_Close() {
    if(CoordinatorProcess){
        if(CoordinatorProcess->state() == QProcess::Running){
            CoordinatorProcess->close();
        }

        delete CoordinatorProcess;
        CoordinatorProcess = NULL;
    }

    if(LaunchProcess){
        if(LaunchProcess->state() == QProcess::Running){
            LaunchProcess->close();
        }

        delete LaunchProcess;
        LaunchProcess = NULL;
    }

    if(RestartProcess){
        if(RestartProcess->state() == QProcess::Running){
            RestartProcess->close();
        }

        delete RestartProcess;
        RestartProcess = NULL;
    }

    return 0;
}
