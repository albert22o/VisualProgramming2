#ifndef DBSEEDER_H
#define DBSEEDER_H

#include <QSqlDatabase>
#include <Domain/announcement.h>
#include "TableShemas/basetableshema.h"

class DbSeeder
{
public:
    DbSeeder();

    void CreateTablesIfNotExists();
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    void CreateTableFromShema(BaseTableShema* shema);

    void SeedRoles();
    void SeedCategories();

    void OpenDbConnection();
    void CloseDbConnection();
};

#endif // DBSEEDER_H
