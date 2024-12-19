#include "mainpage.h"
#include "ui_mainpage.h"

#include <QPoint>
#include <QMouseEvent>

#include "Repositories/computersrepository.h"
#include "Repositories/sessionsrepository.h"

#include "PageViewModels/newseanswindow.h"
#include "Database/TableShemas/computerstatuses.h"

MainPage::MainPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);

    Setup();
}

void MainPage::ConnectWithComputerViewModel(ComputerViewModel* computerViewModel){

    connect(computerViewModel, &ComputerViewModel::timeUpdated, this, &MainPage::OnComputerLeaseTimeChanged);
    connect(computerViewModel, &ComputerViewModel::timerStopped, this, &MainPage::OnComputerLeaseFinished);
}

void MainPage::OnComputerLeaseTimeChanged(const Computer &computer, int updatedTime){

    auto item = ui->tableWidget->item(computer.Id, 3);
    auto remainTime = ToDayHoursMinutesView(updatedTime);

    item->setText(remainTime);
}

void MainPage::OnComputerLeaseFinished(const Computer &computer){

    auto timeItem = ui->tableWidget->item(computer.Id, 3);
    timeItem->setText("---");

    auto statusItem = ui->tableWidget->item(computer.Id, 1);
    statusItem->setText("Free");
}

void MainPage::Setup(){
    GetComputers();
    CreateComputerTable();
    ui->sessionInfo->setText("Выберете свободный компьютер");
    ui->startSession->setEnabled(false);
    ui->endSession->setEnabled(false);
}

void MainPage::mouseReleaseEvent(QMouseEvent *event){

    QWidget::mouseReleaseEvent(event);
    ui->tableWidget->clearSelection();
    ui->startSession->setEnabled(false);
    ui->endSession->setEnabled(false);
    ui->sessionInfo->setText("Выберите свободный компьютер");
}

void MainPage::GetComputers(){

    ComputersRepository repos;
    auto computers = repos.GetAll();

    int i = 0;

    for(auto& comp : computers){
        auto compViewModel = new ComputerViewModel(comp);
        ConnectWithComputerViewModel(compViewModel);
        tableIdToComputer[i] = compViewModel;
        i++;
    }
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::CreateComputerTable(){

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);

    ui->tableWidget->setHorizontalHeaderLabels({"Компьютер", "Статус", "Тариф", "Время"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    SessionsRepository repos;

    for(auto& rowId : tableIdToComputer.keys()) {

        auto comp = tableIdToComputer[rowId]->GetComputer();

        ui->tableWidget->insertRow(rowId);

        ui->tableWidget->setItem(rowId, 0, new QTableWidgetItem(comp.Name));
        ui->tableWidget->setItem(rowId, 1, new QTableWidgetItem(comp.Status));
        ui->tableWidget->setItem(rowId, 2, new QTableWidgetItem(ComputerRateConverter::ParseRate(comp.Rate)));

        if(comp.Status == SessionsRepository::ParseStatusFrom(SessionStatus::Active)) {

            auto activeSession = repos.GetSessionByComputerId(comp.Id);
            auto remainTimeInMinutes = activeSession.GetTimeDiffrenceInMinuters(QDateTime::currentDateTime());

            auto remainTime = ToDayHoursMinutesView(remainTimeInMinutes);

            ui->tableWidget->setItem(rowId, 3, new QTableWidgetItem(remainTime));
        } else {
            ui->tableWidget->setItem(rowId, 3, new QTableWidgetItem("-"));
        }
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

    if(status == ComputerStatuses::Free()){
        ui->startSession->setEnabled(true);
        ui->endSession->setEnabled(false);
    }
    else{
        ui->startSession->setEnabled(false);
    }
}


void MainPage::on_startSession_clicked()
{
    QTableWidgetItem* currentItem = ui->tableWidget->currentItem();

    if(currentItem != nullptr){
        int computerId = currentItem->row();
        NewSeansWindow newSeansDialog(tableIdToComputer[computerId]->GetComputer());
        newSeansDialog.exec();
    }
}

QString MainPage::ToDayHoursMinutesView(int minutes){

    int days = minutes / (24 * 60);
    int hours = (minutes % (24 * 60)) / 60;
    int min = minutes % 60;

    QString result;

    if (days > 0) {
        result.append(QString("%1 дн.").arg(days));
    }
    if (hours > 0) {
        if (!result.isEmpty()) result.append(", ");
        result.append(QString("%1 час.").arg(hours));
    }
    if (min > 0 || (days == 0 && hours == 0)) {
        if (!result.isEmpty()) result.append(", ");
        result.append(QString("%1 мин.").arg(min));
    }

    return result;
}


