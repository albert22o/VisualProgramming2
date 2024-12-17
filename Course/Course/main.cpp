#include "adminpanel.h"
#include <QApplication>

#include "Database/dbseeder.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminPanel w;

    DbSeeder dbSeeder;
    dbSeeder.CreateTablesIfNotExists();

    w.show();

    return a.exec();
}
