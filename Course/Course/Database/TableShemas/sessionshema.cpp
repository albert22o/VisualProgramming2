#include "sessionshema.h"

SessionShema::SessionShema() {}


QString SessionShema::AsString(){

    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Sessions (
            Id INTEGER PRIMARY KEY AUTOINCREMENT,
            StartTime VARCHAR(255) NOT NULL,
            EndTime VARCHAR(255) NOT NULL,
            Status VARCHAR(255) NOT NULL,
            UserId INTEGER,
            ComputerId INTEGER,
            FOREIGN KEY (UserId) REFERENCES Users(Id) ON DELETE CASCADE,
            FOREIGN KEY (ComputerId) REFERENCES Computers(Id) ON DELETE CASCADE
        );
    )";

    return createTableQuery;
}
