#include "dialogcourse.h"
#include "dialoggenderfilter.h"
#include "dialoglogin.h"
#include "dialogmarriagefilter.h"
#include "dialogsearch.h"
#include "dialogteacher.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QStyleFactory>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置背景图片
    this->setObjectName("教师信息界面");
    this->setStyleSheet("#mainWindow{border-image:url(:/background/picture4.png);}");

    QApplication::setStyle(QStyleFactory::create("Fusion"));//增加表格美观度：用于表格标题和后面数据之间增加分隔线
    ui->stackedWidget->setCurrentIndex(0);

    ui->tableWidgetTeacher->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetCourse->setEditTriggers(QAbstractItemView::NoEditTriggers);//单元格不可编辑

    ui->tableWidgetTeacher->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetCourse->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应表头宽度


    //登陆界面
    DialogLogIn login;
    login.setWindowTitle("登陆界面");
    if((login.exec() == QDialog::Accepted) && (login.user == login.user_name) && (login.key == login.password))
    {
        login.close();
    }
    else
    {
        if(login.exec() == QDialog::Rejected)
            exit(0);
        MainWindow mainw;
        mainw.close();
    }
}

MainWindow::~MainWindow()
{
    removeAllTeacher();
    delete ui;
}

bool MainWindow::addTeacher(Teacher *teacher)//添加教师
{
    teacherArray.append(teacher);
    return true;
}

bool MainWindow::removeTeacher(int id)//删除指定教师
{
    for(int i=0; i<teacherArray.length();i++)
    {
        if(id == teacherArray[i]->id)
        {
            delete teacherArray[i];
            teacherArray.removeAt(i);
            return true;
        }
    }
    return false;
}

void MainWindow::removeAllTeacher()//删除所有教师
{
    for(int i=teacherArray.length()-1;i>=0;i--)
    {
        delete teacherArray[i];
        teacherArray.removeAt(i);
    }
}

Teacher *MainWindow::getTeacher(int id)//查找教师
{
    for(int i=0; i<teacherArray.length();i++)
    {
        if(id == teacherArray[i]->id)
            return teacherArray[i];
    }
    return NULL;
}

void MainWindow::showTeacher(int row, Teacher* teacher)//展示教师信息
{
    ui->tableWidgetTeacher->insertRow(row);
    //insertRow()为插入一空行
    ui->tableWidgetTeacher->setItem(row,0,new QTableWidgetItem(QString::number(teacher->id)));//教师编号
    ui->tableWidgetTeacher->setItem(row,1,new QTableWidgetItem(teacher->name));//姓名
    ui->tableWidgetTeacher->setItem(row,2,new QTableWidgetItem(teacher->gender?"男":"女"));//性别
    ui->tableWidgetTeacher->setItem(row,3,new QTableWidgetItem(teacher->birthDate.toString("yyyy-MM-dd")));//生日//MM大写是为了和mm（分钟）区分开
    ui->tableWidgetTeacher->setItem(row,4,new QTableWidgetItem(teacher->jobTitle));//职称
    ui->tableWidgetTeacher->setItem(row,5,new QTableWidgetItem(teacher->highestDegree));//最后学历
    ui->tableWidgetTeacher->setItem(row,6,new QTableWidgetItem(teacher->monthSalary));//月薪
    ui->tableWidgetTeacher->setItem(row,7,new QTableWidgetItem(teacher->marriage?"已婚":"未婚"));//婚否
    //setItem()第一形参为行数，第二形参为列数，第三形参为数据

    QPushButton* pushButton = new QPushButton("修改",this);
    ui->tableWidgetTeacher->setCellWidget(row,8,pushButton);//给每一行加上修改按钮
    //setCellWidget()的参数分别为：行、列、按钮

    connect(pushButton, &QPushButton::clicked,
       [=]()
        {
        int row = ui->tableWidgetTeacher->currentRow();  //获取“修改按钮”所在的行
        int id = ui->tableWidgetTeacher->item(row,0)->text().toInt(); //获取“修改按钮”所在行（item）显示的教师编号
        Teacher* teacher = getTeacher(id);  //重新定义teacher,根据编号获取教师
        if(teacher)
        {
            DialogTeacher dlg(this,teacher); //注意：将要修改的教师传入对话框对象中
            dlg.setWindowTitle("修改教师信息");
            if(QDialog::Accepted == dlg.exec())
            {
                //将修改结果进行更新显示，只作必要项的更新
                ui->tableWidgetTeacher->item(row,0)->setText(QString::number(dlg.teacher->id));
                ui->tableWidgetTeacher->item(row,1)->setText(dlg.teacher->name);
                ui->tableWidgetTeacher->item(row,2)->setText(dlg.teacher->gender?"男":"女");
                ui->tableWidgetTeacher->item(row,3)->setText(dlg.teacher->birthDate.toString("yyyy-MM-dd"));
                ui->tableWidgetTeacher->item(row,4)->setText(dlg.teacher->jobTitle);
                ui->tableWidgetTeacher->item(row,5)->setText(dlg.teacher->highestDegree);
                ui->tableWidgetTeacher->item(row,6)->setText(dlg.teacher->monthSalary);
                ui->tableWidgetTeacher->item(row,7)->setText(dlg.teacher->marriage?"已婚":"未婚");
            }
        }
    });

    pushButton = new QPushButton("删除",this);
    ui->tableWidgetTeacher->setCellWidget(row,9,pushButton);//给每一行加上删除按钮
    connect(pushButton,&QPushButton::clicked,
    [=]()
    {
        QMessageBox box;
        int ret = box.question(this,"删除教师","确认删除？");
        if(QMessageBox::Yes == ret)  //按了"Yes"按钮
        {
            int row = ui->tableWidgetTeacher->currentRow();
            int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
            removeTeacher(id); //后端删除数据
            ui->tableWidgetTeacher->removeRow(row); //从前端显示表格中删除显示
        }
    });

    pushButton = new QPushButton("授课信息",this);
    ui->tableWidgetTeacher->setCellWidget(row,10,pushButton);//给每一行加上"授课信息"按钮
    connect(pushButton,&QPushButton::clicked,
    [=]()
    {
        int row = ui->tableWidgetTeacher->currentRow();
        int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
        Teacher* teacher = getTeacher(id); //取得教师
        if(teacher)
        {
            ui->stackedWidget->setCurrentIndex(1);  //切换到授课信息界面
            //在新数据显示之前，先将原有数据清空
            int row = ui->tableWidgetCourse->rowCount();
            for(int i=0; i<row; i++)
                ui->tableWidgetCourse->removeRow(0);
            //新数据显示
            for(int i=0; i<teacher->courseArray.length();i++)
                showCourse(i,teacher->courseArray[i]);
        }
    });
}

