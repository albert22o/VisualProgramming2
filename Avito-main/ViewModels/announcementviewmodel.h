#ifndef ANNOUNCEMENTVIEWMODEL_H
#define ANNOUNCEMENTVIEWMODEL_H

#include <QWidget>

#include "Domain/announcement.h"
#include "Domain/user.h"
#include "rolechangedtracker.h"

namespace Ui {
class AnnouncementViewModel;
}

class AnnouncementViewModel : public QWidget, RoleChangedTracker
{
    Q_OBJECT

public:
    explicit AnnouncementViewModel(const QSize& size, const Announcement& announcement, QWidget *parent = nullptr);
    ~AnnouncementViewModel();

    Announcement GetAnnouncement();

    void Update(const Announcement& announcement);

signals:
    void onRemoveRequested(AnnouncementViewModel* announcementViewModel);
    void onEditRequested(AnnouncementViewModel* announcementViewModel);
    void onShowDetailsRequested(AnnouncementViewModel* announcementViewModel);

private slots:

    void on_remove_clicked();

    void on_edit_clicked();

    void on_showDetails_clicked();

private:
    Ui::AnnouncementViewModel *ui;

    void Setup(const Announcement& announcement);

    Announcement announcement;

    QString destDirPath = "../../Resources/Images/";

    QPixmap RoundImage(const QPixmap& src, int radius);


    bool IsAnnouncementOfUser(const User& user);
    void AdaptOnSpecificUser(const User& user);

protected:
    virtual void AdaptAdminView() override;
    virtual void AdaptUserView(const User& user) override;
    virtual void AdaptGuestView() override;

    virtual void ReactOnRoleChanged(Role newRole) override;
    virtual void ConnectWithRoleManager() override;
};

#endif // ANNOUNCEMENTVIEWMODEL_H
