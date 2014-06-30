#include<iostream>
#include<vector>
#include<string>
#include"JsonBox.h"
#include"Course.h"

using namespace std;
using namespace JsonBox;
using namespace timetable;

Course::Course()
{
	teacher="";
	courseName="";
}

Course::Course(Value& value)
{
	loadFromValue(value);
}

Course::Course(const Course& course)
{
	lectures=vector<Lecture>(course.lectures);
	teacher=string(course.teacher);
	courseName=string(course.courseName);
}

void Course::loadFromValue(Value& value)
{
	teacher=value["Teacher"].getString();
	courseName=value["CourseName"].getString();
	Array array=value["Lectures"].getArray();
	for(Array::iterator iter=array.begin(); iter!=array.end(); ++iter)
	{
		lectures.push_back(Lecture(*iter));
	}
}

vector<Lecture> Course::getLectures()
{
	return vector<Lecture>(lectures);
}

string Course::getTeacher()
{
	return string(teacher);
}

string Course::getCourseName()
{
	return string(courseName);
}
