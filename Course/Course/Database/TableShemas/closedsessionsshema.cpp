#include "closedsessionsshema.h"

ClosedSessionsShema::ClosedSessionsShema() {}

QString ClosedSessionsShema::AsString(){

    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS ClosedSessions (
            Id INTEGER PRIMARY KEY AUTOINCREMENT,
            StartTime VARCHAR(255) NOT NULL,
            EndTime VARCHAR(255) NOT NULL,
            UserId INTEGER,
            ComputerId INTEGER,
            FOREIGN KEY (UserId) REFERENCES Users(Id) ON DELETE CASCADE,
            FOREIGN KEY (ComputerId) REFERENCES Computers(Id) ON DELETE CASCADE
        );
    )";

    return createTableQuery;
}
