#include "sessionsrepository.h"

#include <QSqlQuery>
#include <QSqlError>

SessionsRepository::SessionsRepository(QSqlDatabase& db) : BaseRepository(db) {}

QList<Session> SessionsRepository::GetSessionsByComputerRate(ComputerRate compRate, SessionStatus sessionStatus){

    OpenConnection();

    auto rate = int(compRate);
    auto status = ParseStatusFrom(sessionStatus);

    QList<Session> sessions;

    QSqlQuery query;
    query.prepare("SELECT s.* FROM Sessions s "
                  "JOIN Computers c ON s.ComputerId = c.Id "
                  "WHERE c.Rate = :compRate AND s.Status = :sessionStatus");

    query.bindValue(":compRate", rate);
    query.bindValue(":sessionStatus", status);

    if (query.exec()) {
        while (query.next()) {

            Session session;
            session.Id = query.value("Id").toInt();
            session.StartOfLease = query.value("StartTime").toString();
            session.EndOfLease = query.value("EndTime").toString();
            session.Status = query.value("Status").toString();
            session.UserId = query.value("UserId").toInt();
            session.ComputerId = query.value("ComputerId").toInt();
            sessions.append(session);
        }
    }
    else{
       throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();

    return sessions;
}

Session SessionsRepository::GetSessionByComputerId(int id){

    OpenConnection();

    Session session;

    QSqlQuery query;

    query.prepare("SELECT Id, StartTime, EndTime, Status, UserId, ComputerId FROM Sessions WHERE ComputerId = :id AND Status = 'Active'");

    query.bindValue(":id", id);

    if (query.exec()) {

        if (query.next()) {

            session.Id = query.value("Id").toInt();
            session.StartOfLease = query.value("StartTime").toString();
            session.EndOfLease = query.value("EndTime").toString();
            session.UserId = query.value("UserId").toInt();
            session.Status = query.value("Status").toString();
            session.ComputerId = query.value("ComputerId").toInt();

        }
        else {
            throw std::runtime_error(query.lastError().text().toStdString());
        }
    }
    else {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();

    return session;
}

QList<Session> SessionsRepository::GetClosedSessions(){

    OpenConnection();

    QSqlQuery query("SELECT Id, StartTime, EndTime, Status, UserId, ComputerId FROM Sessions WHERE Status = 'Closed'");

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    QList<Session> sessions;

    while (query.next()) {

        int id = query.value(0).toInt();
        QString startTime = query.value(1).toString();
        QString endTime = query.value(2).toString();
        QString status = query.value(3).toString();
        int userId = query.value(4).toInt();
        int computerId =   query.value(5).toInt();

        sessions.append(Session(id, startTime, endTime, status, userId, computerId));
    }

    CloseConnection();

    return sessions;
}

QString SessionsRepository::ParseStatusFrom(SessionStatus status){

    if(status == SessionStatus::Active){
        return "Active";
    }

    return "Closed";
}

Session SessionsRepository::GetById(int id){

    OpenConnection();

    Session session;

    QSqlQuery query;

    query.prepare("SELECT Id, StartTime, EndTime, UserId, ComputerId FROM Sessions WHERE Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {

        if (query.next()) {

            session.Id = query.value("Id").toInt();
            session.StartOfLease = query.value("StartOfLease").toString();
            session.EndOfLease = query.value("EndOfLease").toString();
            session.UserId = query.value("UserId").toInt();
            session.ComputerId = query.value("ComputerId").toInt();

        }
        else {
            throw std::runtime_error(query.lastError().text().toStdString());
        }
    }
    else {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();

    return session;
}

QList<Session> SessionsRepository::GetAll(){

    OpenConnection();

    QSqlQuery query("SELECT * FROM Sessions");

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    QList<Session> sessions;

    while (query.next()) {

        int id = query.value(0).toInt();
        QString startTime = query.value(1).toString();
        QString endTime = query.value(2).toString();
        QString status = query.value(3).toString();
        int userId = query.value(4).toInt();
        int computerId =   query.value(5).toInt();

        sessions.append(Session(id, startTime, endTime, status, userId, computerId));
    }

    CloseConnection();

    return sessions;
}

int SessionsRepository::AddRecord(Session record){

    OpenConnection();

    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO Sessions (startTime, endTime, status, userId, computerId)
        VALUES (:startTime, :endTime, :status, :userId, :computerId)
    )");

    query.bindValue(":startTime", record.StartOfLease);
    query.bindValue(":endTime", record.EndOfLease);
    query.bindValue(":userId", record.UserId);
    query.bindValue(":status", record.Status);
    query.bindValue(":computerId", record.ComputerId);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    auto id = query.lastInsertId().toInt();

    CloseConnection();

    return id;
}

void SessionsRepository::UpdateRecord(Session record){

    OpenConnection();

    QSqlQuery query;

    query.prepare("UPDATE Sessions SET StartTime = :startOfLease, EndTime = :endOfLease, Status = :status, UserId = :userId, ComputerId = :computerId  WHERE Id = :id");

    query.bindValue(":startOfLease", record.StartOfLease);
    query.bindValue(":endOfLease", record.EndOfLease);
    query.bindValue(":userId", record.UserId);
    query.bindValue(":computerId", record.ComputerId);
     query.bindValue(":status", record.Status);
    query.bindValue(":id", record.Id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void SessionsRepository::AddRecords(QList<Session> records){
    throw std::runtime_error("Не релизованный метод");
}

void SessionsRepository::DeleteById(int id){
    OpenConnection();

    QSqlQuery query;

    query.prepare("DELETE FROM Sessions WHERE Id = :id");

    query.bindValue(":id", id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void SessionsRepository::DeleteManyById(QList<int> idCollection){
    throw std::runtime_error("Не релизованный метод");
}
