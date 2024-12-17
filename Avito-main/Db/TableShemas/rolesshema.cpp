#include "rolesshema.h"

RolesShema::RolesShema() {}

QString RolesShema::AsString(){

    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Roles (
            Id INTEGER PRIMARY KEY AUTOINCREMENT,
            Name VARCHAR(255) NOT NULL
        );
    )";

    return createTableQuery;
}
