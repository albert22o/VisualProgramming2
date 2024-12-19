#include "usersrepository.h"

#include <QSqlQuery>

UsersRepository::UsersRepository(QSqlDatabase& db) : BaseRepository(db) {}


bool UsersRepository::IsUserExists(const QString& login){

    OpenConnection();

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Users WHERE login = :login");
    query.bindValue(":login", login);

    if (!query.exec()) {
       throw std::runtime_error(query.lastError().text().toStdString());
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    CloseConnection();

    return false;
}

User UsersRepository::GetById(int id){

    OpenConnection();

    User user;

    QSqlQuery query;

    query.prepare("SELECT Id, Login, Password FROM Users WHERE Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {

        if (query.next()) {

            user.Id = query.value("Id").toInt();
            user.Login = query.value("Login").toString();
            user.Password = query.value("Password").toString();
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

        int id = query.value(0).toInt();
        QString login = query.value(1).toString();
        QString password = query.value(2).toString();

        users.append(User(id, login, password));
    }

    CloseConnection();

    return users;
}

int UsersRepository::AddRecord(User record){

    OpenConnection();

    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO Users (Login, Password)
        VALUES (:login, :password)
    )");

    query.bindValue(":login", record.Login);
    query.bindValue(":password", record.Password);

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

    query.prepare("UPDATE Users SET Login = :login, Password = :password WHERE Id = :id");

    query.bindValue(":login", record.Login);
    query.bindValue(":password", record.Password);
    query.bindValue(":id", record.Id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void UsersRepository::AddRecords(QList<User> records){
    throw std::runtime_error("Не релизованный метод");
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
    throw std::runtime_error("Не релизованный метод");
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
        user->Login = query.value("Login").toString();
        user->Password = query.value("Password").toString();

        CloseConnection();

        return user;
    }

    CloseConnection();

    return nullptr;
}
