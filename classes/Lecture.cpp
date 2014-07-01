#include<JsonBox.h>
#include<string>
#include<vector>
#include"Lecture.h"
#include"ClassTime.h"
using namespace std;
using namespace JsonBox;

timetable::Lecture::Lecture()
{
	location="";
}

timetable::Lecture::Lecture(Value& value)
{
	loadFromValue(value);
}

timetable::Lecture::Lecture(const Lecture& lec)
{
	location=string(lec.location);
	weekNumber=vector<int>(lec.weekNumber);
	classTime=timetable::ClassTime(lec.classTime);
}

void timetable::Lecture::loadFromValue(Value& value)
{
	location=value["Location"].getString();
	classTime=ClassTime(value["ClassTime"]);
	Array array=value["WeekNumber"].getArray();
	for(Array::iterator iter=array.begin(); iter!=array.end(); ++iter)
	{
		weekNumber.push_back(iter->getInt());
	}
}

string timetable::Lecture::getLocation()
{
	return location;
}

vector<int> timetable::Lecture::getWeekNumber()
{
	return weekNumber;
}


timetable::ClassTime timetable::Lecture::getClassTime()
{
	return classTime;
}