void MainWindow::showCourse(int row, Course* course)
{
    ui->tableWidgetCourse->insertRow(row);
    ui->tableWidgetCourse->setItem(row,0,new QTableWidgetItem(course->courseId));//课程编号
    ui->tableWidgetCourse->setItem(row,1,new QTableWidgetItem(course->courseName));//课程名称
    ui->tableWidgetCourse->setItem(row,2,new QTableWidgetItem(course->courseHour));//课时
    ui->tableWidgetCourse->setItem(row,3,new QTableWidgetItem(course->credit));//学分
    ui->tableWidgetCourse->setItem(row,4,new QTableWidgetItem(course->classroom));//教室
    ui->tableWidgetCourse->setItem(row,5,new QTableWidgetItem(course->TeachingClass));//班级
    ui->tableWidgetCourse->setItem(row,6,new QTableWidgetItem(course->semester));//学期

    QPushButton* pushButton = new QPushButton("修改", this);
    ui->tableWidgetCourse->setCellWidget(row,7,pushButton);
    connect(pushButton, &QPushButton::clicked,
    [=]()
    {
        int row = ui->tableWidgetTeacher->currentRow();
        int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
        Teacher* teacher = getTeacher(id);
        if(teacher)
        {
            row = ui->tableWidgetCourse->currentRow();
            QString courseId = ui->tableWidgetCourse->item(row,0)->text();
            Course* course = teacher->getCourse(courseId);
            DialogCourse dlg(this,course);
            dlg.setWindowTitle("修改授课信息");
            if(QDialog::Accepted == dlg.exec())
            {
                ui->tableWidgetCourse->item(row,0)->setText(course->courseId);
                ui->tableWidgetCourse->item(row,1)->setText(course->courseName);
                ui->tableWidgetCourse->item(row,2)->setText(course->courseHour);
                ui->tableWidgetCourse->item(row,3)->setText(course->credit);
                ui->tableWidgetCourse->item(row,4)->setText(course->classroom);
                ui->tableWidgetCourse->item(row,5)->setText(course->TeachingClass);
                ui->tableWidgetCourse->item(row,6)->setText(course->semester);
            }
        }
    });

    pushButton = new QPushButton("删除", this);
    ui->tableWidgetCourse->setCellWidget(row,8,pushButton);
    connect(pushButton,&QPushButton::clicked,
    [=]()
    {
        int row = ui->tableWidgetTeacher->currentRow();
        int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
        Teacher* teacher = getTeacher(id);
        QMessageBox box;
        int ret = box.question(this,"删除授课信息","确认删除？");
        if(QMessageBox::Yes == ret)
        {
            row = ui->tableWidgetCourse->currentRow();
            QString courseId = ui->tableWidgetCourse->item(row,0)->text();
            teacher->removeCourse(courseId);
            ui->tableWidgetCourse->removeRow(row);
        }
    });
}

void MainWindow::on_pushButtonExit_clicked()//首页“退出”按钮的槽函数
{
    close();//点击“退出”关闭该界面
}



