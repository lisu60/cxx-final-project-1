#include<iostream>
#include<stdio.h>
#include"JsonBox.h"
#include"resources.h"
#include"platform_resources.h"
#include"system_specified_headers.h"
#include"Course.h"

using namespace JsonBox;
using namespace timetable;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

Value value;
vector<Course*> courses;


void listAll();
void listDetail();
void addCourse();


int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		cout<<"Usage: timetable <path>"<<endl;
		return 0;
	}
	value.loadFromFile(argv[1]);
	
	Array array=value.getArray();
	for(Array::iterator iter=array.begin(); iter!=array.end(); ++iter)
	{
		courses.push_back(new Course(*iter));
	}
	

	system(CLEAR_COMMAND);

	cout<<endl<<endl<<endl;
	cout<<DIVIDER<<endl;
	cout<<TITLE<<endl;
	SLEEP(1000);

	while(1)
	{
		cout<<endl<<endl<<endl;
		cout<<"当前有"<<courses.size()<<"门课"<<endl;
		cout<<SELECT_OPER<<endl;
		for(int i=0; i<4; i++)
		{
			cout<<OPERATIONS[i]<<endl;
		}
		cout<<ENTER<<endl;
		cout<<PROMPT;
		int selection;
		cin>>selection;
		switch(selection)
		{
				case 0:
						return 0;
				case 1:
						listAll();
						break;
				case 2:
						listDetail();
						break;
				case 3:
						addCourse();
						break;
				default:
						cout<<WRONG_ENTER;
						break;


		}

	}

	return 0;
}

void listAll()
{
	int i=0;
	cout<<endl;
	for(vector<Course*>::iterator iter=courses.begin(); iter!=courses.end(); ++iter, ++i)
	{
		Course* pcour=*iter;
		cout<<i<<"、"<<*(pcour->getCourseName())<<'\t'<<*(pcour->getTeacher())<<endl;
	}
}

void listDetail()
{
	listAll();
	if(courses.size()==0)
	{
		cout<<NO_COURSES<<endl;
		return;
	}
	cout<<endl;
	int selection;
	while(1)
	{
		cout<<COURSE_NUMBER<<endl;
		cout<<PROMPT;
		cin>>selection;
		if(selection>=0 && selection<courses.size())
			break;
		else
			cout<<WRONG_ENTER<<endl<<endl;
	}

	Course* pcour=courses[selection];
	cout<<COURSE_NAME<<*pcour->getCourseName()<<endl;
	cout<<COURSE_TEACHER<<*pcour->getTeacher()<<endl;
	cout<<COURSE_LECTURES<<endl;
	vector<Lecture*>* lecs=pcour->getLectures();
	vector<Lecture*>::iterator iter=lecs->begin();
	for(iter=lecs->begin(); iter!=lecs->end(); ++iter)
	{
		ClassTime* classTime=(*iter)->getClassTime();
		cout<<'\t'<<*(*iter)->getLocation()<<endl;
		cout<<'\t'<<DAY_OF_WEEK[classTime->getDayOfWeek()]<<'\t';
		int i;
		for(i=0; i<classTime->getClassNumber()->size()-1; i++)
		{
			cout<<classTime->getClassNumber()->at(i)<<", ";
		}
		cout<<classTime->getClassNumber()->at(i)<<"节"<<endl;
	}


}


void addCourse()
{}

