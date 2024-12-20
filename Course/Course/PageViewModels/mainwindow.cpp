#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTabWidget>
#include <QMouseEvent>

MainWindow::MainWindow(QSqlDatabase& db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Setup(db);
}

void MainWindow::Setup(QSqlDatabase& db){

    mainPage = new MainPage(db);
    registrationPage = new RegistrationPage(db);
    sessionHistoryPage = new SessionsHistoryPage(db);
    statisticsPage = new StatisticsPage(db);

    ui->tabWidget->addTab(mainPage, "Главная");
    ui->tabWidget->addTab(registrationPage, "Регистрация");
    ui->tabWidget->addTab(sessionHistoryPage, "История сеансов");
    ui->tabWidget->addTab(statisticsPage, "Отчеты");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    auto statisticsPage = qobject_cast<StatisticsPage*>(ui->tabWidget->widget(index));

    if(statisticsPage){
        statisticsPage->UpdateView();
    }
}

