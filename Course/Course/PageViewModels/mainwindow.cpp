#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTabWidget>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Setup();
}

void MainWindow::Setup(){

    mainPage = new MainPage();
    registrationPage = new RegistrationPage();
    sessionHistoryPage = new SessionsHistoryPage();
    statisticsPage = new StatisticsPage();

    ui->tabWidget->addTab(mainPage, "Главная");
    ui->tabWidget->addTab(registrationPage, "Регистрация");
    ui->tabWidget->addTab(sessionHistoryPage, "История сеансов");
    ui->tabWidget->addTab(statisticsPage, "Отчеты");
}

MainWindow::~MainWindow()
{
    delete ui;
}
