#include "newseanswindow.h"
#include "ui_newseanswindow.h"

#include "Repositories/usersrepository.h"
#include "Repositories/sessionsrepository.h"
#include "Repositories/computersrepository.h"

#include "Database/TableShemas/computerstatuses.h"

NewSeansWindow::NewSeansWindow
(
    UsersRepository& userRepos,
    SessionsRepository& sessionRepos,
    ComputersRepository& computerRepos,
    const Computer &computer,
    QWidget *parent
)
    : QDialog(parent)
    , ui(new Ui::NewSeansWindow),
    userRepos(userRepos),
    sessionRepos(sessionRepos),
    computerRepos(computerRepos)
{
    ui->setupUi(this);

    Setup(computer);
}

NewSeansWindow::~NewSeansWindow()
{
    delete ui;
}

void NewSeansWindow::Setup(const Computer &computer){

    this->computer = computer;

    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    ui->startOfLease->setDateTime(QDateTime::currentDateTime().addSecs(25200));

    ui->nameEdit->setPlaceholderText("Введите имя пользователя");
    ui->passwordEdit->setPlaceholderText("Введите пароль от аккауунта");
    ui->computerInformation->setText("Компьютер: " + computer.Name + " Тариф: " + ComputerRateConverter::ParseRate(computer.Rate));

    ui->duration->setMinimumTime(QTime(0,1));
}

void NewSeansWindow::on_startSession_clicked()
{
    auto login = ui->nameEdit->text();
    auto password = ui->passwordEdit->text();

    User* user = userRepos.AuthorizeUser(login, password);

    if(user != nullptr){

        Session session;

        session.ComputerId = computer.Id;
        session.Status = sessionRepos.ParseStatusFrom(SessionStatus::Active);
        session.StartOfLease = QDateTime::currentDateTime().toString("dd.MM.yyyy/HH:mm:ss");
        session.UserId = user->Id;

        auto duration = ui->duration->time();
        int totalSeconds = duration.hour() * 3600 + duration.minute() * 60 + duration.second();

        auto endOfLease = QDateTime::currentDateTime().addSecs(totalSeconds);

        session.EndOfLease = endOfLease.toString("dd.MM.yyyy/HH:mm:ss");

        sessionRepos.AddRecord(session);

        auto updatedComputer = computer;
        updatedComputer.Status = ComputerStatuses::Busy();
        computerRepos.UpdateRecord(updatedComputer);

        emit SessionStarted(session, updatedComputer);

        close();
    }

    ui->passwordEdit->setStyleSheet("QLineEdit { border: 2px solid red; }");
    ui->nameEdit->setStyleSheet("QLineEdit { border: 2px solid red; }");
    ui->clue->setText("Неверный логин или пароль");
}


void NewSeansWindow::on_cancel_clicked()
{
    close();
}

