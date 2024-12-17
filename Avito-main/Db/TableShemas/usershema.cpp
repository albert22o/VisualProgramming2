#include "usershema.h"

UserShema::UserShema() {}

QString UserShema::AsString(){

    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Users (
            Id INTEGER PRIMARY KEY AUTOINCREMENT,
            Password VARCHAR(255) NOT NULL,
            Name VARCHAR(255),
            Login VARCHAR(255) NOT NULL,
            Phone VARCHAR(32),
            RoleId INTEGER,
            FOREIGN KEY (RoleId) REFERENCES Roles(Id) ON DELETE CASCADE
        );
    )";

    return createTableQuery;
}
