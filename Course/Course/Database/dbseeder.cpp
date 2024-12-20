#include "dbseeder.h"

#include "TableShemas/computershema.h"
#include "TableShemas/sessionshema.h"
#include "TableShemas/usershema.h"
#include "TableShemas/computerstatuses.h"

#include <QSqlQuery>
#include <QDateTime>
#include <QSqlError>

void DbSeeder::SeedComputers(){

    QSqlQuery query(db);

    QString checkComputersQuery = "SELECT COUNT(*) FROM Computers";

    if (!query.exec(checkComputersQuery)) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    query.next();

    int count = query.value(0).toInt();

    if(count < 10){

        QString deleteQuery = "DELETE FROM Computers";

        if (!query.exec(deleteQuery)) {
            throw std::runtime_error(query.lastError().text().toStdString());
        }

        QStringList computerNames = {"PC-1", "PC-2", "PC-3", "PC-4", "PC-5",
                                     "PC-6", "PC-7", "PC-8", "PC-9", "PC-10"};
        QStringList statuses;

        for(int i=0;i<10;i++){

            auto free = ComputerStatuses::Free();
            statuses.push_back(free);
        }

        QList<int> rates;

        for(int i=0;i<10;i++){
            rates.push_back(i % 3);
        }

        for (int i = 0; i < 10; ++i) {

            query.prepare("INSERT INTO Computers (Name, Status, Rate) VALUES (:name, :status, :rate)");
            query.bindValue(":name", computerNames[i]);
            query.bindValue(":status", statuses[i]);
            query.bindValue(":rate", rates[i]);

            if (!query.exec()) {
                throw std::runtime_error(query.lastError().text().toStdString());
            }
        }
    }
}

QSqlDatabase DbSeeder::GetDb(){
    return db;
}

DbSeeder::DbSeeder() {

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("computer_club.db");
}

void DbSeeder::ChangedOutdatedStatuses(){

    OpenDbConnection();

    QDateTime currentTime = QDateTime::currentDateTime();

    QSqlQuery sessionQuery(db);
    sessionQuery.prepare("SELECT Id, EndTime FROM Sessions WHERE Status = 'Active'");

    if (!sessionQuery.exec()) {
        throw std::runtime_error(sessionQuery.lastError().text().toStdString());
    }

    QList<int> sessionsToClose;

    while (sessionQuery.next()) {

        int sessionId = sessionQuery.value(0).toInt();
        QString endTimeString = sessionQuery.value(1).toString();

        QString format = "dd.MM.yyyy/HH:mm:ss";

        QDateTime endTime = QDateTime::fromString(endTimeString, format);

        if (endTime < currentTime) {
            sessionsToClose.append(sessionId);
        }
    }

    if (!sessionsToClose.isEmpty()) {
        QSqlQuery updateSessionsQuery(db);
        updateSessionsQuery.prepare("UPDATE Sessions SET Status = 'Closed' WHERE Id IN (" + QStringList(sessionsToClose.size(), "?").join(",") + ")");

        for (int id : sessionsToClose) {
            updateSessionsQuery.addBindValue(id);
        }

        if (!updateSessionsQuery.exec()) {
            throw std::runtime_error(updateSessionsQuery.lastError().text().toStdString());
        }

        QSqlQuery updateComputersQuery(db);
        updateComputersQuery.prepare("UPDATE Computers SET Status = 'Free' WHERE Id IN (SELECT ComputerId FROM Sessions WHERE Id IN (" + QStringList(sessionsToClose.size(), "?").join(",") + "))");

        for (int id : sessionsToClose) {
            updateComputersQuery.addBindValue(id);
        }

        if (!updateComputersQuery.exec()) {
            throw std::runtime_error(updateComputersQuery.lastError().text().toStdString());
        }
    }

    CloseDbConnection();
}

void DbSeeder::CreateTablesIfNotExists(){

    OpenDbConnection();

    CreateTableFromShema(new UserShema());
    CreateTableFromShema(new ComputerShema());
    SeedComputers();
    CreateTableFromShema(new SessionShema());

    CloseDbConnection();
}

void DbSeeder::CreateTableFromShema(BaseTableShema* shema){

    QSqlQuery query(db);

    if (!query.exec(shema->AsString())) {
        std::runtime_error(query.lastError().text().toStdString());
    }
}

void DbSeeder::OpenDbConnection(){

    if(!db.open()){
        throw new std::runtime_error("Ошбика открытия соединения с базой данных");
        return;
    }
}

void DbSeeder::CloseDbConnection(){

    db.close();
}
