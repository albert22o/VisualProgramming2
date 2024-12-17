#ifndef CREATEANNOUNCEMENTVIEWMODEL_H
#define CREATEANNOUNCEMENTVIEWMODEL_H

#include <QWidget>
#include <QPixmap>
#include "Domain/announcement.h"
#include "ViewModels/announcementviewmodel.h"

enum ViewModelMode{
    CreateMode = 1,
    EditMode = 2,
};


namespace Ui {
class CreateAnnouncementViewModel;
}

class CreateAnnouncementViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAnnouncementViewModel(QWidget *parent = nullptr);
    ~CreateAnnouncementViewModel();

    void SetMode(ViewModelMode mode);

    void PrepareForUpdate(AnnouncementViewModel* announcementViewModel);

    void BeginReadyForNextAnnouncement();

signals:
    void onCancelReqested();
    void onAnnouncementCreated(const Announcement& announcement);
    void onAnnouncementUpdated(AnnouncementViewModel* updatedAnnoucement);
    void onAnnouncementDeleteRequested(AnnouncementViewModel* announcement);

private slots:
    void on_cancelButton_clicked();

    void on_addImage_clicked();

    void on_createAnnouncement_clicked();

    void on_closeAnnouncement_clicked();

private:
    AnnouncementViewModel* announcementViewModelTemp = nullptr;

    ViewModelMode mode = ViewModelMode::CreateMode;

    QString currentImageFullPath;
    const QString destDirPath = "../../Resources/Images/";

    void AddCategories();

    Ui::CreateAnnouncementViewModel *ui;
    void DisplayImage(const QString& fileName);

    void CopyImageToResourcesDir(const QString& sourceFileName);

    void UpdateAnnouncement(Announcement announcement);
    void CreateAnnouncement(Announcement announcement);

    QPixmap imagePixmap;
    QPixmap originalPixmap;
    QString imagePath;
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // CREATEANNOUNCEMENTVIEWMODEL_H
