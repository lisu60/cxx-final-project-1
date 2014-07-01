#include<JsonBox.h>
#include<vector>
#include<ClassTime.h>

using namespace JsonBox;
using std::vector;
using namespace std;

timetable::ClassTime::ClassTime()
{
	dayOfWeek=0;
}

timetable::ClassTime::ClassTime(Value& value)
{
	loadFromValue(value);
}

timetable::ClassTime::ClassTime(const ClassTime& classTime)
{
	ClassTime time;
	time.dayOfWeek=classTime.dayOfWeek;
	time.classNumber=vector<int>(classTime.classNumber);
}

void timetable::ClassTime::loadFromValue(Value& value)
{
	dayOfWeek=value["DayOfWeek"].getInt();
	Array array=value["ClassNumber"].getArray();
	for(Array::iterator iter=array.begin(); iter!=array.end(); ++iter)
	{
		classNumber.push_back(iter->getInt());
	}
}

int timetable::ClassTime::getDayOfWeek()
{
	return dayOfWeek;
}

vector<int> timetable::ClassTime::getClassNumber()
{
	return classNumber;
}
