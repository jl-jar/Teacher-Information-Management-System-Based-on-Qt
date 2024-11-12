#include "dialogteacher.h"
#include "ui_dialogteacher.h"

DialogTeacher::DialogTeacher( QWidget *parent, Teacher* teacher) :
    QDialog(parent),
    ui(new Ui::DialogTeacher)
{
    ui->setupUi(this);
    this->teacher = teacher;

    ui->dateEditBirthDate->setCalendarPopup(true); //日历的显示方式

    if(teacher)//当形参teacher非空时，用于修改教师信息，调用以下代码把原数据显示在对话框中
    {
        ui->lineEditId->setText(QString::number(teacher->id));
        ui->lineEditName->setText(teacher->name);
        ui->checkBoxGender->setChecked(teacher->gender);
        ui->dateEditBirthDate->setDate(teacher->birthDate);
        ui->lineEditJobTitle->setText(teacher->jobTitle);
        ui->lineEditHighestDegree->setText(teacher->highestDegree);
        ui->lineEditMonthSalary->setText(teacher->monthSalary);
        ui->checkBoxMarriage->setChecked(teacher->marriage);
    }
}

DialogTeacher::~DialogTeacher()
{
    delete ui;
}

void DialogTeacher::on_buttonBox_accepted()//“添加教师”页面OK按钮的槽函数
{
    if(!teacher)//判断是修改还是增加
        teacher = new Teacher; //添加一个教师
    teacher->id = ui->lineEditId->text().toInt();//获取教师编号
    teacher->name = ui->lineEditName->text();//获取姓名
    teacher->gender = ui->checkBoxGender->checkState();//获取性别
    teacher->birthDate = ui->dateEditBirthDate->date();//获取生日
    teacher->jobTitle = ui->lineEditJobTitle->text();//获取职称
    teacher->highestDegree = ui->lineEditHighestDegree->text();//获取最后学历
    teacher->monthSalary = ui->lineEditMonthSalary->text();//获取月薪  
    teacher->marriage = ui->checkBoxMarriage->checkState();//获取婚否
}

void DialogTeacher::on_buttonBox_rejected()//“添加教师”页面Cancel按钮的槽函数
{
    close();
}

void DialogTeacher::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}

