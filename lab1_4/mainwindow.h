#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "geometry.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ClearButton_clicked();

    void on_Square_clicked();

    void on_Rectangle_clicked();

    void on_Rhombus_clicked();

    void on_Circle_clicked();

    void on_Sector_clicked();

    void on_Trianlge_clicked();

    void on_Trapezoid_clicked();

    void on_actionAuthors_triggered();

    void on_actionquit_triggered();

    void on_CalculateButton_clicked();

private:
    Geometry* figure;
    void setImage(std::string path);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
