#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "teacher.h"

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QList<Teacher*> teacherArray;//教师集合

    QString pathName;//加入成员数据，记录文件路径，用于“保存”或“另存为”

    bool addTeacher(Teacher* teacher);//添加教师
    bool removeTeacher(int id);//删除指定教师
    void removeAllTeacher();//删除所有教师
    Teacher* getTeacher(int id);//查找教师

    void showTeacher(int row, Teacher* teacher);//显示教师信息
    void showCourse(int row,Course* course);//显示课程信息

    void filter(QTableWidget *source, QString &text);

private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonAddTeacher_clicked();

    void on_pushButtonAddCourse_clicked();

    void on_actionFileOpen_triggered();

    void on_actionFileSave_triggered();

    void on_actionFileSaveAs_triggered();

    void on_pushButtonBack_clicked();

    void on_actionSearch_triggered();

    void on_actionGenderFilter_triggered();

    void on_actionMarriageFilter_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
