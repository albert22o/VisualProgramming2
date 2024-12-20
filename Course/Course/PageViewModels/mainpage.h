#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>

#include <QSqlDatabase>
#include "Domain/session.h"
#include "Application/computerviewmodel.h"
#include "Repositories/computersrepository.h"
#include "Repositories/usersrepository.h"
#include "Repositories/sessionsrepository.h"

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QSqlDatabase& database, QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

    void on_startSession_clicked();

    void OnComputerLeaseTimeChanged(const Computer &computer, int updatedTime);
    void OnComputerLeaseFinished(const Computer &computer);

    void OnNewSessionStarted(Session& session, const Computer& computer);

    void on_endSession_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_clearButton_clicked();

    void on_tariff_activated(int index);

    void on_status_activated(int index);

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::MainPage *ui;
    QMap<int, ComputerViewModel*> tableIdToComputer;
    int selectedRow;
    void Setup();
    void GetComputers();
    void CreateComputerTable();

    void ConnectWithComputerViewModel(ComputerViewModel* computerViewModel);

    QString FormatTime(int seconds);

    UsersRepository usersRepos;
    ComputersRepository computerRepos;
    SessionsRepository sessionRepos;
};

#endif // MAINPAGE_H
