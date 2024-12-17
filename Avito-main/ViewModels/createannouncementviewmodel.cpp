#include "createannouncementviewmodel.h"
#include "ui_createannouncementviewmodel.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

#include "Repositories/categoryrepository.h"
#include "Repositories/announcementrepository.h"
#include "Session/currentsession.h"

CreateAnnouncementViewModel::CreateAnnouncementViewModel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateAnnouncementViewModel)
{
    ui->setupUi(this);

    ui->image->setScaledContents(true);

    AddCategories();
}

void CreateAnnouncementViewModel::PrepareForUpdate(AnnouncementViewModel* announcementViewModel){

    auto announcement = announcementViewModel->GetAnnouncement();

    ui->announcementDesc->setText(announcement.Description);
    ui->announcementName->setText(announcement.Name);
    ui->announcementPrice->setText(QString::number(announcement.Price));
    ui->imageName->setText(announcement.Image);
    ui->categorySelector->setCurrentIndex(announcement.CategoryId - 1);

    currentImageFullPath = destDirPath + announcement.Image;

    originalPixmap.load(currentImageFullPath);

    imagePixmap = originalPixmap.scaled(ui->image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui->image->setPixmap(imagePixmap);

    announcementViewModelTemp = announcementViewModel;
}

void CreateAnnouncementViewModel::BeginReadyForNextAnnouncement(){

    ui->announcementDesc->clear();
    ui->announcementName->clear();
    ui->announcementPrice->clear();
    ui->imageName->clear();
    ui->categorySelector->setCurrentIndex(0);
    ui->announcementDesc->setStyleSheet("");
    ui->announcementName->setStyleSheet("");
    ui->announcementPrice->setStyleSheet("");
    announcementViewModelTemp = nullptr;
    ui->image->clear();
}

void CreateAnnouncementViewModel::SetMode(ViewModelMode mode){

    if(mode == ViewModelMode::CreateMode){
        ui->createAnnouncement->setText("Создать объявление");
    }

    if(mode == ViewModelMode::EditMode){
        ui->createAnnouncement->setText("Обновить данные");
    }

    this->mode = mode;
}

CreateAnnouncementViewModel::~CreateAnnouncementViewModel()
{
    delete ui;
}

void CreateAnnouncementViewModel::on_cancelButton_clicked()
{
    emit onCancelReqested();
}

void CreateAnnouncementViewModel::on_addImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName
    (
        this, "Выберите изображение", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)"
    );

    if(!fileName.isEmpty()){
        imagePath = fileName;
    }

    ui->imageName->setText(QFileInfo(imagePath).fileName());

    DisplayImage(imagePath);
}

