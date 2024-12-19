#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MainPage *ui;
    int selectedRow;
    void Setup();
    void CreateComputerTable();
};

#endif // MAINPAGE_H
