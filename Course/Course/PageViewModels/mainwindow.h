#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mainpage.h"
#include "statisticspage.h"
#include "sessionshistorypage.h"
#include "registrationpage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void Setup();

    MainPage* mainPage;
    RegistrationPage* registrationPage;
    SessionsHistoryPage* sessionHistoryPage;
    StatisticsPage* statisticsPage;
};

#endif // MAINWINDOW_H
