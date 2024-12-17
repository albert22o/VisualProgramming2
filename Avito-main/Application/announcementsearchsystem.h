#ifndef ANNOUNCEMENTSEARCHSYSTEM_H
#define ANNOUNCEMENTSEARCHSYSTEM_H

#include <QString>
#include <QList>

#include "Domain/announcement.h"

class AnnouncementSearchSystem
{
public:
    AnnouncementSearchSystem();

    QList<Announcement> Search(const QList<Announcement>& announcements, const QString& query);

private:
    int CalcLevenshteinDistance(const QString& s1, const QString& s2);
    QString Transliterate(const QString& word);
    QList<std::string> Tokenize(const std::string& str);
    bool StartsWithAnyToken(const std::string& itemName, const std::string& query);
};

#endif // ANNOUNCEMENTSEARCHSYSTEM_H
