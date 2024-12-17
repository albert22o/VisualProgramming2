#ifndef ANNOUNCEMENTDETAILSVIEWMODEL_H
#define ANNOUNCEMENTDETAILSVIEWMODEL_H

#include <QWidget>
#include <Domain/announcement.h>

namespace Ui {
class AnnouncementDetailsViewModel;
}

class AnnouncementDetailsViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit AnnouncementDetailsViewModel(QWidget *parent = nullptr);
    ~AnnouncementDetailsViewModel();

    void PrepareForShowing(const Announcement& announcement);

signals:
    void onGoBackRequested();

private slots:
    void on_back_clicked();

private:
    const QString destDirPath = "../../Resources/Images/";

    void Setup();
    void SetShowOwnerContancts(bool showOrNot);
    Ui::AnnouncementDetailsViewModel *ui;
};

#endif // ANNOUNCEMENTDETAILSVIEWMODEL_H
