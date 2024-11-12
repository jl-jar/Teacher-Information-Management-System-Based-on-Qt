#ifndef TEACHER_H
#define TEACHER_H

#include "course.h"

#include <QDataStream>
#include <QDate>
#include <QString>

class Teacher
{
public:
    Teacher();
    int id;//教师编号
    QString name;//姓名
    bool gender;//性别
    QDate birthDate;//生日
    QString jobTitle;//职称
    QString highestDegree;//最后学历
    QString monthSalary;//月薪
    bool marriage;//婚否

    QList<Course*> courseArray;//授课信息集合

    bool addCourse(Course* course);//增加操作
    bool removeCourse(QString courseId);//删除指定课程操作
    void removeAllCourse();//删除所有课程操作
    Course* getCourse(QString courseId);//查找操作

    friend QDataStream& operator<<(QDataStream&ds,Teacher& teacher) //用二进制将数据写入文件
    {
        ds<<teacher.id;
        ds<<teacher.name;
        ds<<teacher.gender;
        ds<<teacher.birthDate;
        ds<<teacher.jobTitle;
        ds<<teacher.highestDegree;
        ds<<teacher.monthSalary;
        ds<<teacher.marriage;
        int length = teacher.courseArray.length();
        ds<<length;
        for(int i=0;i<length;i++)
            ds<<*teacher.courseArray[i];
        return ds;
    }

    friend QDataStream& operator>>(QDataStream&ds,Teacher& teacher) //用二进制从文件中读取数据
    {
        ds>>teacher.id;
        ds>>teacher.name;
        ds>>teacher.gender;
        ds>>teacher.birthDate;
        ds>>teacher.jobTitle;
        ds>>teacher.highestDegree;
        ds>>teacher.monthSalary;
        ds>>teacher.marriage;
        int length;
        ds>>length;
        for(int i=0;i<length;i++)
        {
            Course* course = new Course;
            ds>>*course;
            teacher.courseArray.append(course);
        }
        return ds;
     }
};

#endif // TEACHER_H
