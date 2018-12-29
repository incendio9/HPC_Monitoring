#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Update_CPULoadOverview(int key) {

    FILE *file = fopen("/proc/stat", "r");
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;
    fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow, &totalSys, &totalIdle);
    fclose(file);
    double percent = 0.00;
    if (totalUser < lastTotalUser || totalUserLow < lastTotalUserLow || totalSys < lastTotalSys || totalIdle < lastTotalIdle){
            percent = -1.0;
    }
    else{
        total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow) + (totalSys - lastTotalSys);
        percent = total;
        total += (totalIdle - lastTotalIdle);
        percent /= total;
        percent *= 100;
    }

    lastTotalUser = totalUser;
    lastTotalUserLow = totalUserLow;
    lastTotalSys = totalSys;
    lastTotalIdle = totalIdle;

    HPCNodes[0].CPULoad = (float)percent;

    FILE *cpuload = fopen("/nfs/kim/cpuload.out", "r");
    char *string = new char[1024];
    char *temp = new char[1024];
    char *token;
    while (fgets(string, 1024, cpuload) != NULL) {
        strcpy(temp, string);
        token = strtok(temp, " ");
        for (int i = 1; i < NodeCount + 1; i++) {
            if (strncmp(token, HPCNodes[i].NodeName, strlen(HPCNodes[i].NodeName)) == 0) {
                token = strtok(NULL, " \n");
                HPCNodes[i].CPULoad = atof(token);
            }
        }
    }

    QString label;
    for (int i = 0; i < NodeCount + 1; i++) {
        CLOChart[i].graph(0)->addData(key, (double)HPCNodes[i].CPULoad);
        CLOChart[i].xAxis->setRange(key, 8, Qt::AlignRight);
        label.sprintf("%s : %.1f", HPCNodes[i].NodeName, HPCNodes[i].CPULoad);
        CLOChart[i].xAxis->setLabel(label);
        CLOChart[i].replot();
    }

    fclose(cpuload);
    delete[] string;
    delete[] temp;
    //CLOProcess->terminate();
    //delete[] CLOProcess;
    return 0;

}
