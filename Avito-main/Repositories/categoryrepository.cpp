#include "categoryrepository.h"

#include <QSqlQuery>

CategoryRepository::CategoryRepository() {}

Category CategoryRepository::GetById(int id){

    OpenConnection();

    Category category;

    QSqlQuery query;

    query.prepare("SELECT Id, Name FROM Categories WHERE Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {

        if (query.next()) {

            category.Id = query.value("Id").toInt();
            category.Name = query.value("Name").toString();
        }
        else {
            throw std::runtime_error(query.lastError().text().toStdString());
        }
    }
    else {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();

    return category;

}

QList<Category> CategoryRepository::GetAll(){

    OpenConnection();

    QSqlQuery query("SELECT * FROM Categories");

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    QList<Category> categories;

    while (query.next()) {

        Category category;

        category.Id = query.value(0).toInt();
        category.Name = query.value(1).toString();

        categories.append(category);
    }

    CloseConnection();

    return categories;
}

int CategoryRepository::AddRecord(Category record){

    OpenConnection();

    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO Categories (Name)
        VALUES (:name)
    )");

    query.bindValue(":name", record.Name);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    auto id = query.lastInsertId().toInt();

    CloseConnection();

    return id;
}

void CategoryRepository::UpdateRecord(Category record){

    OpenConnection();

    QSqlQuery query;

    query.prepare("UPDATE Categories SET Name = :name WHERE Id = :id");

    query.bindValue(":name", record.Name);
    query.bindValue(":id", record.Id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void CategoryRepository::AddRecords(QList<Category> records){
    throw std::runtime_error("Not implemented exception");
}

void CategoryRepository::DeleteById(int id){

    OpenConnection();

    QSqlQuery query;

    query.prepare("DELETE FROM Categories WHERE Id = :id");

    query.bindValue(":id", id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void CategoryRepository::DeleteManyById(QList<int> idCollection){
    throw std::runtime_error("Not implemented exception");
}
