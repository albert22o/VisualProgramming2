#include "session.h"

Session::Session() {}

Session::Session(int id, QString startTime, QString endTime, QString status, int userId, int computerId){

    Id = id;
    StartOfLease = startTime;
    EndOfLease = endTime;
    UserId = userId;
    ComputerId = computerId;
    Status = status;
}
