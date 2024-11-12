#include "teacher.h"

Teacher::Teacher()
{

}

bool Teacher::addCourse(Course *course)
{
    courseArray.append(course);
    return true;
}//添加课程

bool Teacher::removeCourse(QString courseId)
{
    for(int i=0; i<courseArray.length();i++)
    {
        if(courseArray[i]->courseId == courseId)
        {
            delete courseArray[i];
            courseArray.removeAt(i);
            return true;
        }
    }
    return false;
}//删除指定课程

void Teacher::removeAllCourse()
{
    for(int i=courseArray.length()-1;i>=0;i--)
    {
        delete courseArray[i];
        courseArray.removeAt(i);
    }
}//删除所有课程

Course *Teacher::getCourse(QString courseId)
{
    for(int i=0; i<courseArray.length();i++)
    {
        if(courseArray[i]->courseId == courseId)
        {
            return courseArray[i];
        }
    }
    return NULL;
}//查找课程




