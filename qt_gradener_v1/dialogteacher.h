#ifndef DIALOGTEACHER_H
#define DIALOGTEACHER_H

#include "teacher.h"

#include <QDialog>

namespace Ui {
class DialogTeacher;
}

class DialogTeacher : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTeacher(QWidget *parent = nullptr,Teacher* teacher = NULL);
    ~DialogTeacher();

    Teacher* teacher;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogTeacher *ui;
};

#endif // DIALOGTEACHER_H
