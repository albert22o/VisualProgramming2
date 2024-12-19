#ifndef NEWSEANSWINDOW_H
#define NEWSEANSWINDOW_H

#include <QDialog>
#include "Domain/computer.h"

namespace Ui {
class NewSeansWindow;
}

class NewSeansWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewSeansWindow(const Computer &computer, QWidget *parent = nullptr);
    ~NewSeansWindow();

private slots:

    void on_startSession_clicked();

    void on_cancel_clicked();

private:
    Ui::NewSeansWindow *ui;

    void Setup(const Computer &computer);
};

#endif // NEWSEANSWINDOW_H
