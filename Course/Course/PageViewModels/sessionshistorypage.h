#ifndef SESSIONSHISTORYPAGE_H
#define SESSIONSHISTORYPAGE_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class SessionsHistoryPage;
}

class SessionsHistoryPage : public QWidget
{
    Q_OBJECT

public:
    explicit SessionsHistoryPage(QSqlDatabase& db, QWidget *parent = nullptr);
    ~SessionsHistoryPage();

private:
    Ui::SessionsHistoryPage *ui;
};

#endif // SESSIONSHISTORYPAGE_H
