#include <QApplication>

#include "Database/dbseeder.h"

#include "PageViewModels/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DbSeeder dbSeeder;

    dbSeeder.CreateTablesIfNotExists();
    dbSeeder.ChangedOutdatedStatuses();


    auto db = dbSeeder.GetDb();

    MainWindow mainWindow(db);
    mainWindow.show();

    return a.exec();
}
