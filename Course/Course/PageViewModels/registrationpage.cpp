#include "registrationpage.h"
#include "ui_registrationpage.h"

#include <QRegularExpression>
#include <QMessageBox>
#include <QTimer>

RegistrationPage::RegistrationPage(QSqlDatabase& db, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegistrationPage),
    repos(db)
{
    ui->setupUi(this);

    Setup();
}

void RegistrationPage::Setup(){

    ui->nameEdit->setPlaceholderText("Введите имя нового пользователя");
    ui->passwordEdit->setPlaceholderText("Придумайте пароль для нового пользователя");
    ui->submitPassword->setPlaceholderText("Введите пароль еще раз");
    ui->addUserButton->setEnabled(false);
    ui->submitPassword->setEnabled(false);

    ui->nameValidationClue->setVisible(false);
    ui->passwordValidationClue->setVisible(false);
    ui->submitPasswordValidationClue->setVisible(false);

    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->submitPassword->setEchoMode(QLineEdit::Password);
}

bool RegistrationPage::IsValidUsername(const QString &username){

    if (username.length() > 100) return false;

    QRegularExpression regex("^[A-Za-z0-9]+$");
    return regex.match(username).hasMatch();
}

void RegistrationPage::OnSuccessRegistration(const User& user){

    QMessageBox *msgBox = new QMessageBox();
    msgBox->setText("Пользователь, " + user.Login + " зарегистрирован");

    QTimer *timer = new QTimer();

    auto timeoutSecs = 3;

    QObject::connect(timer, &QTimer::timeout, [msgBox, &timeoutSecs, timer]() {
        timeoutSecs--;
        if (timeoutSecs == 0) {
            msgBox->close();
        }
    });

    timer->start(1000);

    QObject::connect(msgBox, &QMessageBox::finished, [timer]() {
        timer->stop();
        timer->deleteLater();
    });

    msgBox->exec();
}

bool RegistrationPage::IsValidPassword(const QString &password){

    if (password.length() < 8 && password.length() > 32) return false;

    QRegularExpression regex("^[^\sа-яА-ЯЁё]+$");

    return regex.match(password).hasMatch();
}

bool RegistrationPage::IsAllFieldsValidated(){

    if(isUserNameValid && isPasswordValid && isSubmitPasswordValid){
        return true;
    }

    return false;
}

bool RegistrationPage::TryRegistrate(){

    auto username = ui->nameEdit->text();
    auto password = ui->passwordEdit->text();

    if(!repos.IsUserExists(username)){

        User user;
        user.Login = username;
        user.Password = password;

        repos.AddRecord(user);

        OnSuccessRegistration(user);

        return true;
    }
    else{
        isUserNameValid = false;
        OnEditAction();
        ui->nameValidationClue->setText("Имя занято");
        ui->nameValidationClue->setVisible(true);
        ui->nameEdit->setStyleSheet(notValidStylesheet);
    }

    return false;
}

RegistrationPage::~RegistrationPage()
{
    delete ui;
}

void RegistrationPage::OnEditAction(){

    if(IsAllFieldsValidated()){
        ui->addUserButton->setEnabled(true);
    }
    else{
        ui->addUserButton->setEnabled(false);
    }
}

void RegistrationPage::on_nameEdit_textChanged(const QString &arg1)
{
    ui->nameValidationClue->setText("Только латинские буквы и цифры, макс длина 100 символов");

    if(IsValidUsername(arg1)){
        ui->nameEdit->setStyleSheet(validStylesheet);
        isUserNameValid = true;
        ui->nameValidationClue->setVisible(false);
    }
    else{
        isUserNameValid = false;
        ui->nameEdit->setStyleSheet(notValidStylesheet);
        ui->nameValidationClue->setVisible(true);
    }

    OnEditAction();
}

void RegistrationPage::on_passwordEdit_textChanged(const QString &arg1)
{
    ui->passwordValidationClue->setText("Мин. длина 8-32 символа, только латинские буквы");

    if(IsValidPassword(arg1)){
        isPasswordValid = true;
        ui->passwordEdit->setStyleSheet(validStylesheet);
        ui->submitPassword->setEnabled(true);
        ui->passwordValidationClue->setVisible(false);
    }
    else{
        isPasswordValid = false;
        ui->passwordEdit->setStyleSheet(notValidStylesheet);
        ui->submitPassword->clear();
        ui->submitPassword->setStyleSheet(notValidStylesheet);
        ui->submitPassword->setEnabled(false);
        ui->passwordValidationClue->setVisible(true);
        ui->submitPasswordValidationClue->setVisible(true);
    }

    OnEditAction();
}

void RegistrationPage::on_submitPassword_textChanged(const QString &arg1)
{
    ui->submitPasswordValidationClue->setText("Пароли должны совпадать");

    if(ui->passwordEdit->text() == ui->submitPassword->text()){
        isSubmitPasswordValid = true;
        ui->submitPassword->setStyleSheet(validStylesheet);
        ui->submitPasswordValidationClue->setVisible(false);
    }
    else{
        isSubmitPasswordValid = false;
        ui->submitPassword->setStyleSheet(notValidStylesheet);
        ui->submitPasswordValidationClue->setVisible(true);
    }

    OnEditAction();
}

void RegistrationPage::on_addUserButton_clicked()
{
    TryRegistrate();
}

void RegistrationPage::on_clearFields_clicked()
{
    ui->nameEdit->clear();
    ui->passwordEdit->clear();
    ui->submitPassword->clear();

    ui->nameValidationClue->setVisible(false);
    ui->passwordValidationClue->setVisible(false);
    ui->submitPasswordValidationClue->setVisible(false);

    ui->nameEdit->setStyleSheet("");
    ui->passwordEdit->setStyleSheet("");
    ui->submitPassword->setStyleSheet("");
}

