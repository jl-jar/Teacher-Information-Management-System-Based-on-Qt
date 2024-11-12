#ifndef DIALOGCOURSE_H
#define DIALOGCOURSE_H

#include "course.h"

#include <QDialog>

namespace Ui {
class DialogCourse;
}

class DialogCourse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCourse(QWidget *parent = nullptr,Course* course = NULL);
    ~DialogCourse();

    Course* course;

private slots:

    void on_buttonBoxAddCourse_accepted();

private:
    Ui::DialogCourse *ui;
};

#endif // DIALOGCOURSE_H
