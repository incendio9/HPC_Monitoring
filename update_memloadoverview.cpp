#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Update_MemLoadOverview(int key) {

    totalPhysMem = memInfo.totalram;
    totalPhysMem *= memInfo.mem_unit;
    physMemUsed = memInfo.totalram - memInfo.freeram;
    physMemUsed *= memInfo.mem_unit;

    HPCNodes[0].MemLoad = (float)physMemUsed / (float)totalPhysMem * 100.0;

    FILE *memload = fopen("/nfs/kim/memload.out", "r");
    char *string = new char[1024];
    char *temp = new char[1024];
    char *token;
    while (fgets(string, 1024, memload) != NULL) {
        strcpy(temp, string);
        token = strtok(temp, " ");
        for (int i = 1; i < NodeCount + 1; i++) {
            if (strncmp(token, HPCNodes[i].NodeName, strlen(HPCNodes[i].NodeName)) == 0) {
                token = strtok(NULL, " \n");
                HPCNodes[i].MemLoad = atof(token);
            }
        }
    }

    QString label;
    for (int i = 0; i < NodeCount + 1; i++) {
        MLOChart[i].graph(0)->addData(key, (double)HPCNodes[i].MemLoad);
        MLOChart[i].xAxis->setRange(key, 8, Qt::AlignRight);
        label.sprintf("%s : %.1f", HPCNodes[i].NodeName, HPCNodes[i].MemLoad);
        MLOChart[i].xAxis->setLabel(label);
        MLOChart[i].replot();
    }

    fclose(memload);
    delete[] string;
    delete[] temp;
    //CLOProcess->terminate();
    //delete[] CLOProcess;
    return 0;

}
