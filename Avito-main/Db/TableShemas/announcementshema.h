#ifndef ANNOUNCEMENTSHEMA_H
#define ANNOUNCEMENTSHEMA_H

#include "basetableshema.h"

class AnnouncementShema : public BaseTableShema
{
public:
    AnnouncementShema();

    virtual QString AsString() override;
};

#endif // ANNOUNCEMENTSHEMA_H
