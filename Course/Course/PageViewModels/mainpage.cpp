#include "mainpage.h"
#include "ui_mainpage.h"

#include <QPoint>
#include <QMouseEvent>

#include "Repositories/computersrepository.h"
#include "Repositories/sessionsrepository.h"

MainPage::MainPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);

    Setup();
}

void MainPage::Setup(){
    CreateComputerTable();
    ui->sessionInfo->setText("Выберете свободный компьютер");
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::CreateComputerTable(){

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);

    ui->tableWidget->setHorizontalHeaderLabels({"Компьютер", "Статус", "Тариф", "Время"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ComputersRepository repos;
    auto computers = repos.GetAll();

    int i = 0;
    for(auto& comp : computers) {
        ui->tableWidget->insertRow(i);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(comp.Name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(comp.Status));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(ComputerRateConverter::ParseRate(comp.Rate)));

        if(comp.Status == SessionsRepository::ParseStatusFrom(SessionStatus::Active)) {
            auto remainTime = ""; // Здесь нужно добавить логику для расчета времени
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(remainTime));
        } else {
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("-"));
        }

        i++;
    }
}

void MainPage::on_tableWidget_cellClicked(int row, int column)
{
    QString computerName = ui->tableWidget->item(row, 0)->text();
    QString status = ui->tableWidget->item(row, 1)->text();
    QString time = ui->tableWidget->item(row, 2)->text();

    ui->sessionInfo->setText(QString("Информация о компьютере: %1 | Статус: %2 | Время: %3")
                             .arg(computerName, status, time));
    selectedRow = row;
}

