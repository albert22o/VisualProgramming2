#include "announcementviewmodel.h"
#include "ui_announcementviewmodel.h"

#include <QPainter>
#include <QPainterPath>

#include "Repositories/categoryrepository.h"
#include "RoleManagment/rolemanager.h"

AnnouncementViewModel::AnnouncementViewModel(const QSize& size, const Announcement& announcement, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AnnouncementViewModel)
{
    ui->setupUi(this);

    setFixedSize(size);

    Setup(announcement);

    ConnectWithRoleManager();
    ReactOnRoleChanged(RoleManager::GetInstance().GetRole());
}

void AnnouncementViewModel::Update(const Announcement& announcement){

    Setup(announcement);
}

bool AnnouncementViewModel::IsAnnouncementOfUser(const User& user){

    if(announcement.UserId == user.Id){
        return true;
    }

    return false;
}

AnnouncementViewModel::~AnnouncementViewModel()
{
    delete ui;
}

Announcement AnnouncementViewModel::GetAnnouncement(){
    return announcement;
}

void AnnouncementViewModel::Setup(const Announcement& ann){

    announcement = ann;

    ui->name->setText(announcement.Name);
    ui->price->setText(QString::number(announcement.Price));

    CategoryRepository repos;
    auto category = repos.GetById(announcement.CategoryId);

    ui->category->setText(category.Name);

    QImage image;

    if (image.load(destDirPath + announcement.Image)) {

        auto imagePixmap = QPixmap::fromImage(image);

        auto imageSize = size() * 0.8;

        ui->image->setPixmap(RoundImage(imagePixmap.scaled(imageSize ,Qt::IgnoreAspectRatio, Qt::SmoothTransformation),64));
    }
}

QPixmap AnnouncementViewModel::RoundImage(const QPixmap& src, int radius) {

    QPixmap result(src.size());
    result.fill(Qt::transparent);

    QPainter painter(&result);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.addRoundedRect(src.rect(), radius, radius);

    painter.setClipPath(path);

    painter.drawPixmap(0, 0, src);

    return result;
}

void AnnouncementViewModel::on_remove_clicked()
{
    emit onRemoveRequested(this);
}

void AnnouncementViewModel::ReactOnRoleChanged(Role newRole){

    AnnouncementViewModel::RoleChangedTracker::ReactOnRoleChanged(newRole);
}

void AnnouncementViewModel::ConnectWithRoleManager(){

    connect(&RoleManager::GetInstance(), &RoleManager::roleChanged,this,&AnnouncementViewModel::ReactOnRoleChanged);
}

void AnnouncementViewModel::AdaptAdminView(){

    ui->remove->setVisible(true);
    ui->showDetails->setVisible(true);
    ui->edit->setVisible(false);
}

void AnnouncementViewModel::AdaptUserView(const User& user){

    ui->remove->setVisible(false);

    if(IsAnnouncementOfUser(user)){
        ui->edit->setVisible(true);
        ui->showDetails->setVisible(false);
    }
    else{
        ui->showDetails->setVisible(true);
        ui->edit->setVisible(false);
    }
}

void AnnouncementViewModel::AdaptGuestView(){

    ui->remove->setVisible(false);
    ui->edit->setVisible(false);
    ui->showDetails->setVisible(true);
}

void AnnouncementViewModel::on_edit_clicked()
{
    emit onEditRequested(this);
}


void AnnouncementViewModel::on_showDetails_clicked()
{
    emit onShowDetailsRequested(this);
}

