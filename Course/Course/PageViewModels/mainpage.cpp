#include "mainpage.h"
#include "ui_mainpage.h"

#include <QPoint>
#include <QMouseEvent>

#include "PageViewModels/newseanswindow.h"
#include "Database/TableShemas/computerstatuses.h"

MainPage::MainPage(QSqlDatabase& database, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPage),
    computerRepos(database),
    sessionRepos(database),
    usersRepos(database)
{
    ui->setupUi(this);

    Setup();
}

void MainPage::ConnectWithComputerViewModel(ComputerViewModel* computerViewModel){

    connect(computerViewModel, &ComputerViewModel::timeUpdated, this, &MainPage::OnComputerLeaseTimeChanged);
    connect(computerViewModel, &ComputerViewModel::timerStopped, this, &MainPage::OnComputerLeaseFinished);
}

void MainPage::OnComputerLeaseTimeChanged(const Computer &computer, int updatedTime){

    auto item = ui->tableWidget->item(computer.Id - 1, 3);

    auto remainTime = FormatTime(updatedTime);

    item->setText(remainTime);
}

void MainPage::OnComputerLeaseFinished(const Computer &computer){

    auto timeItem = ui->tableWidget->item(computer.Id - 1, 3);
    timeItem->setText("-");

    auto statusItem = ui->tableWidget->item(computer.Id - 1, 1);
    statusItem->setText(ComputerStatuses::Free());

    auto updatedComputer = computer;
    updatedComputer.Status = ComputerStatuses::Free();
    computerRepos.UpdateRecord(updatedComputer);

    auto session = sessionRepos.GetSessionByComputerId(computer.Id);
    session.Status = SessionsRepository::ParseStatusFrom(SessionStatus::Closed);
    sessionRepos.UpdateRecord(session);
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

    auto computers = computerRepos.GetAll();

    int i = 0;

    for(auto& comp : computers){

        auto compViewModel = new ComputerViewModel(comp);

        ConnectWithComputerViewModel(compViewModel);
        tableIdToComputer[i] = compViewModel;

        if(comp.Status == ComputerStatuses::Busy()){

            auto activeSession = sessionRepos.GetSessionByComputerId(comp.Id);

            compViewModel->StartTimer(activeSession.GetTimeDiffrenceInSeconds(QDateTime::currentDateTime()));
        }

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

    for(auto& rowId : tableIdToComputer.keys()) {

        auto comp = tableIdToComputer[rowId]->GetComputer();

        ui->tableWidget->insertRow(rowId);

        ui->tableWidget->setItem(rowId, 0, new QTableWidgetItem(comp.Name));
        ui->tableWidget->setItem(rowId, 1, new QTableWidgetItem(comp.Status));
        ui->tableWidget->setItem(rowId, 2, new QTableWidgetItem(ComputerRateConverter::ParseRate(comp.Rate)));

        if(comp.Status == ComputerStatuses::Busy()) {

            auto activeSession = sessionRepos.GetSessionByComputerId(comp.Id);
            auto remainTimeInSeconds = activeSession.GetTimeDiffrenceInSeconds(QDateTime::currentDateTime());

            auto remainTime = FormatTime(remainTimeInSeconds);

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
        ui->endSession->setEnabled(true);
    }
}

void MainPage::on_startSession_clicked()
{
    QTableWidgetItem* currentItem = ui->tableWidget->currentItem();

    if(currentItem != nullptr){

        int computerId = currentItem->row();

        auto computer = tableIdToComputer[computerId]->GetComputer();

        NewSeansWindow *newSeansDialog = new NewSeansWindow
        (
            usersRepos,
            sessionRepos,
            computerRepos,
            computer
        );

        connect(newSeansDialog, &NewSeansWindow::SessionStarted, this, &MainPage::OnNewSessionStarted);
        newSeansDialog->exec();
    }
}

void MainPage::OnNewSessionStarted(Session &session, const Computer& computer){

    ui->tableWidget->setItem(computer.Id - 1, 1,
        new QTableWidgetItem(computer.Status));

    auto time = FormatTime(session.GetTimeDiffrenceInSeconds());

    ui->tableWidget->setItem(computer.Id - 1, 3, new QTableWidgetItem(time));

    tableIdToComputer[computer.Id - 1]->SetComputerStatus(ComputerStatuses::Busy());

    tableIdToComputer[computer.Id - 1]->StartTimer(session.GetTimeDiffrenceInSeconds());
}

QString MainPage::FormatTime(int seconds){

    int days = seconds / (24 * 3600);
    seconds %= (24 * 3600);
    int hours = seconds / 3600;
    seconds %= 3600;
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;

    QString result;

    if (days > 0) {
        result += QString("%1 дн. ").arg(days);
    }
    if (hours > 0) {
        result += QString("%1 ч. ").arg(hours);
    }
    if (minutes > 0) {
        result += QString("%1 мин. ").arg(minutes);
    }
    result += QString("%1 сек.").arg(remainingSeconds);

    return result.trimmed();
}

void MainPage::on_endSession_clicked()
{
    QTableWidgetItem* currentItem = ui->tableWidget->currentItem();

    if(currentItem != nullptr){

        int computerId = currentItem->row();

        auto computerViewModel = tableIdToComputer[computerId];
        auto computer = computerViewModel->GetComputer();

        if(computer.Status == ComputerStatuses::Busy()){

            OnComputerLeaseFinished(computer);
            tableIdToComputer[computer.Id - 1]->SetComputerStatus(ComputerStatuses::Free());
            computerViewModel->StopTimer();
        }
    }
}
