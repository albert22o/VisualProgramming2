#include "dbseeder.h"

#include "TableShemas/computershema.h"
#include "TableShemas/sessionshema.h"
#include "TableShemas/usershema.h"
#include "TableShemas/computerstatuses.h"

#include <QSqlQuery>
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

        for (int i = 0; i < 10; ++i) {

            query.prepare("INSERT INTO Computers (Name, Status) VALUES (:name, :status)");
            query.bindValue(":name", computerNames[i]);
            query.bindValue(":status", statuses[i]);

            if (!query.exec()) {
                throw std::runtime_error(query.lastError().text().toStdString());
            }
        }
    }
}

DbSeeder::DbSeeder() {

    db.setDatabaseName("computer_club.db");
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
