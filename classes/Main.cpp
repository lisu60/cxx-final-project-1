#include<iostream>
#include<stdio.h>
#include<fstream>
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

char* filePath;

void listAll();
void listDetail();
void addCourse();
void deleteCourse();


int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		cout<<"Usage: timetable <path>"<<endl;
		return 0;
	}
	filePath=argv[1];
	value.loadFromFile(filePath);
	
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
		for(int i=0; i<5; i++)
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
				case 4:
						deleteCourse();
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
	for(vector<Lecture*>::iterator iter=lecs->begin(); iter!=lecs->end(); ++iter)
	{
		ClassTime* classTime=(*iter)->getClassTime();
		cout<<'\t'<<*(*iter)->getLocation()<<endl;
		cout<<'\t'<<DAY_OF_WEEK[classTime->getDayOfWeek()]<<'\t';

		int i;
		for(i=0; i<classTime->getClassNumber()->size()-1; i++)
		{
			cout<<classTime->getClassNumber()->at(i)<<", ";
		}
		cout<<classTime->getClassNumber()->at(i)<<"节"<<'\t';
		
		vector<int>* weeks=(*iter)->getWeekNumber();
		vector<int>::iterator iterw=weeks->begin();
		int begin=*iterw, last=begin-1, curr;
		while(1)
		{
			if(iterw==weeks->end())
			{
				if(begin==curr)
				{
					cout<<curr;
				}
				else
				{
					cout<<begin<<"-"<<curr;
				}
				cout<<" 周"<<endl;
				break;
			}
			else
			{
				curr=*iterw;
				if(curr-last!=1)
				{
					if(last==begin)
					{
						cout<<last<<", ";
					}
					else
					{
						cout<<begin<<"-"<<last<<", ";
					}
					begin=curr;
				}
				last=curr;
			}
			++iterw;
		}

	}


}


void addCourse()
{
	Value cour;
	string str;
	int integer;



	cout<<ENTER_COURSE_NAME<<endl;
	cout<<PROMPT;
	cin.clear();
	cin>>str;
	cour["CourseName"]=str;
	cout<<ENTER_TEACHER_NAME<<endl;
	cout<<PROMPT;
	cin.clear();
	cin>>str;
	cour["Teacher"]=str;

	char choice='\0';
	int i=0;
	while(choice!='n')
	{
		cout<<WHETHER_ADD_LECTURE<<endl;
		cout<<PROMPT;
		cin.clear();
		cin>>choice;
		switch(choice)
		{
				case 'y':
						cout<<ENTER_LOCATION<<endl;
						cout<<PROMPT;
						cin.clear();
						cin>>str;
						cour["Lectures"][size_t(i)]["Location"]=str;
						cout<<ENTER_DAY_OF_WEEK<<endl;
						cout<<PROMPT;
						cin.clear();
						cin>>integer;
						cour["Lectures"][size_t(i)]["ClassTime"]["DayOfWeek"]=integer;
						cout<<ENTER_CLASS_NUMBER<<endl;
						cout<<PROMPT;
						cin.clear();
						for(int j=0; cin>>integer; j++)
						{
							cour["Lectures"][size_t(i)]["ClassTime"]["ClassNumber"][size_t(j)]=integer;
						}
						cout<<ENTER_WEEK_NUMBER<<endl;
						cout<<PROMPT;
						cin.clear();
						for(int j=0; cin>>integer; j++)
						{
							cour["Lectures"][size_t(i)]["WeekNumber"][size_t(j)]=integer;
						}
						i++;
						break;
				case 'n':
						break;
				default: cout<<WRONG_ENTER<<endl;

		}
		
	}
	value[size_t(value.getArray().size())]=cour;
	ofstream file;
	file.open(filePath);
	file<<value<<endl;
	file.close();

	value.loadFromFile(filePath);
	Array array=value.getArray();
	courses.clear();
	for(Array::iterator iter=array.begin(); iter!=array.end(); ++iter)
	{
		courses.push_back(new Course(*iter));
	}

}

void deleteCourse()
{
	listAll();
	cout<<ENTER_COURSE_TO_DELETE<<endl;
	cout<<PROMPT;
	int choice;
	cin>>choice;
	if(choice>=0 && value.getArray().size())
	{
		Array array=value.getArray();
		Array::iterator iter=array.begin();
		array.erase(iter+choice);
		value=Value(array);
	}
	ofstream file;
	file.open(filePath);
	file<<value<<endl;
	file.close();

	value.loadFromFile(filePath);
	Array array=value.getArray();
	courses.clear();
	for(Array::iterator iter=array.begin(); iter!=array.end(); ++iter)
	{
		courses.push_back(new Course(*iter));
	}
}

