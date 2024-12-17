#include "currentsession.h"

CurrentSession& CurrentSession::GetInstance(){
    static CurrentSession instance;
    return instance;
}

void CurrentSession::SetUser(User newUser){

    user = newUser;
}

User CurrentSession::GetUser() const{
    return user;
}
