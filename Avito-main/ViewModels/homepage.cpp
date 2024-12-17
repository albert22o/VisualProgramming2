#include "homepage.h"
#include "ui_homepage.h"

#include "RoleManagment/rolemanager.h"
#include "Repositories/announcementrepository.h"
#include "Session/currentsession.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);

    ui->searchLine->setPlaceholderText("Найти объявление");

    ConnectWithRoleManager();
    ReactOnRoleChanged(RoleManager::GetInstance().GetRole());
}

void HomePage::AddCategories(const QList<Category>& categories){

    ui->categorySelector->clear();

    ui->categorySelector->addItem("Все категории");
    ui->categorySelector->setItemData(0, 0);

    int index = 1;

    for(auto& category : categories){

        ui->categorySelector->addItem(category.Name);
        ui->categorySelector->setItemData(index, category.Id);

        index++;
    }
}

void HomePage::SetAuthorizedView(){
    ui->loginButton->setText("Выйти из аккаунта");
}

void HomePage::SetUnauthorizedView(){
    ui->loginButton->setText("Войти в аккуант");
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_loginButton_clicked()
{
    if(RoleManager::GetInstance().GetRole() != Role::GuestRole){

        RoleManager::GetInstance().SetRole(Role::GuestRole);

        auto emptyUser = User();

        CurrentSession::GetInstance().SetUser(emptyUser);

        SetUnauthorizedView();
    }

    emit onLoginRequested();
}

void HomePage::on_createAnnouncement_clicked()
{
    emit onCreateAnnouncementRequested();
}

void HomePage::AddAnnouncement(AnnouncementViewModel* announcementViewModel){

    announcementViewModel->setFixedSize(announcementSize);

    ConnectWithSignals(announcementViewModel);

    AddAnnouncementOnGrid(announcementViewModel);
    announcements.push_back(announcementViewModel);
}

void HomePage::RemoveAnnouncement(AnnouncementViewModel* announcementViewModel) {

    RemoveAnnouncementFromDb(announcementViewModel->GetAnnouncement());

    for (int i = 0; i < ui->catalog->rowCount(); ++i) {
        for (int j = 0; j < ui->catalog->columnCount(); ++j) {
            if (ui->catalog->itemAtPosition(i, j)
                && ui->catalog->itemAtPosition(i, j)->widget() == announcementViewModel) {

                ui->catalog->removeWidget(announcementViewModel);
                RemoveAnnouncementFromList(announcementViewModel);
                delete announcementViewModel;

                for (int col = j + 1; col < ui->catalog->columnCount(); ++col) {
                    if (ui->catalog->itemAtPosition(i, col)) {
                        QWidget* widgetToMove = ui->catalog->itemAtPosition(i, col)->widget();
                        ui->catalog->removeWidget(widgetToMove);
                        ui->catalog->addWidget(widgetToMove, i, col - 1);
                    }
                }

                return;
            }
        }
    }
}

void HomePage::RemoveAnnouncementFromList(AnnouncementViewModel* announcementViewModel){

    int index = announcements.indexOf(announcementViewModel);

    if (index != -1) {

        announcements.removeAt(index);
    }
}

void HomePage::RemoveAnnouncementFromDb(const Announcement& announcement){

    AnnouncementRepository repos;
    repos.DeleteById(announcement.Id);
}

void HomePage::AddAnnouncementOnGrid(AnnouncementViewModel* announcementViewModel){

    if (currentRowWidth + announcementSize.width() > width()) {

        currentRow++;
        currentRowWidth = 0;
        currentColumn = 0;
    }

    ui->catalog->addWidget(announcementViewModel, currentRow, currentColumn);
    currentRowWidth += announcementSize.width() + ui->catalog->spacing();

    currentColumn++;
}

void HomePage::resizeEvent(QResizeEvent *event){

    ResetGridParameters();

    int count = ui->catalog->count();

    for (int i = count - 1; i >= 0; --i){

        QLayoutItem *item = ui->catalog->itemAt(i);
        ui->catalog->removeItem(item);
        ui->catalog->removeWidget(item->widget());
    }

    for(size_t i=0;i<announcements.size();i++){

        AddAnnouncementOnGrid(announcements[i]);
    }

    QWidget::resizeEvent(event);
}

void HomePage::ClearGridFromAnnouncements(){

    ResetGridParameters();

    int count = ui->catalog->count();

    for (int i = count - 1; i >= 0; --i) {

        QLayoutItem *item = ui->catalog->itemAt(i);
        ui->catalog->removeItem( item );
        ui->catalog->removeWidget(item->widget());
        item->widget()->deleteLater();
    }

    announcements.clear();
}

void HomePage::ResetGridParameters(){

    currentRow = 0;
    currentColumn = 0;
    currentRowWidth = 0;
}

void HomePage::ConnectWithSignals(AnnouncementViewModel* announcementViewModel){

    connect(announcementViewModel, &AnnouncementViewModel::onRemoveRequested,this, &HomePage::RemoveAnnouncement);
    connect(announcementViewModel,&AnnouncementViewModel::onEditRequested,this, &HomePage::onEditAnnouncementRequested);
    connect(announcementViewModel, &AnnouncementViewModel::onShowDetailsRequested, this, &HomePage::onShowAnnouncementDetailsRequested);
}

void HomePage::ConnectWithRoleManager(){

    connect(&RoleManager::GetInstance(), &RoleManager::roleChanged, this,
            &HomePage::ReactOnRoleChanged);
}

void HomePage::ReactOnRoleChanged(Role newRole){

    HomePage::RoleChangedTracker::ReactOnRoleChanged(newRole);
}

void HomePage::AdaptAdminView(){

    ui->createAnnouncement->setEnabled(false);
    ui->roleMessage->setText("Администратор, " + CurrentSession::GetInstance().GetUser().Name);
}

void HomePage::AdaptUserView(const User& user){ // поправить в будущем

    ui->createAnnouncement->setEnabled(true);
    ui->roleMessage->setText("Пользователь, " + CurrentSession::GetInstance().GetUser().Name);
}

void HomePage::AdaptGuestView(){

    ui->createAnnouncement->setEnabled(false);

    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomNumber = std::rand() % 900000 + 100000;

    ui->roleMessage->setText("Гость №" + QString::number(randomNumber));
}

void HomePage::on_categorySelector_activated(int index)
{
    auto announcements = GetAnnouncementsByCategoryFilter(index);

    ClearGridFromAnnouncements();

    for(auto& announcement : announcements){
        AddAnnouncement(new AnnouncementViewModel(announcementSize, announcement));
    }

    on_searchLine_textChanged(ui->searchLine->text());
}

QList<Announcement> HomePage::GetAnnouncementsByCategoryFilter(int index){

    bool conversionOk;
    int dbCategoryIndex = ui->categorySelector->itemData(index).toInt(&conversionOk);

    if(!conversionOk){
        throw std::runtime_error("неправильное преобразование или в categorySelector в метаданных лежит не int");
    }

    int allCategoriesIndex = 0;

    QList<Announcement> announcements;

    AnnouncementRepository repos;

    if(dbCategoryIndex == allCategoriesIndex){

        announcements = repos.GetAll();
    }
    else{
        announcements = repos.GetByCategoryId(dbCategoryIndex);
    }

    return announcements;
}

void HomePage::on_searchLine_textChanged(const QString &text)
{
    auto currentCategoryIndex = ui->categorySelector->currentIndex();

    auto findedAnnouncements = search.Search(GetAnnouncementsByCategoryFilter(currentCategoryIndex), text);

    ClearGridFromAnnouncements();

    for(auto& announcement : findedAnnouncements){
        AddAnnouncement(new AnnouncementViewModel(announcementSize, announcement));
    }
}

void HomePage::Search(const QString& announcementName){
    on_searchLine_textChanged(announcementName);
}

