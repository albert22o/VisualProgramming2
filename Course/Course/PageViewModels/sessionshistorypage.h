#ifndef SESSIONSHISTORYPAGE_H
#define SESSIONSHISTORYPAGE_H

#include <QWidget>

namespace Ui {
class SessionsHistoryPage;
}

class SessionsHistoryPage : public QWidget
{
    Q_OBJECT

public:
    explicit SessionsHistoryPage(QWidget *parent = nullptr);
    ~SessionsHistoryPage();

private:
    Ui::SessionsHistoryPage *ui;
};

#endif // SESSIONSHISTORYPAGE_H
