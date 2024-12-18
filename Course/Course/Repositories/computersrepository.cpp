#include "computersrepository.h"

#include <QSqlQuery>

#include "Domain/computer.h"

ComputersRepository::ComputersRepository() {}

Computer ComputersRepository::GetById(int id){

    OpenConnection();

    Computer computer;

    QSqlQuery query;

    query.prepare("SELECT Id, Name, Status FROM Computers WHERE Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {

        if (query.next()) {

            computer.Id = query.value("Id").toInt();
            computer.Name = query.value("Name").toString();
            computer.Status = query.value("Status").toString();
        }
        else {
            throw std::runtime_error(query.lastError().text().toStdString());
        }
    }
    else {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();

    return computer;
}

QList<Computer> ComputersRepository::GetAll(){

    OpenConnection();

    QSqlQuery query("SELECT * FROM Computers");

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    QList<Computer> computers;

    while (query.next()) {

        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString status = query.value(2).toString();

        computers.append(Computer(id, name, status));
    }

    CloseConnection();

    return computers;
}

int ComputersRepository::AddRecord(Computer record){

    OpenConnection();

    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO Computers (name, status)
        VALUES (:name, :status)
    )");

    query.bindValue(":name", record.Name);
    query.bindValue(":status", record.Status);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    auto id = query.lastInsertId().toInt();

    CloseConnection();

    return id;
}

void ComputersRepository::UpdateRecord(Computer record){

    OpenConnection();

    QSqlQuery query;

    query.prepare("UPDATE Computers SET Name = :name, Status = :status WHERE Id = :id");

    query.bindValue(":name", record.Name);
    query.bindValue(":status", record.Status);
    query.bindValue(":id", record.Id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void ComputersRepository::AddRecords(QList<Computer> records){
    throw std::runtime_error("Не релизованный метод");
}

void ComputersRepository::DeleteById(int id){
    OpenConnection();

    QSqlQuery query;

    query.prepare("DELETE FROM Computers WHERE Id = :id");

    query.bindValue(":id", id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void ComputersRepository::DeleteManyById(QList<int> idCollection){
    throw std::runtime_error("Не релизованный метод");
}
