#include<iostream>
#include"JsonBox.h"
#include"resources.h"
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
vector<Course> courses;

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
		courses.push_back(Course(*iter));
	}
	

	system(CLEAR_COMMAND);

	cout<<endl<<endl<<endl;
	cout<<DIVIDER<<endl;
	cout<<TITLE<<endl;
	SLEEP(1000);

	cout<<"There are "<<courses.size()<<" courses for present"<<endl;



	return 0;
}


