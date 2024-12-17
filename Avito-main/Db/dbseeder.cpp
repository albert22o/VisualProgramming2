#include "dbseeder.h"

#include <QSqlQuery>
#include <QUuid>
#include <QSqlError>

#include "TableShemas/usershema.h"
#include "TableShemas/rolesshema.h"
#include "TableShemas/announcementshema.h"
#include "TableShemas/categoriesshema.h"

DbSeeder::DbSeeder() {

    db.setDatabaseName("avito.db");
}

void DbSeeder::CreateTablesIfNotExists(){

    OpenDbConnection();

    CreateTableFromShema(new RolesShema());
    SeedRoles();
    CreateTableFromShema(new UserShema());
    CreateTableFromShema(new CategoriesShema());
    SeedCategories();
    CreateTableFromShema(new AnnouncementShema());

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

void DbSeeder::SeedCategories(){

    QSqlQuery query(db);

    QString checkCategoriesQuery = "SELECT COUNT(*) FROM Categories";

    if (!query.exec(checkCategoriesQuery)) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    query.next();

    int count = query.value(0).toInt();

    if(count == 0){

        QString insertDataQuery = R"(
            INSERT INTO Categories (Name) VALUES
                ('Авто'),
                ('Одежда и обувь'),
                ('Хобби и отдых'),
                ('Услуги'),
                ('Электроника'),
                ('Запчасти для авто'),
                ('Красота и здоровье'),
                ('Для дачи и дома'),
                ('Детские товары')
        )";

        if (!query.exec(insertDataQuery)) {
            throw std::runtime_error(query.lastError().text().toStdString());
        }
    }
}

void DbSeeder::SeedRoles(){

    QSqlQuery query(db);

    QString checkRolesQuery = "SELECT COUNT(*) FROM Roles";

    if (!query.exec(checkRolesQuery)) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    query.next();

    int count = query.value(0).toInt();

    if (count != 3) {

        QString deleteQuery = "DELETE FROM Roles";

        if (!query.exec(deleteQuery)) {
            throw std::runtime_error(query.lastError().text().toStdString());
        }

        QString insertDataQuery = R"(
            INSERT INTO Roles (Name) VALUES
                ('Admin'),
                ('User'),
                ('Guest')
        )";

        if (!query.exec(insertDataQuery)) {
            throw std::runtime_error(query.lastError().text().toStdString());
        }
    }
}