void CreateAnnouncementViewModel::DisplayImage(const QString& fileName){

    if (!fileName.isEmpty()) {

        originalPixmap.load(fileName);

        imagePixmap = originalPixmap.scaled(ui->image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        ui->image->setPixmap(imagePixmap);

        currentImageFullPath = fileName;
    }
}

void CreateAnnouncementViewModel::resizeEvent(QResizeEvent *event){

    if (!ui->image->pixmap().isNull()) {

        imagePixmap = originalPixmap.scaled(ui->image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        ui->image->setPixmap(imagePixmap);
    }

    QWidget::resizeEvent(event);
}

void CreateAnnouncementViewModel::CopyImageToResourcesDir(const QString& sourceFileName){

    auto destDir = destDirPath + QFileInfo(sourceFileName).fileName();

    QFile file(sourceFileName);

    QFile destFile(destDir);

    if (destFile.exists()) {
        destFile.close();
        return;
    }

    destFile.close();

    file.copy(destDir);

    file.close();
}

void CreateAnnouncementViewModel::AddCategories(){

    CategoryRepository repos;

    auto categories = repos.GetAll();

    int index = 0;

    ui->categorySelector->clear();

    for(auto& category : categories){

        ui->categorySelector->addItem(category.Name);
        ui->categorySelector->setItemData(index, category.Id);

        index++;
    }
}

void CreateAnnouncementViewModel::UpdateAnnouncement(Announcement announcement){
    AnnouncementRepository repos;

    repos.UpdateRecord(announcement);

    auto announcementId = announcementViewModelTemp->GetAnnouncement().Id; // костыль
    announcement.Id = announcementId;// костыль

    announcementViewModelTemp->Update(announcement);

    emit onAnnouncementUpdated(announcementViewModelTemp);
}

void CreateAnnouncementViewModel::CreateAnnouncement(Announcement announcement){

    AnnouncementRepository repos;

    announcement.Id = repos.AddRecord(announcement);

    emit onAnnouncementCreated(announcement);

    BeginReadyForNextAnnouncement();
}

void CreateAnnouncementViewModel::on_createAnnouncement_clicked()
{
    bool isTextEmpty = false;
    bool isDescriptionEmpty = false;
    bool isPriceEmpty = false;

    auto wrongStylesheet = "QLineEdit { border: 2px solid red; }";

    if(ui->announcementName->text().isEmpty()){
        ui->announcementName->setStyleSheet(wrongStylesheet);
        isTextEmpty = true;
    }

    if(ui->announcementDesc->toPlainText().isEmpty()){
        ui->announcementDesc->setStyleSheet("QTextEdit { border: 2px solid red; }");
        isDescriptionEmpty = true;
    }

    bool priceIsOk;
    auto price = ui->announcementPrice->text().toDouble(&priceIsOk);

    if(ui->announcementPrice->text().isEmpty()){
        ui->announcementPrice->setStyleSheet(wrongStylesheet);
        isPriceEmpty = true;
    }

    if(!priceIsOk){
        ui->announcementPrice->setStyleSheet(wrongStylesheet);
    }

    if(!isTextEmpty && !isDescriptionEmpty && !isPriceEmpty && priceIsOk){

        Announcement announcement;

        auto categorySelected = ui->categorySelector->currentIndex();
        auto categoryId = ui->categorySelector->itemData(categorySelected).toInt();

        announcement.CategoryId = categoryId;
        announcement.Name = ui->announcementName->text();
        announcement.Description = ui->announcementDesc->toPlainText();
        announcement.Price = ui->announcementPrice->text().toDouble();
        announcement.UserId = CurrentSession::GetInstance().GetUser().Id;
        announcement.Image = ui->imageName->text();

        CopyImageToResourcesDir(currentImageFullPath);

        switch(mode){
        case ViewModelMode::CreateMode:
            CreateAnnouncement(announcement);
            break;
        case ViewModelMode::EditMode:
            UpdateAnnouncement(announcement);
            break;
        }
    }
}

void CreateAnnouncementViewModel::on_closeAnnouncement_clicked()
{
    if(announcementViewModelTemp == nullptr){

        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("Объявление еще не создано");

        QTimer *timer = new QTimer();

        auto timeoutSecs = 5;

        QObject::connect(timer, &QTimer::timeout, [msgBox, &timeoutSecs, timer]() {
            timeoutSecs--;
            if (timeoutSecs == 0) {
                msgBox->close();
            } else {
                msgBox->setText(QString("Объявление еще не создано (%1) сек.").arg(timeoutSecs));
            }
        });

        timer->start(1000);

        QObject::connect(msgBox, &QMessageBox::finished, [timer]() {
            timer->stop();
            timer->deleteLater();
        });

        msgBox->exec();
    }
    else{

        QMessageBox msgBox;
        msgBox.setWindowTitle("Удаление объявления");
        msgBox.setText("Вы уверены, что хотите удалить свое объявление?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.buttons()[0]->setText("Да");
        msgBox.buttons()[1]->setText("Нет");

        int ret = msgBox.exec();

        if (ret == QMessageBox::Yes) {
            emit onAnnouncementDeleteRequested(announcementViewModelTemp);
        }
    }
}

