#include <QApplication>

#include "Database/dbseeder.h"

#include "PageViewModels/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DbSeeder dbSeeder;
    dbSeeder.CreateTablesIfNotExists();

    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
