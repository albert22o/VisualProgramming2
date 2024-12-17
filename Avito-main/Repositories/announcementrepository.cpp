#include "announcementrepository.h"

AnnouncementRepository::AnnouncementRepository(){

}

Announcement AnnouncementRepository::GetById(int id){

    OpenConnection();

    Announcement announcement;

    QSqlQuery query;

    query.prepare("SELECT Id, Name, Desc, Image, Price, UserId, CategoryId FROM Announcement WHERE Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {

        if (query.next()) {

            announcement.Id = query.value("Id").toInt();
            announcement.Name = query.value("Name").toString();
            announcement.Description = query.value("Desc").toString();
            announcement.Image = query.value("Image").toString();
            announcement.Price = query.value("Price").toDouble();
            announcement.UserId = query.value("UserId").toInt();
            announcement.CategoryId = query.value("CategoryId").toInt();
        }
        else {
            throw std::runtime_error(query.lastError().text().toStdString());
        }
    }
    else {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();

    return announcement;
}

QList<Announcement> AnnouncementRepository::GetAll(){

    OpenConnection();

    QSqlQuery query("SELECT * FROM Announcement");

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    QList<Announcement> announcements;

    while (query.next()) {

        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString desc = query.value(2).toString();
        QString image = query.value(3).toString();
        double price = query.value(4).toDouble();
        int userId = query.value(5).toInt();
        int categoryId = query.value(6).toInt();

        announcements.append(Announcement(id, name, desc, image, price, userId, categoryId));
    }

    CloseConnection();

    return announcements;
}

int AnnouncementRepository::AddRecord(Announcement record){

    OpenConnection();

    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO Announcement (Name, Desc, Image, Price, UserId, CategoryId)
        VALUES (:name, :desc, :image, :price, :userId, :categoryId)
    )");

    query.bindValue(":name", record.Name);
    query.bindValue(":desc", record.Description);
    query.bindValue(":image", record.Image);
    query.bindValue(":price", record.Price);
    query.bindValue(":userId", record.UserId);
    query.bindValue(":categoryId", record.CategoryId);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    auto id = query.lastInsertId().toInt();

    CloseConnection();

    return id;
}

void AnnouncementRepository::UpdateRecord(Announcement record){

    OpenConnection();

    QSqlQuery query;

    query.prepare("UPDATE Announcement SET Name = :name, Desc = :desc, Image = :image, Price = :price, UserId = :userId, CategoryId = :categoryId WHERE Id = :id");

    query.bindValue(":name", record.Name);
    query.bindValue(":desc", record.Description);
    query.bindValue(":image", record.Image);
    query.bindValue(":price", record.Price);
    query.bindValue(":userId", record.UserId);
    query.bindValue(":categoryId", record.CategoryId);
    query.bindValue(":id", record.Id);

    if (!query.exec()) {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void AnnouncementRepository::AddRecords(QList<Announcement> records){
    throw std::runtime_error("Not implemented exception");
}

void AnnouncementRepository::DeleteById(int id){

    OpenConnection();

    QSqlQuery query;

    query.prepare("DELETE FROM Announcement WHERE Id = :id");

    query.bindValue(":id", id);

    if (!query.exec()) {
       throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();
}

void AnnouncementRepository::DeleteManyById(QList<int> idCollection){
     throw std::runtime_error("Not implemented exception");
}

QList<Announcement> AnnouncementRepository::GetByCategoryId(int categoryId){

    OpenConnection();

    QString selectQuery = R"(
            SELECT Id, Name, Desc, Image, Price, UserId, CategoryId
            FROM Announcement
            WHERE CategoryId = :categoryId
        )";

    QSqlQuery query(db);

    query.prepare(selectQuery);
    query.bindValue(":categoryId", categoryId);

    QList<Announcement> announcements;

    if (query.exec()) {
        while (query.next()) {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            QString desc = query.value(2).toString();
            QString image = query.value(3).toString();
            double price = query.value(4).toDouble();
            int userId = query.value(5).toInt();
            int categoryId = query.value(6).toInt();

            announcements.append(Announcement(id, name, desc, image, price, userId, categoryId));
        }
    }
    else
    {
        throw std::runtime_error(query.lastError().text().toStdString());
    }

    CloseConnection();

    return announcements;
}

