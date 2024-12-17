#ifndef DBSEEDER_H
#define DBSEEDER_H

#include "TableShemas/basetableshema.h"

#include <QSqlDatabase>


class DbSeeder
{
public:
    DbSeeder();

    void CreateTablesIfNotExists();
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    void CreateTableFromShema(BaseTableShema* shema);

    void SeedComputers();

    void OpenDbConnection();
    void CloseDbConnection();
};

#endif // DBSEEDER_H
