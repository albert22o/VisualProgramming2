#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QWidget>

namespace Ui {
class RegistrationPage;
}

class RegistrationPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationPage(QWidget *parent = nullptr);
    ~RegistrationPage();

private slots:
    void on_nameEdit_textChanged(const QString &arg1);

    void on_passwordEdit_textChanged(const QString &arg1);

private:
    QString validStylesheet = "QTextEdit { border: 2px solid green; }";
    QString notValidStylesheet = "QTextEdit { border: 2px solid red; }";

    void Setup();
    void TryRegistrate();
    Ui::RegistrationPage *ui;

    bool IsValidUsername(const QString &username);
    bool IsValidPassword(const QString &password);
};

#endif // REGISTRATIONPAGE_H
