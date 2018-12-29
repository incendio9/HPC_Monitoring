#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <QProcess>
#include <nvml.h>
#include "sys/types.h"
#include "sys/sysinfo.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "qcustomplot.h"

struct nodelist {

    int NodeNum;
    char *NodeName;
    float CPULoad;
    float MemLoad;

};

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    // CPULoadOverview
    int Init_CPULoadOverview();
    int Update_CPULoadOverview(int key);

    // MemLoadOverview
    int Init_MemLoadOverview();
    int Update_MemLoadOverview(int key);

    ~MainWindow();


private:

    Ui::MainWindow *ui;

    int NodeCount;
    nodelist *HPCNodes;

    // CPULoadOverview
    QCustomPlot *CLOChart;
    unsigned long long lastTotalUser, lastTotalUserLow, lastTotalSys, lastTotalIdle;

    // MemLoadOverview
    struct sysinfo memInfo;
    QCustomPlot *MLOChart;
    long long totalPhysMem;
    long long physMemUsed;

    // Checkpoint
    QProcess* CoordinatorProcess = NULL;
    QProcess* LaunchProcess = NULL;
    QProcess* RestartProcess = NULL;
    QString checkpointApp;
    QString checkpointInterval;
    QString checkpointDir;
    QString Execution_Time;
    QString Checkpoint_Time;
    QString Fault_Rate;


private slots:

    int Update();

    // Checkpoint
    int Checkpoint_Start_Coordinator();
    int Checkpoint_Launch();
    int Checkpoint_Restart();
    int Checkpoint_Setting();
    int Checkpoint_Reset();
    int Checkpoint_Close();
    int Checkpoint_Optimal();

};

#endif // MAINWINDOW_H
