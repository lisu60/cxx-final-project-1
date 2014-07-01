#ifndef LECTURE_H
#define LECTURE_H

#include"JsonBox.h"
#include"ClassTime.h"
#include<string>
#include<vector>
using std::string;
using std::vector;
using namespace JsonBox;


namespace timetable
{
	class Lecture
	{
			public:
					Lecture();
					Lecture(Value&);
					~Lecture();

					void loadFromValue(Value&);

					string* getLocation();
					vector<int>* getWeekNumber();
					ClassTime* getClassTime();

			private:
					string* location;
					vector<int>* weekNumber;
					ClassTime* classTime;
	};
}

#endif
