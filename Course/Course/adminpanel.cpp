#include "adminpanel.h"
#include "ui_adminpanel.h"
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

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    {
            ui->setupUi(this);
            setWindowTitle("Панель администратора");
            resize(800, 600);

            // Создание центрального виджета
            QWidget *centralWidget = new QWidget(this);
            QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

            // Строка поиска и фильтры
            QHBoxLayout *searchLayout = new QHBoxLayout();
            QLineEdit *searchBox = new QLineEdit();
            searchBox->setPlaceholderText("Поиск клиента или компьютера...");
            QComboBox *filterCombo = new QComboBox();
            filterCombo->addItem("Все");
            filterCombo->addItem("Свободен");
            filterCombo->addItem("Занят");
            QPushButton *searchButton = new QPushButton("Поиск");

            searchLayout->addWidget(searchBox);
            searchLayout->addWidget(filterCombo);
            searchLayout->addWidget(searchButton);

            // Список компьютеров
            QTableWidget *computerTable = new QTableWidget(10, 3); // 10 строк, 3 столбца
            computerTable->setHorizontalHeaderLabels({"Компьютер", "Статус", "Время"});
            for (int i = 0; i < 10; ++i) {
                computerTable->setItem(i, 0, new QTableWidgetItem("Компьютер " + QString::number(i + 1)));
                computerTable->setItem(i, 1, new QTableWidgetItem(i % 2 == 0 ? "Свободен" : "Занят"));
                computerTable->setItem(i, 2, new QTableWidgetItem("00:00"));
            }

            // Панель информации о сеансе
            QLabel *sessionInfo = new QLabel("Информация о сеансе: Выберите компьютер из списка.");
            sessionInfo->setStyleSheet("font-weight: bold; padding: 5px;");

            // Быстрые действия
            QHBoxLayout *actionsLayout = new QHBoxLayout();
            QPushButton *registerButton = new QPushButton("Зарегистрировать клиента");
            QPushButton *startSessionButton = new QPushButton("Начать сеанс");
            QPushButton *endSessionButton = new QPushButton("Завершить сеанс");

            actionsLayout->addWidget(registerButton);
            actionsLayout->addWidget(startSessionButton);
            actionsLayout->addWidget(endSessionButton);

            // Компоновка виджетов
            mainLayout->addLayout(searchLayout);
            mainLayout->addWidget(computerTable);
            mainLayout->addWidget(sessionInfo);
            mainLayout->addLayout(actionsLayout);

            setCentralWidget(centralWidget);

            // Строка состояния
            QStatusBar *statusBar = new QStatusBar(this);
            setStatusBar(statusBar);
            statusBar->showMessage("Готово");
        }
}

AdminPanel::~AdminPanel()
{
    delete ui;
}