void MainWindow::on_pushButtonAddCourse_clicked()//"添加课程"的槽函数
{
    DialogCourse dlg(this);
    dlg.setWindowTitle("添加授课信息");
    if(QDialog::Accepted == dlg.exec())  //判断是否按了确定关闭对话框（返回值是QDialog::Accepted）
    {
        int row = ui->tableWidgetTeacher->currentRow();
        int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
        Teacher* teacher = getTeacher(id);
        if(teacher)
        {
            teacher->addCourse(dlg.course);
            row = ui->tableWidgetCourse->rowCount();
            showCourse(row,dlg.course);
        }
    }
}

void MainWindow::on_pushButtonBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionFileOpen_triggered()//"打开文件"的槽函数
{
    QString path = QFileDialog::getOpenFileName(this,"open","../");
    if(false == path.isEmpty())
    {
        QFile file;
        file.setFileName(path);
        bool isOk = file.open(QIODevice::ReadOnly);
        if(true == isOk)
        {
            pathName = path;
            removeAllTeacher();
            QDataStream stream(&file);
            int i,length;
            stream >> length;
            for(i=0; i<length; i++)
            {
                Teacher* teacher = new Teacher;
                stream >> *teacher;
                teacherArray.append(teacher);
            }
            file.close();

            int row = ui->tableWidgetTeacher->rowCount();
            for(int i=0; i<row; i++)
            ui->tableWidgetTeacher->removeRow(0);
            ui->tableWidgetTeacher->clearContents();

            for(i=0; i<teacherArray.length(); i++)
                showTeacher(i,teacherArray[i]);
        }
    }
}

void MainWindow::on_actionFileSave_triggered()//"保存文件"的槽函数
{
    if(false == pathName.isEmpty())
    {
        QFile file;
        file.setFileName(pathName);
        bool isOk = file.open(QIODevice::WriteOnly);
        if(true == isOk)
        {
            QDataStream stream(&file);
            int length = teacherArray.length();
            stream << length;
            for(int i=0; i<length; i++)
                stream<<*teacherArray[i];
            file.close();
        }
    }
    else //保存时，如未打开过文件，调用“另存为”保存
        on_actionFileSaveAs_triggered();
}

void MainWindow::on_actionFileSaveAs_triggered()//"另存为"的槽函数
{
    QString path = QFileDialog::getSaveFileName(this,"Save as","../");
    if(false == path.isEmpty())
    {
        QFile file;
        file.setFileName(path);
        bool isOk = file.open(QIODevice::WriteOnly);
        if(true == isOk)
        {
            pathName = path;
            QDataStream stream(&file);
            int length = teacherArray.length();
            stream << length;
            for(int i=0; i<length; i++)
                stream<<*teacherArray[i];
            file.close();
        }
    }
}

void MainWindow::on_pushButtonAddTeacher_clicked()//首页“添加教师”按钮的槽函数
{
    DialogTeacher dlg(this);
    dlg.setWindowTitle("数据可视化-性别");
    if(dlg.exec() == QDialog::Accepted)//exec()用于展示窗口，exec()包含show()，如果只用show()的话窗口只会一闪而过
    {
        addTeacher(dlg.teacher);
        int row = ui->tableWidgetTeacher->rowCount();
        showTeacher(row,dlg.teacher);
    }
}


void MainWindow::on_actionSearch_triggered()
{
    DialogSearch dlg;
    dlg.setWindowTitle("查找教师");
    if(dlg.exec() == QDialog::Accepted)
    {
        Teacher* teacher = getTeacher(dlg.idSearch);
        int i = 0;
        showTeacher(i, teacher);
        int row = ui->tableWidgetTeacher->rowCount();
        for(int i=1; i<row; i++)
            ui->tableWidgetTeacher->removeRow(1);//removeRow()的参数是删除第几行
    }
}

void MainWindow::filter(QTableWidget* source, QString &text)
{
    int row = source->rowCount();//获得行数
    if ("" == text)
    {   //判断输入是否为空
        for (int i = 0; i < row; i++)
        {
            source->setRowHidden(i, false);//显示所有行
        }
    }
    else
    {
        //获取符合条件的索引
        QList <QTableWidgetItem*> item = source->findItems(text, Qt::MatchContains);

        for (int i = 0; i < row; i++) {
            source->setRowHidden(i, true);//隐藏所有行
        }

        if (!item.isEmpty()) { //不为空
            for (int i = 0; i < item.count(); i++) {
                source->setRowHidden(item.at(i)->row(),false);//item.at(i).row()输出行号
            }
        }
    }
}

void MainWindow::on_actionGenderFilter_triggered()
{
    DialogGenderFilter dlg;
    dlg.setWindowTitle("筛选功能");
    if(dlg.exec() == QDialog::Accepted)
    {
        filter(ui->tableWidgetTeacher, dlg.genderFilter);
    }
}

void MainWindow::on_actionMarriageFilter_triggered()
{
    DialogMarriageFilter dlg;
    dlg.setWindowTitle("筛选功能");
    if(dlg.exec() == QDialog::Accepted)
    {
        filter(ui->tableWidgetTeacher, dlg.marriageFilter);
    }
}
