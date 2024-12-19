#include "newseanswindow.h"
#include "ui_newseanswindow.h"

#include "Repositories/usersrepository.h"

NewSeansWindow::NewSeansWindow(const Computer &computer, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewSeansWindow)
{
    ui->setupUi(this);

    Setup(computer);
}

NewSeansWindow::~NewSeansWindow()
{
    delete ui;
}

void NewSeansWindow::Setup(const Computer &computer){

    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    ui->startOfLease->setDateTime(QDateTime::currentDateTime().addSecs(25200));

    ui->nameEdit->setPlaceholderText("Введите имя пользователя");
    ui->passwordEdit->setPlaceholderText("Введите пароль от аккауунта");
    ui->computerInformation->setText("Компьютер: " + computer.Name + " Тариф: " + ComputerRateConverter::ParseRate(computer.Rate));
}

void NewSeansWindow::on_startSession_clicked()
{
    UsersRepository repos;

    auto login = ui->nameEdit->text();
    auto password = ui->passwordEdit->text();

    if(repos.AuthorizeUser(login, password) != nullptr){
        // запуск сеанса
        close();
    }
    else{
        ui->passwordEdit->setStyleSheet("QLineEdit { border: 2px solid red; }");
        ui->nameEdit->setStyleSheet("QLineEdit { border: 2px solid red; }");
        ui->clue->setText("Неверный логин или пароль");
    }
}


void NewSeansWindow::on_cancel_clicked()
{
    close();
}

