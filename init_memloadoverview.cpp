#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Init_MemLoadOverview() {

    totalPhysMem = memInfo.totalram;
    totalPhysMem *= memInfo.mem_unit;

    MLOChart = new QCustomPlot[NodeCount + 1];
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");

    int perColumn = (int)ceil(sqrt((double)(NodeCount + 1)));
    for (int i = 0; i < NodeCount + 1; i++) {
        MLOChart[i].addGraph();
        MLOChart[i].graph(0)->setPen(QPen(QColor(255, 0, 0)));
        MLOChart[i].xAxis->setLabelFont(QFont("Consolas", 10, 0,false));
        MLOChart[i].xAxis->setLabel(HPCNodes[i].NodeName);
        MLOChart[i].xAxis->setLabelPadding(5);
        MLOChart[i].xAxis->setTicker(timeTicker);
        MLOChart[i].axisRect()->setupFullAxesBox();
        MLOChart[i].yAxis->setRange(0, 100);
        ui->gridLayout_4->addWidget(&MLOChart[i], (int)(i / perColumn), i % perColumn);
    }

    //delete[] string;

    //printf("Init CPULoadOverview done\n");
    return 0;

}
