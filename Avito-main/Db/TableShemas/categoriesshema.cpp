#include "categoriesshema.h"

CategoriesShema::CategoriesShema() {}

QString CategoriesShema::AsString(){

    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Categories (
            Id INTEGER PRIMARY KEY AUTOINCREMENT,
            Name VARCHAR(255) NOT NULL
        );
    )";

    return createTableQuery;
}
