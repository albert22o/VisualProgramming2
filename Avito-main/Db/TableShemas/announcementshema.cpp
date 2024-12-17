#include "announcementshema.h"

AnnouncementShema::AnnouncementShema() {}

QString AnnouncementShema::AsString(){

    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Announcement (
            Id INTEGER PRIMARY KEY AUTOINCREMENT,
            Name VARCHAR(255) NOT NULL,
            Desc VARCHAR(255),
            Image VARCHAR(255),
            Price REAL,
            UserId INTEGER,
            CategoryId INTEGER,
            FOREIGN KEY (UserId) REFERENCES Users(Id) ON DELETE CASCADE,
            FOREIGN KEY (CategoryId) REFERENCES Categories(Id) ON DELETE CASCADE
        );
    )";

    return createTableQuery;
}
