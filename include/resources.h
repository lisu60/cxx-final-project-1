#include<string>
using std::string;

const string KCYN="\x1B[1m\x1B[36m";
const string KNRM="\x1B[0m";

const string DAY_OF_WEEK[]=
{
	"周日",
	"周一",
	"周二",
	"周三",
	"周四",
	"周五",
	"周六"
};

const string DIVIDER=
"-----------------------------------------------------------------";
const string PROMPT=">>> ";
const string TITLE="\t\t超级神奇超级厉害课表查询管理系统";
const string SELECT_OPER="请选择操作";
const string OPERATIONS[]={
	"1、列出所有课程",
	"2、查看课程详情",
	"3、添加课程",
	"0、退出"
};
const string ENTER="请输入:";
const string WRONG_ENTER="输入有误";
const string COURSE_NUMBER="请输入课程编号:";
const string NO_COURSES="当前没有课程";
const string COURSE_NAME="课程名称:";
const string COURSE_TEACHER="任课教师:";
const string COURSE_LECTURES="时间地点:";
const string COURSE_WEEKS="上课周次:";
