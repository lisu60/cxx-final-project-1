#ifndef CLASSTIME_H
#define CLASSTIME_H

#include"JsonBox.h"
#include<vector>

using namespace JsonBox;
using std::vector;

namespace timetable
{
	class ClassTime
	{
			public:
					ClassTime();
					ClassTime(Value&);
					ClassTime(const ClassTime&);

					void loadFromValue(Value&);

					int getDayOfWeek();
					vector<int> getClassNumber();
			private:
					int dayOfWeek;
					vector<int> classNumber;

	};
}

#endif
