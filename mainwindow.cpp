#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    FILE *slurm_conf = fopen("/etc/slurm-llnl/slurm.conf", "r");
    char *string = new char[1024];
    NodeCount = 0;

    while (fgets(string, 1024, slurm_conf) != NULL) {
        if (strncmp(string, "NodeName", 8) == 0) {
            NodeCount++;
        }
    }
    HPCNodes = new nodelist[NodeCount + 1];

    fseek(slurm_conf, 0, SEEK_SET);
    char *token;
    int n = 0;
    while (fgets(string, 1024, slurm_conf) != NULL) {
        if (strncmp(string, "NodeName", 8) == 0) {
            n++;
            HPCNodes[n].NodeNum = n;
            token = strtok(string, " =\n");
            token = strtok(NULL, " =\n");
            HPCNodes[n].NodeName = new char[strlen(token) + 1];
            strcpy(HPCNodes[n].NodeName, token);
        } else if (strncmp(string, "ControlMachine", 13) == 0) {
            HPCNodes[0].NodeNum = 0;
            token = strtok(string, " =\n");
            token = strtok(NULL, " =\n");
            HPCNodes[0].NodeName = new char[strlen(token) + 1];
            strcpy(HPCNodes[0].NodeName, token);
        }
    }

    delete[] string;

    Init_CPULoadOverview();
    Init_MemLoadOverview();

    QTimer *dataTimer = new QTimer(this);
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(Update()));
    dataTimer->start(100);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Checkpoint_Start_Coordinator()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(Checkpoint_Launch()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(Checkpoint_Restart()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(Checkpoint_Setting()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(Checkpoint_Reset()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(Checkpoint_Close()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(Checkpoint_Optimal()));

    fclose(slurm_conf);

}

MainWindow::~MainWindow()
{
    for (int i = 0; i < NodeCount; i++)
        delete[] HPCNodes[i].NodeName;
    delete[] HPCNodes;
    delete[] CLOChart;
    delete[] MLOChart;
    delete ui;
}
