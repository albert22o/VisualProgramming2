#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QWidget>
#include "Repositories/usersrepository.h"

namespace Ui {
class RegistrationPage;
}

class RegistrationPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationPage(QSqlDatabase& db, QWidget *parent = nullptr);
    ~RegistrationPage();

private slots:
    void on_nameEdit_textChanged(const QString &arg1);

    void on_passwordEdit_textChanged(const QString &arg1);

    void on_submitPassword_textChanged(const QString &arg1);

    void on_addUserButton_clicked();

    void on_clearFields_clicked();

private:
    QString validStylesheet = "QLineEdit { border: 2px solid green; }";
    QString notValidStylesheet = "QLineEdit { border: 2px solid red; }";

    void Setup();
    bool TryRegistrate();
    Ui::RegistrationPage *ui;

    bool IsValidUsername(const QString &username);
    bool IsValidPassword(const QString &password);

    bool isUserNameValid = false;
    bool isPasswordValid = false;
    bool isSubmitPasswordValid = false;

    bool IsAllFieldsValidated();
    void OnEditAction();

    void OnSuccessRegistration(const User& user);

    UsersRepository repos;
};

#endif // REGISTRATIONPAGE_H
