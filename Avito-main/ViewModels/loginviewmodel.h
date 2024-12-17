#ifndef LOGINVIEWMODEL_H
#define LOGINVIEWMODEL_H

#include <QWidget>

#include "Domain/user.h"

namespace Ui {
class LoginViewModel;
}

class LoginViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit LoginViewModel(QWidget *parent = nullptr);
    ~LoginViewModel();

signals:
    void onCancelRequested();
    void onLoginSuccess(const User& user);

private slots:
    void on_cancelButton_clicked();
    void on_enterButton_clicked();

private:
    Ui::LoginViewModel *ui;

    void ProcessLogin();

    void OnSuccessLogin();
    void OnWrongLogin();

    void Setup();
};

#endif // LOGINVIEWMODEL_H
