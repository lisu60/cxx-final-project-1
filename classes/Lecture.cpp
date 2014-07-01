#include<JsonBox.h>
#include<string>
#include<vector>
#include"Lecture.h"
#include"ClassTime.h"
using namespace std;
using namespace JsonBox;

timetable::Lecture::Lecture()
{
	location=new string("");
}

timetable::Lecture::Lecture(Value& value)
{
	loadFromValue(value);
}


timetable::Lecture::~Lecture()
{
	cout<<"Lecture on destroy"<<endl;
	delete location;
	delete weekNumber;
	delete classTime;
}

void timetable::Lecture::loadFromValue(Value& value)
{
	location=new string(value["Location"].getString());
	classTime=new ClassTime(value["ClassTime"]);
	Array array=value["WeekNumber"].getArray();
	weekNumber=new vector<int>();
	for(Array::iterator iter=array.begin(); iter!=array.end(); ++iter)
	{
		weekNumber->push_back(iter->getInt());
	}
}

string* timetable::Lecture::getLocation()
{
	return location;
}

vector<int>* timetable::Lecture::getWeekNumber()
{
	return weekNumber;
}


timetable::ClassTime* timetable::Lecture::getClassTime()
{
	return classTime;
}
