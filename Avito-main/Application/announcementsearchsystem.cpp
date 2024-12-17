#include "announcementsearchsystem.h"

#include <QMap>

AnnouncementSearchSystem::AnnouncementSearchSystem() {}

int AnnouncementSearchSystem::CalcLevenshteinDistance(const QString& s1, const QString& s2){

    std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1));

    for (int i = 0; i <= s1.size(); ++i) {
        for (int j = 0; j <= s2.size(); ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j],
                               dp[i][j - 1],
                               dp[i - 1][j - 1]
                           });
            }
        }
    }

    return dp[s1.size()][s2.size()];
}

QList<std::string> AnnouncementSearchSystem::Tokenize(const std::string& str) {

    QList<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(' ');

    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(' ', start);
    }

    tokens.push_back(str.substr(start, end));

    return tokens;
}


bool AnnouncementSearchSystem::StartsWithAnyToken(const std::string& itemName, const std::string& query) {

    auto tokens = Tokenize(itemName);

    for (const auto& token : tokens) {

        if (token.rfind(query, 0) == 0) {
            return true;
        }
    }
    return false;
}

QList<Announcement> AnnouncementSearchSystem::Search(const QList<Announcement>& announcements, const QString& query) {

    QString lowerQuery = query.toLower();

    QList<Announcement> exactMatches;
    QList<std::pair<Announcement, int>> fuzzyResults;

    for (const auto& announcement : announcements) {
        QString lowerName = announcement.Name.toLower();

        if (lowerName == lowerQuery) {
            exactMatches.push_back(announcement);
        } else if (StartsWithAnyToken(lowerName.toStdString(), lowerQuery.toStdString())) {
            fuzzyResults.emplace_back(announcement, 0);
        } else {
            int distance = CalcLevenshteinDistance(Transliterate(lowerName), Transliterate(lowerQuery));
            fuzzyResults.emplace_back(announcement, distance);
        }
    }

    if (!exactMatches.empty()) {
        return exactMatches;
    }

    std::sort(fuzzyResults.begin(), fuzzyResults.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    QList<Announcement> sortedResults;
    for (const auto& result : fuzzyResults) {
        sortedResults.push_back(result.first);
    }

    return sortedResults;
}


QString AnnouncementSearchSystem::Transliterate(const QString& word){

    QMap<QString, QString> translitMap = {
        {"а", "a"}, {"б", "b"}, {"в", "v"}, {"г", "g"}, {"д", "d"},
        {"е", "e"}, {"ё", "yo"}, {"ж", "zh"}, {"з", "z"}, {"и", "i"},
        {"й", "y"}, {"к", "k"}, {"л", "l"}, {"м", "m"}, {"н", "n"},
        {"о", "o"}, {"п", "p"}, {"р", "r"}, {"с", "s"}, {"т", "t"},
        {"у", "u"}, {"ф", "f"}, {"х", "kh"}, {"ц", "ts"}, {"ч", "ch"},
        {"ш", "sh"}, {"щ", "shch"}, {"ъ", ""}, {"ы", "y"}, {"ь", ""},
        {"э", "e"}, {"ю", "yu"}, {"я", "ya"},

        {"А", "A"}, {"Б", "B"}, {"В", "V"}, {"Г", "G"}, {"Д", "D"},
        {"Е", "E"}, {"Ё", "Yo"}, {"Ж", "Zh"}, {"З", "Z"}, {"И", "I"},
        {"Й", "Y"}, {"К", "K"}, {"Л", "L"}, {"М", "M"}, {"Н", "N"},
        {"О", "O"}, {"П", "P"}, {"Р", "R"}, {"С", "S"}, {"Т", "T"},
        {"У", "U"}, {"Ф", "F"}, {"Х", "Kh"}, {"Ц", "Ts"}, {"Ч", "Ch"},
        {"Ш", "Sh"}, {"Щ", "Shch"}, {"Ъ", ""}, {"Ы", "Y"}, {"Ь", ""},
        {"Э", "E"}, {"Ю", "Yu"}, {"Я", "Ya"}
    };

    QString result;

    for (const QChar &ch : word) {

        QString strCh = QString(ch);

        if (translitMap.contains(strCh)) {
            result.append(translitMap[strCh]);
        }
        else {
            result.append(strCh);
        }
    }

    return result;
}
