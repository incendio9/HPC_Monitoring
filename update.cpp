#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Update() {

    static QTime time(QTime::currentTime());
    double key = time.elapsed() / 1000.0;
    static double lastPointKey = 0;

    if (key-lastPointKey > 1.000) { // at most add point every 1 ms

        QProcess *CLOProcess = new QProcess(this);
        QString CLOcommand = "sbatch";
        QString CLOscript = "/nfs/kim/cpuload.slurm";
        QStringList CLOarguments;
        CLOarguments << CLOscript;
        CLOProcess->start(CLOcommand, CLOarguments);

        QProcess *MLOProcess = new QProcess(this);
        QString MLOcommand = "sbatch";
        QString MLOscript = "/nfs/kim/memload.slurm";
        QStringList MLOarguments;
        MLOarguments << MLOscript;
        MLOProcess->start(MLOcommand, MLOarguments);

        Update_CPULoadOverview(key);
        Update_MemLoadOverview(key);

        lastPointKey = key;

    }

    return 0;

}
