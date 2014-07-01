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
	teacher=new string("");
	courseName=new string("");
}

Course::Course(Value& value)
{
	loadFromValue(value);
}


Course::~Course()
{
	cout<<"Course on destroy"<<endl;
	delete lectures;
	delete teacher;
	delete courseName;
}

void Course::loadFromValue(Value& value)
{
	teacher=new string(value["Teacher"].getString());
	courseName=new string(value["CourseName"].getString());
	Array array=value["Lectures"].getArray();
	lectures=new vector<Lecture*>();
	for(Array::iterator iter=array.begin(); iter!=array.end(); ++iter)
	{
		lectures->push_back(new Lecture(*iter));
	}
}

vector<Lecture*>* Course::getLectures()
{
	return lectures;
}

string* Course::getTeacher()
{
	return teacher;
}

string* Course::getCourseName()
{
	return courseName;
}
