#ifndef COURSE_H
#define COURSE_H

#include<iostream>
#include<vector>
#include<string>
#include"JsonBox.h"
#include"Lecture.h"

using namespace std;
using namespace JsonBox;

namespace timetable
{
	class Course
	{
			public:
					Course();
					Course(Value&);
					Course(const Course&);

					void loadFromValue(Value&);

					vector<Lecture> getLectures();
					string getTeacher();
					string getCourseName();
			private:
					vector<Lecture> lectures;
					string teacher;
					string courseName;
	};
}

#endif
