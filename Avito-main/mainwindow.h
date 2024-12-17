#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ViewModels/homepage.h"
#include "ViewModels/loginviewmodel.h"
#include "ViewModels/createannouncementviewmodel.h"
#include "ViewModels/announcementdetailsviewmodel.h"

#include "rolechangedtracker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, RoleChangedTracker
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:    
    const QSize announcementSize = QSize(450,450);

    void ConnectWithViewModelsSignals();

    Ui::MainWindow *ui;

    HomePage* homePage;
    LoginViewModel* loginViewModel;
    CreateAnnouncementViewModel* createAnnouncementViewModel;
    AnnouncementDetailsViewModel* announcementDetailsViewModel;

    void Setup();
    void InitializeViewModels();
    void AddViewModels();
    void OnStartUp();
    void LoadCatalog();
    void LoadCategories();

    void ChangeViewModel(QWidget* newViewModel);

    void OnSuccessLogin(const User& user);
    void OnCreateAnnouncementViewModelRequested();
    void OnEnterLoginViewModelRequested();
    void OnExitLoginViewModelRequested();
    void OnShowAnnouncementDetailsGoBackRequested();
    void OnCreateAnnouncementCancelRequested();

    void OnAnnouncementEditRequested(AnnouncementViewModel* announcement);
    void OnAnnouncementCreated(const Announcement& announcement);
    void OnAnnouncementUpdated(AnnouncementViewModel* announcementViewModel);
    void onAnnouncementRemoveRequested(AnnouncementViewModel* announcementViewModel);

    void OnShowAnnounncementDetailsRequested(AnnouncementViewModel* announcement);

protected:
    virtual void ConnectWithRoleManager() override;
};

#endif // MAINWINDOW_H
