#include "loginviewmodel.h"
#include "ui_loginviewmodel.h"

#include "Repositories/usersrepository.h"

LoginViewModel::LoginViewModel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginViewModel)
{
    ui->setupUi(this);

    Setup();
}

LoginViewModel::~LoginViewModel()
{
    delete ui;
}

void LoginViewModel::on_cancelButton_clicked()
{
    emit onCancelRequested();
}

void LoginViewModel::Setup(){

    ui->username->setPlaceholderText("Логин");
    ui->password->setPlaceholderText("Пароль");
    ui->password->setEchoMode(QLineEdit::Password);
}

void LoginViewModel::on_enterButton_clicked()
{
    ProcessLogin();
}

void LoginViewModel::ProcessLogin(){

    UsersRepository repos;

    auto username = ui->username->text();

    if(repos.IsUserExists(username)){

        auto password = ui->password->text();

        auto user = repos.AuthorizeUser(username, password);

        if(user != nullptr){

            OnSuccessLogin();
            emit onLoginSuccess(*user);
            return;
        }
    }

    OnWrongLogin();
}

void LoginViewModel::OnSuccessLogin(){
    ui->password->setStyleSheet(""); // default
    ui->username->setStyleSheet("");
}

void LoginViewModel::OnWrongLogin(){

    auto stylesheet = "QLineEdit { border: 2px solid red; }";

    ui->password->setStyleSheet(stylesheet);
    ui->username->setStyleSheet(stylesheet);
}

