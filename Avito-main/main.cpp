#include <QApplication>
#include "Db/dbseeder.h"

#include "mainwindow.h"

#include "Domain/user.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DbSeeder db; // вынести в класс application
    db.CreateTablesIfNotExists();

    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();

}
