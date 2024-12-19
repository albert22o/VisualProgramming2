#ifndef NEWSEANSWINDOW_H
#define NEWSEANSWINDOW_H

#include <QDialog>
#include "Domain/computer.h"
#include "Domain/session.h"

#include "Repositories/usersrepository.h"
#include "Repositories/sessionsrepository.h"
#include "Repositories/computersrepository.h"

namespace Ui {
class NewSeansWindow;
}

class NewSeansWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewSeansWindow
    (
        UsersRepository& userRepos,
        SessionsRepository& sessionRepos,
        ComputersRepository& computerRepos,
        const Computer &computer,
        QWidget *parent = nullptr
    );

    ~NewSeansWindow();

signals:
    void SessionStarted(Session &session, const Computer& computer);

private slots:
    void on_startSession_clicked();
    void on_cancel_clicked();

private:
    Ui::NewSeansWindow *ui;

    void Setup(const Computer &computer);

    UsersRepository userRepos;
    SessionsRepository sessionRepos;
    ComputersRepository computerRepos;

    Computer computer;
};

#endif // NEWSEANSWINDOW_H
