#include "announcementdetailsviewmodel.h"
#include "ui_announcementdetailsviewmodel.h"

#include "Repositories/usersrepository.h"
#include "Repositories/categoryrepository.h"
#include "Session/currentsession.h"

AnnouncementDetailsViewModel::AnnouncementDetailsViewModel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AnnouncementDetailsViewModel)
{
    ui->setupUi(this);

    Setup();
}

void AnnouncementDetailsViewModel::Setup(){

    ui->name->setReadOnly(true);
    ui->phoneNumber->setReadOnly(true);
    ui->announcementName->setReadOnly(true);
    ui->announcementDesc->setReadOnly(true);
    ui->announcementPrice->setReadOnly(true);
    ui->category->setReadOnly(true);
}

void AnnouncementDetailsViewModel::SetShowOwnerContancts(bool showOrNot){

    if(showOrNot == true){
        ui->notAuthorizedMessage->setVisible(false);
    }
    else{
        ui->notAuthorizedMessage->setVisible(true);
    }

    ui->phoneLabel->setVisible(showOrNot);
    ui->nameLabel->setVisible(showOrNot);
    ui->name->setVisible(showOrNot);
    ui->phoneNumber->setVisible(showOrNot);
}

void AnnouncementDetailsViewModel::PrepareForShowing(const Announcement& announcement){

    int announcementDetailsIndex = 1;

    ui->tabWidget->setCurrentIndex(announcementDetailsIndex);

    if(CurrentSession::GetInstance().GetUser().Name != ""){

        UsersRepository repos;
        auto announcementOwner = repos.GetById(announcement.UserId);

        ui->name->setText(announcementOwner.Name);
        ui->phoneNumber->setText("+" + announcementOwner.Phone);

        SetShowOwnerContancts(true);
    }
    else{
        SetShowOwnerContancts(false);
    }

    CategoryRepository categoryRepos;

    ui->announcementName->setText(announcement.Name);
    ui->announcementDesc->setText(announcement.Description);
    ui->announcementPrice->setText(QString::number(announcement.Price));
    ui->category->setText(categoryRepos.GetById(announcement.CategoryId).Name);

    auto imageFullPath = destDirPath + announcement.Image;

    QPixmap imagePixmap(imageFullPath);

    ui->image->setPixmap(imagePixmap.scaled(ui->image->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

AnnouncementDetailsViewModel::~AnnouncementDetailsViewModel()
{
    delete ui;
}

void AnnouncementDetailsViewModel::on_back_clicked()
{
    emit onGoBackRequested();
}

