#include "sessionshistorypage.h"
#include "ui_sessionshistorypage.h"

SessionsHistoryPage::SessionsHistoryPage(QSqlDatabase& db, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SessionsHistoryPage),
    sessionRepos(db),
    userRepos(db),
    computerRepos(db)
{
    ui->setupUi(this);

    model = new QStandardItemModel();

    model->setHorizontalHeaderLabels(QStringList()
        << "Id" << "Время начала" << "Время окончания" << "Статус" << "Компьютер" << "Пользователь");

    ui->tableView->setModel(model);

    for (int i = 0; i < model->columnCount(); ++i) {
        ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    ui->tableView->horizontalHeader()->setSortIndicatorShown(true);
    ui->tableView->horizontalHeader()->setSectionsClickable(true);
    ui->tableView->setSortingEnabled(true);

    auto closedSessions = sessionRepos.GetClosedSessions();

    for(auto& session : closedSessions){

        QList<QStandardItem*> row;

        row.append(new QStandardItem(QString::number(session.Id)));
        row.append(new QStandardItem(session.StartOfLease));
        row.append(new QStandardItem(session.EndOfLease));
        row.append(new QStandardItem(session.Status));

        auto computer = computerRepos.GetById(session.ComputerId);
        auto user = userRepos.GetById(session.UserId);

        row.append(new QStandardItem(computer.Name));
        row.append(new QStandardItem(user.Login));

        model->appendRow(row);
    }
}

SessionsHistoryPage::~SessionsHistoryPage()
{
    delete ui;
}
