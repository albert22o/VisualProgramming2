#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "square.h"
#include "rectangle.h"
#include "rhombus.h"
#include "circle.h"
#include "sector.h"
#include "trapezoid.h"
#include "triangle.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_ClearButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setImage(std::string path){
    QPixmap pix(QString::fromStdString(path));
    int w = ui->Image->width();
    int h = ui->Image->height();
    ui->Image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_ClearButton_clicked()
{
    ui->ParOneName->clear();
    ui->ParOne->hide();
    ui->ParTwoName->clear();
    ui->ParTwo->hide();
    ui->ParThreeName->clear();
    ui->ParThree->hide();
    ui->answer->clear();
}

void MainWindow::on_Square_clicked()
{
    on_ClearButton_clicked();
    ui->ParOneName->setText("a");
    ui->ParOne->show();
    setImage(":/figure/img/square.png");
    figure = new Square();
}

void MainWindow::on_Rectangle_clicked()
{
    on_ClearButton_clicked();
    ui->ParOneName->setText("a");
    ui->ParOne->show();
    ui->ParTwoName->setText("b");
    ui->ParTwo->show();
    setImage(":/figure/img/rectangle.jfif");
    figure = new Rectangle();
}

void MainWindow::on_Rhombus_clicked()
{
    on_ClearButton_clicked();
    ui->ParOneName->setText("a");
    ui->ParOne->show();
    ui->ParTwoName->setText("h");
    ui->ParTwo->show();
    setImage(":/figure/img/rhombus.jpg");
    figure = new Rhombus();
}

void MainWindow::on_Circle_clicked()
{
    on_ClearButton_clicked();
    ui->ParOneName->setText("r");
    ui->ParOne->show();
    setImage(":/figure/img/circle.png");
    figure = new Circle();
}


void MainWindow::on_Sector_clicked()
{
    on_ClearButton_clicked();
    ui->ParOneName->setText("r");
    ui->ParOne->show();
    ui->ParTwoName->setText("Degrees");
    ui->ParTwo->show();
    setImage(":/figure/img/sector.png");
    figure = new Sector();
}

void MainWindow::on_Trianlge_clicked()
{
    on_ClearButton_clicked();
    ui->ParOneName->setText("a");
    ui->ParOne->show();
    ui->ParTwoName->setText("b");
    ui->ParTwo->show();
    ui->ParThreeName->setText("c");
    ui->ParThree->show();
    setImage(":/figure/img/triangle.jpg");
    figure = new Triangle();
}


void MainWindow::on_Trapezoid_clicked()
{
    on_ClearButton_clicked();
    ui->ParOneName->setText("a");
    ui->ParOne->show();
    ui->ParTwoName->setText("b");
    ui->ParTwo->show();
    ui->ParThreeName->setText("h");
    ui->ParThree->show();
    setImage(":/figure/img/trapezoid.jpg");
    figure = new Trapezoid();
}

void MainWindow::on_actionAuthors_triggered()
{
    QMessageBox::information(this,QString::fromStdString("Author"),QString::fromStdString("Oganesan Albert IP-211"));
}

void MainWindow::on_actionquit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_CalculateButton_clicked()
{
    figure->first_par = ui->ParOne->text().toDouble();
    figure->second_par = ui->ParTwo->text().toDouble();
    figure->third_par = ui->ParThree->text().toDouble();
    figure->GetArea();
    ui->answer->setText(QString::number(figure->output));
}
