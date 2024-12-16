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
#include <QHeaderView>
#include <QtDebug>


AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    resize(800, 600);

    // Central Widget
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Create and add widgets
    mainLayout->addLayout(createSearchBar());
    mainLayout->addWidget(createComputerTable());
    mainLayout->addWidget(createSessionInfo());
    mainLayout->addLayout(createActionButtons());

    setCentralWidget(centralWidget);

    // Status Bar
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    statusBar->showMessage("Готово");
}

QHBoxLayout* AdminPanel::createSearchBar()
{
    QHBoxLayout *searchLayout = new QHBoxLayout();

    QLineEdit *searchBox = new QLineEdit();
    searchBox->setPlaceholderText("Поиск клиента или компьютера...");
    searchBox->setToolTip("Введите имя клиента или номер компьютера для поиска");

    QComboBox *filterCombo = new QComboBox();
    filterCombo->addItem("Все");
    filterCombo->addItem("Свободен");
    filterCombo->addItem("Занят");
    filterCombo->setToolTip("Фильтровать компьютеры по статусу");

    QPushButton *searchButton = new QPushButton("Поиск");
    searchButton->setToolTip("Нажмите для выполнения поиска");

    searchLayout->addWidget(searchBox);
    searchLayout->addWidget(filterCombo);
    searchLayout->addWidget(searchButton);

    // Signal-slot connection (to be implemented)
    connect(searchButton, &QPushButton::clicked, this, []() {
        qDebug() << "Search button clicked!";
    });

    return searchLayout;
}

QTableWidget* AdminPanel::createComputerTable()
{
    QTableWidget *computerTable = new QTableWidget(10, 3);
    computerTable->setHorizontalHeaderLabels({"Компьютер", "Статус", "Время"});
    computerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < 10; ++i) {
        computerTable->setItem(i, 0, new QTableWidgetItem("Компьютер " + QString::number(i + 1)));
        computerTable->setItem(i, 1, new QTableWidgetItem(i % 2 == 0 ? "Свободен" : "Занят"));
        computerTable->setItem(i, 2, new QTableWidgetItem("00:00"));
    }

    connect(computerTable, &QTableWidget::cellClicked, this, [](int row, int column) {
        qDebug() << "Clicked cell at row:" << row << "column:" << column;
    });

    return computerTable;
}

QLabel* AdminPanel::createSessionInfo()
{
    QLabel *sessionInfo = new QLabel("Информация о сеансе: Выберите компьютер из списка.");
    sessionInfo->setStyleSheet("font-weight: bold; padding: 5px;");
    sessionInfo->setAlignment(Qt::AlignLeft);
    return sessionInfo;
}

QHBoxLayout* AdminPanel::createActionButtons()
{
    QHBoxLayout *actionsLayout = new QHBoxLayout();

    QPushButton *registerButton = new QPushButton("Зарегистрировать клиента");
    QPushButton *startSessionButton = new QPushButton("Начать сеанс");
    QPushButton *endSessionButton = new QPushButton("Завершить сеанс");

    registerButton->setToolTip("Добавить нового клиента в систему");
    startSessionButton->setToolTip("Запустить сеанс для выбранного компьютера");
    endSessionButton->setToolTip("Завершить текущий сеанс");

    actionsLayout->addWidget(registerButton);
    actionsLayout->addWidget(startSessionButton);
    actionsLayout->addWidget(endSessionButton);

    // Signal-slot connections (to be implemented)
    connect(registerButton, &QPushButton::clicked, this, []() {
        qDebug() << "Register button clicked!";
    });
    connect(startSessionButton, &QPushButton::clicked, this, []() {
        qDebug() << "Start session button clicked!";
    });
    connect(endSessionButton, &QPushButton::clicked, this, []() {
        qDebug() << "End session button clicked!";
    });

    return actionsLayout;
}

AdminPanel::~AdminPanel()
{
    delete ui;
}
