#include "registrationpage.h"
#include "ui_registrationpage.h"

#include "Repositories/usersrepository.h"

#include <QRegularExpression>

RegistrationPage::RegistrationPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegistrationPage)
{
    ui->setupUi(this);

    Setup();
}

void RegistrationPage::Setup(){
    ui->nameEdit->setPlaceholderText("Введите имя нового пользователя");
    ui->passwordEdit->setPlaceholderText("Придумайте пароль для нового пользователя");
    ui->submitPassword->setPlaceholderText("Введите пароль еще раз");
    ui->addUserButton->setEnabled(false);
}

bool RegistrationPage::IsValidUsername(const QString &username){

    if (username.length() > 100) return false;

    QRegularExpression regex("^[A-Za-z0-9]+$");
    return regex.match(username).hasMatch();
}

bool RegistrationPage::IsValidPassword(const QString &password){

    if (password.length() < 12) return false;

    QRegularExpression regex("^(?=.*\d)[A-Za-z0-9]+$");
    return regex.match(password).hasMatch();
}

void RegistrationPage::TryRegistrate(){

    auto username = ui->nameEdit->text();
    auto password = ui->passwordEdit->text();

    UsersRepository repos;

    if(!repos.IsUserExists(username)){

        User user;
        user.Login = username;
        user.Password = password;

        repos.AddRecord(user);
    }
    else{
        ui->nameValidationClue->setText("Имя занято");
        ui->nameEdit->setStyleSheet(notValidStylesheet);
    }
}

RegistrationPage::~RegistrationPage()
{
    delete ui;
}

void RegistrationPage::on_nameEdit_textChanged(const QString &arg1)
{
    if(IsValidUsername(arg1)){
        ui->nameEdit->setStyleSheet(validStylesheet);
    }
    else{
        ui->nameEdit->setStyleSheet(notValidStylesheet);
    }
}


void RegistrationPage::on_passwordEdit_textChanged(const QString &arg1)
{

}

