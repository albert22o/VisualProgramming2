#include "sessionshistorypage.h"
#include "ui_sessionshistorypage.h"

SessionsHistoryPage::SessionsHistoryPage(QSqlDatabase& db, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SessionsHistoryPage)
{
    ui->setupUi(this);
}

SessionsHistoryPage::~SessionsHistoryPage()
{
    delete ui;
}
