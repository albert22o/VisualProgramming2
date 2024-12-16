#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QMenuBar>
#include <QStatusBar>
#include <QHeaderView>
#include <QMessageBox>
#include <QDebug>
namespace Ui {
class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);

    ~AdminPanel();

private:
    Ui::AdminPanel *ui;
    QHBoxLayout* createActionButtons();
    QHBoxLayout* createSearchBar();
    QTableWidget* createComputerTable();
    QLabel* createSessionInfo();
    void endSession();
    int selectedRow;
    QStatusBar* statusBar;
    QTableWidget* computerTable;
    QLabel* sessionInfo;
};

#endif // ADMINPANEL_H
