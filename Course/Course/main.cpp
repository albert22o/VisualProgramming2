#include <QApplication>
#include <QFile>
#include "Database/dbseeder.h"

#include "PageViewModels/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());
    DbSeeder dbSeeder;

    dbSeeder.CreateTablesIfNotExists();
    dbSeeder.ChangedOutdatedStatuses();


    auto db = dbSeeder.GetDb();

    MainWindow mainWindow(db);
    mainWindow.show();

    return a.exec();
}
