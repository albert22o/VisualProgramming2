#ifndef SESSIONSHISTORYPAGE_H
#define SESSIONSHISTORYPAGE_H

#include <QWidget>
#include <QSqlDatabase>

#include <QStandardItemModel>

#include "Repositories/sessionsrepository.h"
#include "Repositories/usersrepository.h"
#include "Repositories/computersrepository.h"

namespace Ui {
class SessionsHistoryPage;
}

class SessionsHistoryPage : public QWidget
{
    Q_OBJECT

public:
    explicit SessionsHistoryPage(QSqlDatabase& db, QWidget *parent = nullptr);
    ~SessionsHistoryPage();

private:
    Ui::SessionsHistoryPage *ui;

    QStandardItemModel *model; // Указатель на модель

    SessionsRepository sessionRepos;
    UsersRepository userRepos;
    ComputersRepository computerRepos;
};

#endif // SESSIONSHISTORYPAGE_H
