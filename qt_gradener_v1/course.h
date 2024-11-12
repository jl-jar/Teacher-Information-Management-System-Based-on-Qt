#ifndef COURSE_H
#define COURSE_H

#include <QDataStream>
#include <QString>

class Course
{
public:
    Course();
    QString courseId;//课程编号
    QString courseName;//课程名称
    QString courseHour;//课时
    QString classroom;//教室
    QString TeachingClass;//班级
    QString credit;//学分
    QString semester;//学期

    friend QDataStream &operator<<(QDataStream& ds,Course& course) //用二进制将数据写入文件//对<<运算符重载
    {
        ds<<course.courseId;
        ds<<course.courseName;
        ds<<course.courseHour;
        ds<<course.credit;
        ds<<course.TeachingClass;
        ds<<course.classroom;
        ds<<course.semester;
        return ds;
    }

    friend QDataStream &operator>>(QDataStream& ds,Course& course) //用二进制从文件读取数据//对>>运算符重载
    {
        ds>>course.courseId;
        ds>>course.courseName;
        ds>>course.courseHour;
        ds>>course.credit;
        ds>>course.TeachingClass;
        ds>>course.classroom;
        ds>>course.semester;
        return ds;
    }

};

#endif // COURSE_H
