#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ViewModels/homepage.h"
#include "Repositories/announcementrepository.h"
#include "Repositories/categoryrepository.h"
#include "RoleManagment/rolemanager.h"
#include "Session/currentsession.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Setup();

    ConnectWithRoleManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Setup() {

    InitializeViewModels();
    AddViewModels();
    OnStartUp();
    ConnectWithViewModelsSignals();
    LoadCatalog();
    LoadCategories();
}

void MainWindow::LoadCatalog(){

    AnnouncementRepository repos;

    auto announcements = repos.GetAll();

    for(auto& announcement : announcements){

        homePage->AddAnnouncement(new AnnouncementViewModel(announcementSize, announcement));
    }
}

void MainWindow::LoadCategories(){

    CategoryRepository repos;

    auto categories = repos.GetAll();

    homePage->AddCategories(categories);
}

void MainWindow::InitializeViewModels(){

    homePage = new HomePage();
    loginViewModel = new LoginViewModel();
    createAnnouncementViewModel = new CreateAnnouncementViewModel();
    announcementDetailsViewModel = new AnnouncementDetailsViewModel();
}

void MainWindow::AddViewModels(){

    ui->stackedWidget->addWidget(homePage);
    ui->stackedWidget->addWidget(loginViewModel);
    ui->stackedWidget->addWidget(createAnnouncementViewModel);
    ui->stackedWidget->addWidget(announcementDetailsViewModel);
}

void MainWindow::OnStartUp(){

    ChangeViewModel(homePage);
}

void MainWindow::OnEnterLoginViewModelRequested(){

    ChangeViewModel(loginViewModel);
}

void MainWindow::OnExitLoginViewModelRequested(){

    ChangeViewModel(homePage);
}

void MainWindow::OnCreateAnnouncementViewModelRequested(){

    ChangeViewModel(createAnnouncementViewModel);
    createAnnouncementViewModel->BeginReadyForNextAnnouncement();
    createAnnouncementViewModel->SetMode(ViewModelMode::CreateMode);
}

void MainWindow::OnCreateAnnouncementCancelRequested(){
    ChangeViewModel(homePage);
}

void MainWindow::ConnectWithViewModelsSignals(){

    connect(homePage, &HomePage::onLoginRequested, this, &MainWindow::OnEnterLoginViewModelRequested);
    connect(loginViewModel, &LoginViewModel::onCancelRequested, this, &MainWindow::OnExitLoginViewModelRequested);
    connect(homePage, &HomePage::onCreateAnnouncementRequested, this, &MainWindow::OnCreateAnnouncementViewModelRequested);
    connect(createAnnouncementViewModel, &CreateAnnouncementViewModel::onCancelReqested, this, &MainWindow::OnCreateAnnouncementCancelRequested);
    connect(loginViewModel, &LoginViewModel::onLoginSuccess, this, &MainWindow::OnSuccessLogin);
    connect(createAnnouncementViewModel, &CreateAnnouncementViewModel::onAnnouncementCreated, this, &MainWindow::OnAnnouncementCreated);
    connect(homePage, &HomePage::onEditAnnouncementRequested, this, &MainWindow::OnAnnouncementEditRequested);
    connect(createAnnouncementViewModel, &CreateAnnouncementViewModel::onAnnouncementUpdated, this, &MainWindow::OnAnnouncementUpdated);
    connect(announcementDetailsViewModel, &AnnouncementDetailsViewModel::onGoBackRequested, this, &MainWindow::OnShowAnnouncementDetailsGoBackRequested);
    connect(homePage, &HomePage::onShowAnnouncementDetailsRequested, this, &MainWindow::OnShowAnnounncementDetailsRequested);
    connect(createAnnouncementViewModel, &CreateAnnouncementViewModel::onAnnouncementDeleteRequested, this, &MainWindow::onAnnouncementRemoveRequested);
}

void MainWindow::onAnnouncementRemoveRequested(AnnouncementViewModel* announcementViewModel){
    ChangeViewModel(homePage);
    homePage->RemoveAnnouncement(announcementViewModel);
    homePage->Search(""); // костыль чтобы порядок объявлений стал нормальным
}

void MainWindow::OnShowAnnounncementDetailsRequested(AnnouncementViewModel* announcement){

    announcementDetailsViewModel->PrepareForShowing(announcement->GetAnnouncement());
    ChangeViewModel(announcementDetailsViewModel);
}

void MainWindow::OnShowAnnouncementDetailsGoBackRequested(){
    ChangeViewModel(homePage);
}

void MainWindow::OnAnnouncementEditRequested(AnnouncementViewModel* announcementViewModel){

    createAnnouncementViewModel->SetMode(ViewModelMode::EditMode);
    createAnnouncementViewModel->PrepareForUpdate(announcementViewModel);
    ChangeViewModel(createAnnouncementViewModel);
}

void MainWindow::OnAnnouncementCreated(const Announcement& announcement){

    ChangeViewModel(homePage);
    homePage->AddAnnouncement(new AnnouncementViewModel(announcementSize, announcement));
}

void MainWindow::OnAnnouncementUpdated(AnnouncementViewModel* announcementViewModel){

    ChangeViewModel(homePage);
    createAnnouncementViewModel->SetMode(ViewModelMode::CreateMode);
    createAnnouncementViewModel->BeginReadyForNextAnnouncement();
    //announcementViewModel->Update(announcement);
}

void MainWindow::OnSuccessLogin(const User& user){

    CurrentSession::GetInstance().SetUser(user); // порядок важен, сначала сохраняем в сессию!
    RoleManager::GetInstance().SetRole(user.RoleId); // поместить это в класс Application

    ChangeViewModel(homePage);
    homePage->SetAuthorizedView();
}

void MainWindow::ChangeViewModel(QWidget* newViewModel){

    ui->stackedWidget->setCurrentWidget(newViewModel);
}

void MainWindow::ConnectWithRoleManager(){

}
