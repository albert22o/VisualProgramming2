#include "usersrepository.h"

#include <QSqlQuery>

UsersRepository::UsersRepository() {}

User UsersRepository::GetById(int id){

    OpenConnection();

    User user;

    QSqlQuery query;

    query.prepare("SELECT Id, Password, Name, Login, Phone, RoleId FROM Users WHERE Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {

        if (query.next()) {

            user.Id = query.value("Id").toInt();
            user.Login = query.value("Login").toString();
            user.Password = query.value("Password").toString();
            user.Name = query.value("Name").toString();
            user.Phone = query.value("Phone").toString();
            user.RoleId = query.value("RoleId").toInt();

        }
        else {
            throw std::runtime_error(query.lastError().text().toStdString());
        }
    }
    else {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();

    return user;
}

QList<User> UsersRepository::GetAll(){

    OpenConnection();

    QSqlQuery query("SELECT * FROM Users");

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    QList<User> users;

    while (query.next()) {

        User user;

        user.Id = query.value("Id").toInt();
        user.Login = query.value("Login").toString();
        user.Password = query.value("Password").toString();
        user.Name = query.value("Name").toString();
        user.Phone = query.value("Phone").toString();
        user.RoleId = query.value("RoleId").toInt();

        users.append(user);
    }

    CloseConnection();

    return users;
}

int UsersRepository::AddRecord(User record){

    OpenConnection();

    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO Users (Password, Name, Login, Phone, RoleId)
        VALUES (:password, :name, :login, :phone, :roleId)
    )");

    query.bindValue(":password", record.Password);
    query.bindValue(":name", record.Name);
    query.bindValue(":login", record.Login);
    query.bindValue(":phone", record.Phone);
    query.bindValue(":roleId", record.RoleId);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    auto id = query.lastInsertId().toInt();

    CloseConnection();

    return id;
}

void UsersRepository::UpdateRecord(User record){

    OpenConnection();

    QSqlQuery query;

    query.prepare("UPDATE Users SET Password = :password, Name = :name, Login = :login, Phone = :phone, RoleId = :roleId WHERE Id = :id");

    query.bindValue(":password", record.Password);
    query.bindValue(":name", record.Name);
    query.bindValue(":login", record.Login);
    query.bindValue(":phone", record.Phone);
    query.bindValue(":roleId", record.RoleId);
    query.bindValue(":id", record.Id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void UsersRepository::AddRecords(QList<User> records){

    throw std::runtime_error("Not implemented exception");
}

void UsersRepository::DeleteById(int id){

    OpenConnection();

    QSqlQuery query;

    query.prepare("DELETE FROM Users WHERE Id = :id");

    query.bindValue(":id", id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void UsersRepository::DeleteManyById(QList<int> idCollection){

    throw std::runtime_error("Not implemented exception");
}

bool UsersRepository::IsUserExists(const QString& login){

    OpenConnection();

    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM Users WHERE Login = :login");
    query.bindValue(":login", login);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    if (query.next()) {

        int count = query.value(0).toInt();

        CloseConnection();

        return count > 0;
    }

    CloseConnection();

    return false;
}

User* UsersRepository::AuthorizeUser(const QString& login, const QString& password){

    OpenConnection();

    QSqlQuery query;

    query.prepare("SELECT * FROM Users WHERE Login = :login AND Password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    if (query.next()) {

        User* user = new User();

        user->Id = query.value("Id").toInt();
        user->Name = query.value("Name").toString();
        user->Phone = query.value("Phone").toString();
        user->RoleId = query.value("RoleId").toInt();

        CloseConnection();

        return user;
    }

    CloseConnection();

    return nullptr;
}
