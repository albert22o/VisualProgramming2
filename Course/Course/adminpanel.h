#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QLabel>
namespace Ui {
class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    QHBoxLayout* createActionButtons();
    QHBoxLayout* createSearchBar();
    QTableWidget* createComputerTable();
    QLabel* createSessionInfo();
    ~AdminPanel();

private:
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
