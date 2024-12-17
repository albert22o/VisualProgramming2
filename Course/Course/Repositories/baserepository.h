#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H

#include <QSqlDatabase>
#include <QSqlError>

template <typename T>
class BaseRepository
{    
protected:
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    void OpenConnection(){
        if(!db.open()){
            throw std::runtime_error(db.lastError().text().toStdString());
            return;
        }
    }

    void CloseConnection(){
        db.close();
    }

public:

    BaseRepository(){
        db.setDatabaseName("computer_club.db");
    }

    virtual T GetById(int id) = 0;
    virtual QList<T> GetAll() = 0;
    virtual int AddRecord(T record) = 0;
    virtual void UpdateRecord(T record) = 0;
    virtual void AddRecords(QList<T> records) = 0;
    virtual void DeleteById(int id) = 0;
    virtual void DeleteManyById(QList<int> idCollection) = 0;
};

#endif // BASEREPOSITORY_H
