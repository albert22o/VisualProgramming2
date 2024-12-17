#include "usershema.h"

UserShema::UserShema() {}

QString UserShema::AsString(){

    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Users (
            Id INTEGER PRIMARY KEY AUTOINCREMENT,
            Login VARCHAR(255) NOT NULL,
            Password VARCHAR(255) NOT NULL
        );
    )";

    return createTableQuery;
}
