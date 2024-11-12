#include "dialogcourse.h"
#include "ui_dialogcourse.h"
#include "course.h"

DialogCourse::DialogCourse(QWidget *parent,Course* course) :
    QDialog(parent),
    ui(new Ui::DialogCourse)
{
    ui->setupUi(this);
    this->course = course;
    if(course)//当形参course非空时，用于修改课程信息，调用以下代码把原数据显示在对话框中
    {
        ui->lineEditCourseId->setText(course->courseId);
        ui->lineEditCourseName->setText(course->courseName);
        ui->lineEditCourseHour->setText(course->courseHour);
        ui->lineEditCredit->setText(course->credit);
        ui->lineEditTeachingClass->setText(course->TeachingClass);
        ui->lineEditClassroom->setText(course->classroom);
        ui->lineEditSemester->setText(course->semester);
    }
}

DialogCourse::~DialogCourse()
{
    delete ui;
}

void DialogCourse::on_buttonBoxAddCourse_accepted()
{
    if(!course)
        course = new Course;
    course->courseId = ui->lineEditCourseId->text();
    course->courseName = ui->lineEditCourseName->text();
    course->courseHour = ui->lineEditCourseHour->text();
    course->credit = ui->lineEditCredit->text();
    course->TeachingClass = ui->lineEditTeachingClass->text();
    course->classroom = ui->lineEditClassroom->text();
    course->semester = ui->lineEditSemester->text();
}
