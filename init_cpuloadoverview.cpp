#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Init_CPULoadOverview() {

    FILE* file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &lastTotalUser, &lastTotalUserLow, &lastTotalSys, &lastTotalIdle);
    fclose(file);

    CLOChart = new QCustomPlot[NodeCount + 1];
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");

    int perColumn = (int)ceil(sqrt((double)(NodeCount + 1)));
    for (int i = 0; i < NodeCount + 1; i++) {
        CLOChart[i].addGraph();
        CLOChart[i].graph(0)->setPen(QPen(QColor(255, 0, 0)));
        CLOChart[i].xAxis->setLabelFont(QFont("Consolas", 10, 0,false));
        CLOChart[i].xAxis->setLabel(HPCNodes[i].NodeName);
        CLOChart[i].xAxis->setLabelPadding(5);
        CLOChart[i].xAxis->setTicker(timeTicker);
        CLOChart[i].axisRect()->setupFullAxesBox();
        CLOChart[i].yAxis->setRange(0, 100);
        ui->gridLayout_2->addWidget(&CLOChart[i], (int)(i / perColumn), i % perColumn);
    }

    //delete[] string;

    //printf("Init CPULoadOverview done\n");
    return 0;

}
