#include "computershema.h"

ComputerShema::ComputerShema() {}


QString ComputerShema::AsString(){

    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Computers (
            Id INTEGER PRIMARY KEY AUTOINCREMENT,
            Name VARCHAR(255) NOT NULL,
            Status VARCHAR(255) NOT NULL
        );
    )";

    return createTableQuery;

}
