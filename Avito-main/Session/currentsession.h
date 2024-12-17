#ifndef CURRENTSESSION_H
#define CURRENTSESSION_H

#include "Domain/user.h"

#include <QObject>

class CurrentSession : public QObject
{
    Q_OBJECT
public:
    static CurrentSession& GetInstance();

    void SetUser(User newUser);
    User GetUser() const;
private:
    CurrentSession(QObject* parent = nullptr) : QObject(parent) {}
    CurrentSession(const CurrentSession&) = delete;
    CurrentSession& operator=(const CurrentSession&) = delete;

    User user;
};

#endif // CURRENTSESSION_H
