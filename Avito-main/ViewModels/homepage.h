#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

#include "Domain/category.h"
#include "ViewModels/announcementviewmodel.h"
#include "rolechangedtracker.h"

#include "Application/announcementsearchsystem.h"

namespace Ui {
class HomePage;
}

class HomePage : public QWidget, RoleChangedTracker
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

    void AddAnnouncement(AnnouncementViewModel* announcementViewModel);
    void RemoveAnnouncement(AnnouncementViewModel* announcementViewModel);

    void AddCategories(const QList<Category>& categories);

    void SetAuthorizedView();
    void SetUnauthorizedView();

    void Search(const QString& announcementName);

signals:
    void onLoginRequested();
    void onCreateAnnouncementRequested();
    void onEditAnnouncementRequested(AnnouncementViewModel* announcement);
    void onAnnouncementUpdated(const Announcement& announcement, AnnouncementViewModel* announcementViewModel);
    void onShowAnnouncementDetailsRequested(AnnouncementViewModel* announcement);

private slots:
    void on_loginButton_clicked();
    void on_createAnnouncement_clicked();
    void on_categorySelector_activated(int index);

    void on_searchLine_textChanged(const QString &arg1);

private:
    AnnouncementSearchSystem search;

    void ConnectWithSignals(AnnouncementViewModel* announcementViewModel);

    void ResetGridParameters();
    void ClearGridFromAnnouncements();

    void RemoveAnnouncementFromList(AnnouncementViewModel* announcementViewModel);
    void RemoveAnnouncementFromDb(const Announcement& announcement);
    void AddAnnouncementOnGrid(AnnouncementViewModel* announcementViewModel);

    QList<Announcement> GetAnnouncementsByCategoryFilter(int index);

    virtual void AdaptAdminView() override;
    virtual void AdaptUserView(const User& user) override;
    virtual void AdaptGuestView() override;

    Ui::HomePage *ui;
    QList<AnnouncementViewModel*> announcements;

    int currentRow = 0;
    int currentColumn = 0;
    int currentRowWidth = 0;

    const QSize announcementSize = QSize(450,450);

protected:
    void resizeEvent(QResizeEvent *event) override;
    virtual void ReactOnRoleChanged(Role newRole) override;
    virtual void ConnectWithRoleManager() override;
};

#endif // HOMEPAGE_H
