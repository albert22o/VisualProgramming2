#include "adminpanel.h"
#include <QApplication>

#include "Database/dbseeder.h"
#include "Repositories/computersrepository.h"
#include "Repositories/sessionsrepository.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminPanel w;

    DbSeeder dbSeeder;
    dbSeeder.CreateTablesIfNotExists();

    w.show();

    ComputersRepository repos;

    auto computers = repos.GetAll();

    SessionsRepository sessionRepos;

    sessionRepos.SetTable(SessionTables::Active);
    Session session;
    session.ComputerId = 1;
    session.StartOfLease = "19.12.2024/12:00";
    session.EndOfLease =
    sessionRepos.AddRecord(session);

    return a.exec();
}
