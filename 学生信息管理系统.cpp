#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<Windows.h>
#include<limits>
#include<fstream>
#undef max
#pragma warning (disable:4996)
using namespace std;
class abstract//抽象类
{
public:
	virtual void print() = 0;
};
class time :virtual abstract
{
public:
	time(int a, int b, int c);
	~time();
	int Getyear();
	int Getmonth();
	int Getdate();
	char* Getsemester();
	void Setyear(int a);
	void Setmonth(int a);
	void Setdate(int a);
	void reflect();
	virtual void print();
protected:
	int year;
	int month;
	int date;
	char semester[9];
};
time::time(int a, int b, int c) : year(a), month(b), date(c)
{
	reflect();
}
time::~time()
{
}
int time::Getyear()
{
	return year;
}
int time::Getmonth()
{
	return month;
}
int time::Getdate()
{
	return date;
}
char* time::Getsemester()
{
	return semester;
}
void time::Setyear(int a)
{
	year = a;
}
void time::Setmonth(int a)
{
	month = a;
	reflect();
}
void time::Setdate(int a)
{
	date = a;
}
void time::reflect()//根据日期自动对应学期
{
	if (month >= 3 && month <= 6)
		strcpy(semester, "春季学期");
	else if (month >= 7 && month <= 8)
		strcpy(semester, "夏季学期");
	else if ((month >= 9 && month <= 12) || (month == 1))
		strcpy(semester, "秋季学期");
	else
		strcpy(semester, "其他学期");
}
void time::print()
{
	cout << year << "-" << month << "-" << date << " (" << semester << ")  ";
}
class student :virtual public abstract
{
public:
	student(char*a, char* b, char* c, char* d);
	~student();
	char* Getstudentname();
	char* Getstudentnumber();
	char* Getstudentclass();
	char* Getstudentgrade();
	void Setstudentname(char* a);
	void Setstudentnumber(char* a);
	void Setstudentclass(char* a);
	void Setstudentgrade(char* a);
	void print();
protected:
	char* studentname;
	char* studentnumber;
	char* studentclass;
	char* studentgrade;
};
student::student(char*a, char*b, char*c, char* d)
{
	studentname = new char[strlen(a) + 1];
	strcpy(studentname, a);
	studentnumber = new char[strlen(b) + 1];
	strcpy(studentnumber, b);
	studentclass = new char[strlen(c) + 1];
	strcpy(studentclass, c);
	studentgrade = new char[strlen(d) + 1];
	strcpy(studentgrade, d);
}
student::~student()
{
	delete[] studentname;
	delete[] studentnumber;
	delete[] studentclass;
	delete[] studentgrade;
}
char* student::Getstudentname()
{
	return studentname;
}
char* student::Getstudentnumber()
{
	return studentnumber;
}
char* student::Getstudentclass()
{
	return studentclass;
}
char* student::Getstudentgrade()
{
	return studentgrade;
}
void student::Setstudentname(char* a)
{
	delete[] studentname;
	studentname = new char[strlen(a) + 1];
	strcpy(studentname, a);
}
void student::Setstudentnumber(char* a)
{
	delete[] studentnumber;
	studentnumber = new char[strlen(a) + 1];
	strcpy(studentnumber, a);
}
void student::Setstudentclass(char* a)
{
	delete[] studentclass;
	studentclass = new char[strlen(a) + 1];
	strcpy(studentclass, a);
}
void student::Setstudentgrade(char* a)
{
	delete[] studentgrade;
	studentgrade = new char[strlen(a) + 1];
	strcpy(studentgrade, a);
}
void student::print()
{
	cout << studentname << "  ";
	cout << studentnumber << "  ";
	cout << studentclass << "  ";
	cout << studentgrade << "  ";
}
class record_grade :virtual public abstract, public student
{
public:
	record_grade(char* a, char* b, char* c,char*d, char*a1, int b1, int c1);
	~record_grade();
	char* Getclassname();
	int Getclassmark();
	int Getmark();
	char* Getgrade();
	double Getpoint();
	void Setclassname(char* a);
	void Setclassmark(int a);
	void Setmark(int a);
	void reflect();
	virtual void print();
	double operator+(double a);
	int operator+(int a);
protected:
	char* classname;
	int classmark;
	int mark;
	char grade[3];
	double point;
};
record_grade::record_grade(char* a, char* b, char* c, char*d, char*a1, int b1, int c1) :student(a, b, c, d), classmark(b1), mark(c1)
{
	classname = new char[strlen(a1) + 1];
	strcpy(classname, a1);
	reflect();
}
record_grade::~record_grade()
{
	delete[] classname;
}
char* record_grade::Getclassname()
{
	return classname;
}
int record_grade::Getclassmark()
{
	return classmark;
}
int record_grade::Getmark()
{
	return mark;
}
char* record_grade::Getgrade()
{
	return grade;
}
double record_grade::Getpoint()
{
	return point;
}
void record_grade::Setclassname(char* a)
{
	delete[] classname;
	classname = new char[strlen(a) + 1];
	strcpy(classname, a);
}
void record_grade::Setclassmark(int a)
{
	classmark = a;
}
void record_grade::Setmark(int a)
{
	mark = a;
	reflect();
}
void record_grade::reflect()//根据百分制成绩对应绩点
{
	if (mark >= 99) { point = 4.0; strcpy(grade, "A+"); }
	else if (mark >= 95) { point = 4.0; strcpy(grade, "A "); }
	else if (mark >= 90) { point = 4.0; strcpy(grade, "A-"); }
	else if (mark >= 85) { point = 3.6; strcpy(grade, "B+"); }
	else if (mark >= 80) { point = 3.3; strcpy(grade, "B "); }
	else if (mark >= 77) { point = 3.0; strcpy(grade, "B-"); }
	else if (mark >= 73) { point = 2.6; strcpy(grade, "C+"); }
	else if (mark >= 70) { point = 2.3; strcpy(grade, "C "); }
	else if (mark >= 67) { point = 2.0; strcpy(grade, "C-"); }
	else if (mark >= 63) { point = 1.6; strcpy(grade, "D+"); }
	else if (mark >= 60) { point = 1.3; strcpy(grade, "D "); }
	else { point = 0; strcpy(grade, "F "); }
}
void record_grade::print()
{
	student::print();
	cout << classname << "(" << classmark << "学分)  ";
	cout << "百分制成绩:" << mark << "  ";
	cout << "等级制成绩:" << grade << "  ";
	cout << setiosflags(ios_base::fixed) << setprecision(1) << point << resetiosflags(ios_base::fixed);
	cout << endl;
}
double record_grade::operator+(double a)//两个+重载用于计算平均学分绩
{
	return this->classmark*this->point + a;
}
int record_grade::operator+(int a)
{
	return this->classmark + a;
}
class record_absent :virtual public abstract, public time, public student
{
public:
	record_absent(int a, int b, int c, char* a1, char* b1, char* c1, char*d1, int a2, char* c2,char* d2);
	~record_absent();
	int Getday();
	int Getclassnumber();
	char* Getclassname();
	char* Getform();
	void reflect_day();
	void Setclassnumber(int a);
	void Setclassname(char* a);
	void Setform(char* a);
	virtual void print();
protected:
	int day;
	int classnumber;
	char* classname;
	char form[5];
};
record_absent::record_absent(int a, int b, int c, char* a1, char* b1, char* c1, char*d1, int a2, char* c2, char* d2) :time(a, b, c), student(a1, b1, c1, d1), classnumber(a2)
{
	classname = new char[strlen(c2) + 1];
	strcpy(classname, c2);
	strcpy(form, d2);
	reflect_day();
}
record_absent::~record_absent()
{
	delete[] classname;
}
int record_absent::Getday()
{
	return day;
}
int record_absent::Getclassnumber()
{
	return classnumber;
}
char* record_absent::Getform()
{
	return form;
}
char* record_absent::Getclassname()
{
	return classname;
}
void record_absent::reflect_day()//根据日期自动对应星期
{
	int i, count = 0, t = 28;
	for (i = 1900; i < year; i++)
	{
		if (!(i % 4) && ((i % 100) || !(i % 400)))
			count = count + 366;
		else
			count = count + 365;
	}
	if (!(year % 4) && ((year % 100) || !(year % 400)))
		t = 29;
	for (i = 1; i < month; i++)
	{
		switch (i)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:count = count + 31; break;
		case 4:case 6:case 9:case 11:count = count + 30; break;
		case 2:count = count + t; break;
		}
	}
	count = count + date;
	day = count % 7;
	if (day == 0)
		day = 7;
}
void record_absent::Setclassnumber(int a)
{
	classnumber = a;
}
void record_absent::Setform(char* a)
{
	strcpy(form, a);
}
void record_absent::Setclassname(char* a)
{
	delete[] classname;
	classname = new char[strlen(a) + 1];
	strcpy(classname, a);
}
void record_absent::print()
{
	time::print();
	student::print();
	cout << classname;
	cout << " (" << day << "-" << classnumber << ")  ";
	cout << form;
	cout << endl;
}
//两种节点分别储存两类数据
struct grade
{
	record_grade data;
	grade* next;
};
struct absent
{
	record_absent data;
	absent* next;
};
grade* Grade;
absent* Absent;
//链表操作函数
template <typename T>
void list_insert(T*&head, T*&p)
{
	if (head == NULL)
	{
		head = p;
		p->next = NULL;
	}
	else
	{
		T* helper = head;
		while (helper->next != NULL)
			helper = helper->next;
		helper->next = p;
		p->next = NULL;
	}
}
template <typename T>
void list_delete(T*&head, T*&p)
{
	if (p == head)
	{
		head = p->next;
		delete p;
	}
	else
	{
		T* helper = head;
		while (helper->next != p)
			helper = helper->next;
		helper->next = helper->next->next;
		delete p;
	}
}
//判断日期是否合法
bool judge_date(int a, int b, int c)
{
	int t = 28;
	bool mark = 0;
	if (a < 1900 || b <= 0 || c <= 0)
		mark = 1;
	else
	{
		if (!(a % 4) && ((a % 100) || !(a % 400)))
			t = 29;
		switch (b)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:if (c <= 0 || c > 31) mark = 1; break;
		case 4:case 6:case 9:case 11:if (c <= 0 || c > 30) mark = 1; break;
		case 2:if (c <= 0 || c > t) mark = 1; break;
		default:mark = 1;
		}
	}
	if (mark)cout << "输入日期不合法，请重新输入(年 月 日)" << endl;
	return mark;
}
void input_date(int &a, int &b, int &c)
{
	cout << "(年 月 日)" << endl;
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	do
	{
		cin >> a;
		if (cin.fail())
		{
			a = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			while (cin.peek() == ' ')
				getchar();
		}
		cin >> b;
		if (cin.fail())
		{
			b = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			while (cin.peek() == ' ')
				getchar();
		}
		cin >> c;
		if (cin.fail())
		{
			c = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (judge_date(a, b, c));
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
}
//输入学号并判断是否合乎学号形式
void input_studentnumber(char* a)
{
	int p = 0;
	char target[21];
	cout << "请输入学号" << endl;
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	cin.getline(target, 21, '\n');
	while (true)
	{
		bool numbersign = false;
		while (target[p] != '\0')
		{
			if (target[p] > '9' || target[p] < '0')
			{
				numbersign = true;
				break;
			}
			p++;
		}
		if (numbersign == true)
		{
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cout << "请输入正确的学号(纯数字)" << endl;
			cin.getline(target, 21, '\n');
			p = 0;
		}
		if (numbersign == false)
			break;
	}
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	strcpy(a, target);
}
//根据不同关键字的搜索函数
template<typename T>
T* list_search_studentname(T*start, bool mark)
{
	static char target[51];
	if (mark);
	else
	{
		cout << "请输入学生姓名" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getstudentname(), target) != 0)
		helper = helper->next;
	return helper;
}
template<typename T>
T* list_search_studentnumber(T*start, bool mark)
{
	static char target[21];
	if (mark);
	else
		input_studentnumber(target);
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getstudentnumber(), target) != 0)
		helper = helper->next;
	return helper;
}
template<typename T>
T* list_search_studentclass(T*start, bool mark)
{
	static char target[21];
	if (mark);
	else
	{
		cout << "请输入学生班级" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 21, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getstudentclass(), target) != 0)
		helper = helper->next;
	return helper;
}
template<typename T>
T* list_search_studentgrade(T*start, bool mark)
{
	static char target[21];
	if (mark);
	else
	{
		cout << "请输入学生年级" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 21, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getstudentgrade(), target) != 0)
		helper = helper->next;
	return helper;
}
template<typename T>
T* list_search_classname(T*start, bool mark)
{
	static char target[51];
	if (mark);
	else
	{
		cout << "请输入课程名" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	T* helper = start;
	while (helper != NULL && strcmp(helper->data.Getclassname(), target))
		helper = helper->next;
	return helper;
}
absent* list_search_absentform(absent* start, bool mark)
{
	static char target[5];
	if (mark);
	else
	{
		cout << "请输入类型" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 5, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		while (strcmp(target, "正常") && strcmp(target, "迟到") && strcmp(target, "早退") && strcmp(target, "请假") && strcmp(target, "缺课"))
		{
			cout << "请输入正确的类型(正常/迟到/早退/请假/缺课)" << endl;
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cin.getline(target, 5, '\n');
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
	}
	absent* helper = start;
	while (helper != NULL && strcmp(helper->data.Getform(), target))
		helper = helper->next;
	return helper;
}
absent* list_search_absenttime(absent* start, bool mark)
{
	static int a, b, c;
	if (mark);
	else
	{
		cout << "请输入日期" << endl;
		input_date(a, b, c);
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != a || helper->data.Getmonth() != b || helper->data.Getdate() != c))
		helper = helper->next;
	return helper;
}
absent* list_search_absentsemester(absent* start, bool mark)
{
	static char target[9];
	if (mark);
	else
	{
		cout << "请输入学期" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 9, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		while (strcmp(target, "春季学期") && strcmp(target, "夏季学期") && strcmp(target, "秋季学期") && strcmp(target, "其他学期"))
		{
			cout << "请输入正确的学期(春季学期/夏季学期/秋季学期/其他学期)" << endl;
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cin.getline(target, 9, '\n');
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
	}
	absent* helper = start;
	while (helper != NULL && strcmp(helper->data.Getsemester(), target))
		helper = helper->next;
	return helper;
}
absent * list_search_student_withtime1(absent*start, bool mark)
{
	static int year;
	static char target[51];
	if (mark);
	else
	{
		input_studentnumber(target);
		cout << "请输入年份" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		while (cin.fail() || year < 1900)
		{
			cout << "请输入正确的年份" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> year;
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || strcmp(helper->data.Getstudentnumber(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_student_withtime2(absent*start, bool mark)
{
	static int year, month;
	static char target[51];
	if (mark);
	else
	{
		input_studentnumber(target);
		cout << "请输入时间" << endl;
		cout << "(年 月)" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		if (cin.fail() || year < 1900)
		{
			year = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			while (cin.peek() == ' ')
				getchar();
		}
		cin >> month;
		if (cin.fail() || month < 0 || month>12)
		{
			month = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		if (year == -1)
		{
			cout << "请输入正确的年份" << endl;
			cin >> year;
			while (cin.fail() || year < 0)
			{
				cout << "请输入正确年份" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> year;
			}
		}
		if (month == -1)
		{
			cout << "请输入正确的月份" << endl;
			cin >> month;
			while (cin.fail() || month < 0 || month>100)
			{
				cout << "请输入正确的月份" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> month;
			}
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || helper->data.Getmonth() != month || strcmp(helper->data.Getstudentnumber(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_student_withtime3(absent*start, bool mark)
{
	static int year, month, day;
	static char target[51];
	if (mark);
	else
	{
		input_studentnumber(target);
		cout << "请输入日期" << endl;
		input_date(year, month, day);
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || helper->data.Getmonth() != month || helper->data.Getdate() != day || strcmp(helper->data.Getstudentnumber(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_student_withtime4(absent*start, bool mark)
{
	static int year;
	static char semester[9], target[51];
	if (mark);
	else
	{
		input_studentnumber(target);
		cout << "请输入年份" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		while (cin.fail() || year < 1900)
		{
			cout << "请输入正确的年份" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> year;
		}
		cout << "请输入学期" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(semester, 9, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		while (strcmp(semester, "春季学期") && strcmp(semester, "夏季学期") && strcmp(semester, "秋季学期") && strcmp(semester, "其他学期"))
		{
			cout << "请输入正确的学期(春季学期/夏季学期/秋季学期/其他学期)" << endl;
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cin.getline(semester, 9, '\n');
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || strcmp(helper->data.Getstudentnumber(), target) || strcmp(helper->data.Getsemester(), semester)))
		helper = helper->next;
	return helper;
}
absent * list_search_class_withtime1(absent*start, bool mark)
{
	static int year;
	static char target[51];
	if (mark);
	else
	{
		cout << "请输入课程名" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cout << "请输入年份" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		while (cin.fail() || year < 1900)
		{
			cout << "请输入正确的年份" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> year;
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || strcmp(helper->data.Getclassname(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_class_withtime2(absent*start, bool mark)
{
	static int year, month;
	static char target[51];
	if (mark);
	else
	{
		cout << "请输入课程名" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cout << "请输入时间" << endl;
		cout << "(年 月)" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		if (cin.fail() || year < 1900)
		{
			year = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			while (cin.peek() == ' ')
				getchar();
		}
		cin >> month;
		if (cin.fail() || month < 0 || month>12)
		{
			month = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		if (year == -1)
		{
			cout << "请输入正确的年份" << endl;
			cin >> year;
			while (cin.fail() || year < 0)
			{
				cout << "请输入正确年份" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> year;
			}
		}
		if (month == -1)
		{
			cout << "请输入正确的月份" << endl;
			cin >> month;
			while (cin.fail() || month < 0 || month>100)
			{
				cout << "请输入正确的月份" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> month;
			}
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || helper->data.Getmonth() != month || strcmp(helper->data.Getclassname(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_class_withtime3(absent*start, bool mark)
{
	static int year, month, day;
	static char target[51];
	if (mark);
	else
	{
		cout << "请输入课程名" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cout << "请输入日期" << endl;
		input_date(year, month, day);
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || helper->data.Getmonth() != month || helper->data.Getdate() != day || strcmp(helper->data.Getclassname(), target)))
		helper = helper->next;
	return helper;
}
absent* list_search_class_withtime4(absent*start, bool mark)
{
	static int year;
	static char semester[9], target[51];
	if (mark);
	else
	{
		cout << "请输入课程名" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(target, 51, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cout << "请输入年份" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> year;
		while (cin.fail() || year < 1900)
		{
			cout << "请输入正确的年份" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> year;
		}
		cout << "请输入学期" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(semester, 9, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		while (strcmp(semester, "春季学期") && strcmp(semester, "夏季学期") && strcmp(semester, "秋季学期") && strcmp(semester, "其他学期"))
		{
			cout << "请输入正确的学期(春季学期/夏季学期/秋季学期/其他学期)" << endl;
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			cin.getline(semester, 9, '\n');
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
	}
	absent* helper = start;
	while (helper != NULL && (helper->data.Getyear() != year || strcmp(helper->data.Getclassname(), target) || strcmp(helper->data.Getsemester(), semester)))
		helper = helper->next;
	return helper;
}
//函数指针数组便于调用函数
template <typename P>
P*(*f[5])(P*, bool) = { list_search_classname,list_search_studentclass,list_search_studentgrade,list_search_studentname,list_search_studentnumber };
absent*(*h1[4])(absent*, bool) = { list_search_student_withtime1,list_search_student_withtime2, list_search_student_withtime3, list_search_student_withtime4 };
absent*(*h2[4])(absent*, bool) = { list_search_class_withtime1,list_search_class_withtime2, list_search_class_withtime3, list_search_class_withtime4 };
absent*(*g[3])(absent*, bool) = { list_search_absentform,list_search_absentsemester,list_search_absenttime };
template <typename P, typename T>
void search_makesure(P*(*f)(P*, bool), T* &helper)
{
	char k;
	bool a = false, b = false, mark = false;
	while (true)
	{
		helper = f(helper, mark);
		while (true)
		{
			system("cls");
			if (helper == NULL)
			{
				cout << "无相关记录!" << endl;
				a = true; b = true;
				Sleep(700);
			}
			else
			{
				helper->data.print();
				cout << "────────────────────────────────────────────────────────────────" << endl;
				cout << "     [1] 操作该条记录          [0]查找下一条记录" << endl;
				while (cin.peek() == '\n')
					getchar();
				k = getchar();
				while (cin.rdbuf()->in_avail())
					getchar();
				cin.clear();
				switch (k)
				{
				case '1':a = true; b = true; break;
				case '0':a = true; mark = true; helper = helper->next; break;
				default:
					cout << "所选择功能不存在，请重新输入" << endl;
					Sleep(700); break;
				}
				if (a == true)
					break;
			}
			if (a == true)
				break;
		}
		if (b == true)
			break;
	}
}
grade* searchmenu_grade()
{
	char a;
	bool sign = false;
	grade* helper = Grade;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│            查找成绩记录            │" << endl;
		cout << "│         ——选择关键字——         │" << endl;
		cout << "│                                    │" << endl;
		cout << "│            [1]学生姓名             │" << endl;
		cout << "│            [2]学号                 │" << endl;
		cout << "│            [3]学生班级             │" << endl;
		cout << "│            [4]学生年级             │" << endl;
		cout << "│            [5]课程名               │" << endl;
		cout << "│                                    │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':search_makesure(f<grade>[3], helper); sign = true; break;
		case '2':search_makesure(f<grade>[4], helper); sign = true; break;
		case '3':search_makesure(f<grade>[1], helper); sign = true; break;
		case '4':search_makesure(f<grade>[2], helper); sign = true; break;
		case '5':search_makesure(f<grade>[0], helper); sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
	return helper;
}
absent* searchmenu_absent()
{
	char a;
	bool sign = false;
	absent* helper = Absent;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│            查找考勤记录            │" << endl;
		cout << "│         ——选择关键字——         │" << endl;
		cout << "│                                    │" << endl;
		cout << "│            [1]学生姓名             │" << endl;
		cout << "│            [2]学号                 │" << endl;
		cout << "│            [3]学生班级             │" << endl;
		cout << "│            [4]学生年级             │" << endl;
		cout << "│            [5]课程名               │" << endl;
		cout << "│            [6]时间                 │" << endl;
		cout << "│            [7]学期                 │" << endl;
		cout << "│            [8]类型                 │" << endl;
		cout << "│                                    │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':search_makesure(f<absent>[3], helper); sign = true; break;
		case '2':search_makesure(f<absent>[4], helper); sign = true; break;
		case '3':search_makesure(f<absent>[1], helper); sign = true; break;
		case '4':search_makesure(f<absent>[2], helper); sign = true; break;
		case '5':search_makesure(f<absent>[0], helper); sign = true; break;
		case '6':search_makesure(g[2], helper); sign = true; break;
		case '7':search_makesure(g[1], helper); sign = true; break;
		case '8':search_makesure(g[0], helper); sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
	return helper;
}
//判断新增数据是否与已有数据冲突
bool judge_studentnumber(char *a, char *b, grade* temp1, absent* temp2)
{
	bool mark1 = false;
	grade* helper11 = Grade;
	while (helper11 != NULL)
	{
		if (helper11 == temp1);
		else
		{
			if (!strcmp(helper11->data.Getstudentnumber(), b))
				if (strcmp(helper11->data.Getstudentname(), a))
				{
					cout << "信息与已有记录冲突(不同姓名共享学号)" << endl;
					cout << "操作无效，即将返回" << endl;
					Sleep(1000);
					mark1 = true;
					break;
				}
		}
		helper11 = helper11->next;
	}
	if (!mark1)
	{
		absent* helper22 = Absent;
		while (helper22 != NULL)
		{
			if (helper22 == temp2);
			else
			{
				if (!strcmp(helper22->data.Getstudentnumber(), b))
					if (strcmp(helper22->data.Getstudentname(), a))
					{
						cout << "信息与已有记录冲突(不同姓名共享学号)" << endl;
						cout << "操作无效，即将返回" << endl;
						Sleep(500);
						mark1 = true;
						break;
					}
			}
			helper22 = helper22->next;
		}
	}
	return mark1;
}
bool input_grade(char* a, char* b, char* c, char* d, char* a1, int &b1, int &c1)
{
	int p = 0;
	cout << "请输入成绩记录" << endl;
	cout << "(姓名 学号 班级 年级 课程名 学分数 百分制成绩)" << endl;
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	cin.getline(a, 51, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(b, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(c, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(d, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(a1, 51, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin >> b1;
	if (cin.fail() || b1 < 0)
	{
		b1 = -1;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), ' ');
		while (cin.peek() == ' ')
			getchar();
	}
	cin >> c1;
	if (cin.fail() || c1 < 0 || c1>100)
	{
		c1 = -1;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	while (true)
	{
		bool numbersign = false;
		while (b[p] != '\0')
		{
			if (b[p] > '9' || b[p] < '0')
			{
				numbersign = true;
				break;
			}
			p++;
		}
		if (numbersign == true)
		{
			cout << "请输入正确的学号(纯数字)" << endl;
			cin.getline(b, 21, '\n');
			p = 0;
		}
		if (numbersign == false)
			break;
	}
	if (b1 == -1)
	{
		cout << "请输入正确学分数" << endl;
		cin >> b1;
		while (cin.fail() || b1 < 0)
		{
			cout << "请输入正确学分数" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> b1;
		}
	}
	if (c1 == -1)
	{
		cout << "请输入正确的百分制成绩" << endl;
		cin >> c1;
		while (cin.fail() || c1 < 0 || c1>100)
		{
			cout << "请输入正确的百分制成绩" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> c1;
		}
	}
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	return judge_studentnumber(a, b, NULL, NULL);
}
bool input_absent(int &a, int &b, int &c, char*a1, char*b1, char*c1, char*d1, int &a2, char*c2, char*d2)
{
	int p = 0;
	cout << "请输入考勤日期" << endl;
	input_date(a, b, c);
	cout << "请输入考勤记录" << endl;
	cout << "(姓名 学号 班级 年级 节次 课程名 类型)" << endl;
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	while (cin.peek() == ' ')
		getchar();
	cin.getline(a1, 51, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(b1, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(c1, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(d1, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin >> a2;
	if (cin.fail() || a2 < 0 || a2 > 5)
	{
		a2 = -1;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), ' ');
		while (cin.peek() == ' ')
			getchar();
	}
	while (cin.peek() == ' ')
		getchar();
	cin.getline(c2, 21, ' ');
	while (cin.peek() == ' ')
		getchar();
	cin.getline(d2, 5, '\n');
	while (true)
	{
		bool numbersign = false;
		while (b1[p] != '\0')
		{
			if (b1[p] > '9' || b1[p] < '0')
			{
				numbersign = true;
				break;
			}
			p++;
		}
		if (numbersign == true)
		{
			cout << "请输入正确的学号(纯数字)" << endl;
			cin.getline(b1, 21, '\n');
			p = 0;
		}
		if (numbersign == false)
			break;
	}
	if (a2 == -1)
	{
		cout << "请输入正确节次(1-5)" << endl;
		cin >> a2;
		while (cin.fail() || a2 < 0 || a2 > 5)
		{
			cout << "请输入正确节次(1-5)" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> a2;
		}
	}
	while (strcmp(d2, "正常") && strcmp(d2, "迟到") && strcmp(d2, "早退") && strcmp(d2, "请假") && strcmp(d2, "缺课"))
	{
		cout << "请输入正确的类型(正常/迟到/早退/请假/缺课)" << endl;
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin.getline(d2, 5, '\n');
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
	return judge_studentnumber(a1, b1, NULL, NULL);
}
void establish_grade()
{
	char a[51], b[21], c[21], d[21], a1[51];
	int b1, c1;
	char k;
	bool sign = false, sign1 = false, sign2 = false;
	while (true)
	{
		system("cls");
		cout << "────────────────────────────录入成绩────────────────────────────" << endl;
		if (input_grade(a, b, c, d, a1, b1, c1))
			break;
		while (true)
		{
			sign = sign1 = false;
			system("cls");
			cout << "────────────────────────────录入成功────────────────────────────" << endl;
			cout << a << "  " << b << "  " << c << "  " << d << "  " << a1 << "  " << b1 << "  " << c1 << endl;
			cout << "────────────────────────────────────────────────────────────────" << endl;
			cout << "        [1] 确认      [0]重新录入     [w]放弃录入并返回" << endl;
			while (cin.peek() == '\n')
				getchar();
			k = getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			switch (k)
			{
			case '1':sign = true; sign1 = true; sign2 = true; break;
			case '0':sign = true; break;
			case 'w':sign = true; sign1 = true; break;
			default:
				cout << "所选择功能不存在，请重新输入" << endl;
				Sleep(700); break;
			}
			if (sign == true)
				break;
		}
		if (sign1 == true)
			break;
	}
	if (sign2)
	{
		grade* assistant_establish_grade = new grade{ record_grade(a,b,c,d,a1,b1,c1),NULL };
		list_insert(Grade, assistant_establish_grade);
	}
}
void establish_absent()
{
	int a, b, c;
	char a1[51], b1[21], c1[21], d1[21];
	int a2;
	char c2[51], d2[5];
	char k;
	bool sign = false, sign1 = false, sign2 = false;
	while (true)
	{
		sign = sign1 = false;
		system("cls");
		cout << "────────────────────────────录入考勤────────────────────────────" << endl;
		if (input_absent(a, b, c, a1, b1, c1, d1, a2, c2, d2))
			break;
		while (true)
		{
			system("cls");
			cout << "────────────────────────────录入成功────────────────────────────" << endl;
			cout << a << "-" << b << "-" << c << "  " << a1 << "  " << b1 << "  " << c1 << "  " << d1 << "  " << "(第" << a2 << "节)  " << c2 << "  " << d2 << endl;
			cout << "────────────────────────────────────────────────────────────────" << endl;
			cout << "        [1] 确认      [0]重新录入     [w]放弃录入并返回" << endl;
			while (cin.peek() == '\n')
				getchar();
			k = getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			switch (k)
			{
			case '1':sign = true; sign1 = true; sign2 = true; break;
			case '0':sign = true; break;
			case 'w':sign = true; sign1 = true; break;
			default:
				cout << "所选择功能不存在，请重新输入" << endl;
				Sleep(700); break;
			}
			if (sign == true)
				break;
		}
		if (sign1 == true)
			break;
	}
	if (sign2)
	{
		absent* assistant_establish_absent = new absent{ record_absent(a,b,c,a1,b1,c1,d1,a2,c2,d2),NULL };
		list_insert(Absent, assistant_establish_absent);
	}
}
void rewrite_grade()
{
	bool sign = false, sign1 = false, sign3 = true;
	grade* helper = Grade;
	char a[51], b[21], c[21], d[21], a1[51];
	int b1, c1;
	if (helper != NULL)
	{
		system("cls");
		cout << "────────────────────────────修改成绩────────────────────────────" << endl;
		cout << "请查找成绩记录" << endl;
		helper = searchmenu_grade();
		if (helper != NULL)
		{
			strcpy(a, helper->data.Getstudentname());
			strcpy(b, helper->data.Getstudentnumber());
			strcpy(c, helper->data.Getstudentclass());
			strcpy(d, helper->data.Getstudentgrade());
			strcpy(a1, helper->data.Getclassname());
			b1 = helper->data.Getclassmark();
			c1 = helper->data.Getmark();
			system("cls");
			char p;
			while (true)
			{
				while (true)
				{
					system("cls");
					cout << "┌────────────────────────────────────┐" << endl;
					cout << "│         请选择要修改的项目         │" << endl;
					cout << "│                                    │" << endl;
					cout << "│            [1]学生姓名             │" << endl;
					cout << "│            [2]学号                 │" << endl;
					cout << "│            [3]学生班级             │" << endl;
					cout << "│            [4]学生年级             │" << endl;
					cout << "│            [5]课程名               │" << endl;
					cout << "│            [6]学分                 │" << endl;
					cout << "│            [7]成绩                 │" << endl;
					cout << "│            [8]全部重新输入         │" << endl;
					cout << "│            [0]取消修改             │" << endl;
					cout << "│                                    │" << endl;
					cout << "└────────────────────────────────────┘" << endl;
					while (cin.peek() == '\n')
						getchar();
					p = getchar();
					while (cin.rdbuf()->in_avail())
						getchar();
					cin.clear();
					switch (p)
					{
					case '1':
						cout << "请输入学生姓名" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(a, 51, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '2':
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						input_studentnumber(b);
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '3':
						cout << "请输入学生班级" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(c, 21, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '4':
						cout << "请输入学生年级" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(d, 21, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '5':
						cout << "请输入课程名" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(a1, 51, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '6':
						cout << "请输入学分数" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin >> b1;
						while (cin.fail() || b1 < 0)
						{
							cout << "请输入正确的学分数" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> b1;
						}
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '7':
						cout << "请输入百分制成绩" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin >> c1;
						while (cin.fail() || c1 < 0 || c1 > 100)
						{
							cout << "请输入正确的百分制成绩" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> c1;
						}
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '8':
						input_grade(a, b, c, d, a1, b1, c1);
						sign = true; break;
					case '0':sign = sign1 = true; sign3 = false; break;
					default:
						cout << "所选择功能不存在，请重新输入" << endl;
						Sleep(700); break;
					}
					if (sign == true)
						break;
				}
				if (sign1 == true)
					break;
				if (p == '1' || p == '2')
					if (judge_studentnumber(a, b, helper, NULL))
					{
						sign3 = false;
						break;
					}
				while (true)
				{
					char k;
					sign = sign1 = false;
					system("cls");
					cout << "────────────────────────────录入成功────────────────────────────" << endl;
					cout << a << "  " << b << "  " << c << "  " << d << "  " << a1 << "  " << b1 << "  " << c1 << endl;
					cout << "────────────────────────────────────────────────────────────────" << endl;
					cout << "              [1]确认修改          [0]放弃修改并返回" << endl;
					while (cin.peek() == '\n')
						getchar();
					k = getchar();
					while (cin.rdbuf()->in_avail())
						getchar();
					cin.clear();
					switch (k)
					{
					case '1':sign = true; sign1 = true; break;
					case '0':sign = true; sign3 = false; break;
					default:
						cout << "所选择功能不存在，请重新输入" << endl;
						Sleep(700); break;
					}
					if (sign == true)
						break;
				}
				if (sign1 == true)
					break;
			}
			if (sign3)
			{
				helper->data.Setstudentname(a);
				helper->data.Setstudentnumber(b);
				helper->data.Setstudentclass(c);
				helper->data.Setstudentgrade(d);
				helper->data.Setclassname(a1);
				helper->data.Setclassmark(b1);
				helper->data.Setmark(c1);
			}
		}
	}
	else
	{
		system("cls");
		cout << "无数据！" << endl;
		Sleep(700);
	}
}
void rewrite_absent()
{
	bool sign = false, sign1 = false, sign3 = true;
	absent* helper = Absent;
	int a, b, c;
	char a1[51], b1[21], c1[21], d1[21];
	int a2;
	char c2[51], d2[5];
	if (helper != NULL)
	{
		system("cls");
		cout << "────────────────────────────修改考勤────────────────────────────" << endl;
		cout << "请查找考勤记录" << endl;
		helper = searchmenu_absent();
		if (helper != NULL)
		{
			a = helper->data.Getyear();
			b = helper->data.Getmonth();
			c = helper->data.Getdate();
			strcpy(a1, helper->data.Getstudentname());
			strcpy(b1, helper->data.Getstudentnumber());
			strcpy(c1, helper->data.Getstudentclass());
			strcpy(d1, helper->data.Getstudentgrade());
			a2 = helper->data.Getclassnumber();
			strcpy(c2, helper->data.Getclassname());
			strcpy(d2, helper->data.Getform());
			system("cls");
			char p;
			while (true)
			{
				while (true)
				{
					system("cls");
					cout << "┌────────────────────────────────────┐" << endl;
					cout << "│         请选择要修改的项目         │" << endl;
					cout << "│                                    │" << endl;
					cout << "│            [1]学生姓名             │" << endl;
					cout << "│            [2]学号                 │" << endl;
					cout << "│            [3]学生班级             │" << endl;
					cout << "│            [4]学生年级             │" << endl;
					cout << "│            [5]时间                 │" << endl;
					cout << "│            [6]课程名               │" << endl;
					cout << "│            [7]类型                 │" << endl;
					cout << "│            [8]节次                 │" << endl;
					cout << "│            [9]全部重新输入         │" << endl;
					cout << "│            [0]取消修改             │" << endl;
					cout << "│                                    │" << endl;
					cout << "└────────────────────────────────────┘" << endl;
					while (cin.peek() == '\n')
						getchar();
					p = getchar();
					while (cin.rdbuf()->in_avail())
						getchar();
					cin.clear();
					switch (p)
					{
					case '1':
						cout << "请输入学生姓名" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(a1, 51, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '2':
						input_studentnumber(b1);
						sign = true; break;
					case '3':
						cout << "请输入学生班级" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(c1, 21, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '4':
						cout << "请输入学生年级" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(d1, 21, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '5':
						cout << "请输入时间" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						input_date(a, b, c);
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '6':
						cout << "请输入课程名" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(c2, 51, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '7':
						cout << "请输入类型" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin.getline(d2, 5, '\n');
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						while (strcmp(d2, "正常") && strcmp(d2, "迟到") && strcmp(d2, "早退") && strcmp(d2, "请假") && strcmp(d2, "缺课"))
						{
							cout << "请输入正确的类型(正常/迟到/早退/请假/缺课)" << endl;
							while (cin.rdbuf()->in_avail())
								getchar();
							cin.clear();
							cin.getline(d2, 5, '\n');
							while (cin.rdbuf()->in_avail())
								getchar();
							cin.clear();
						}
						sign = true; break;
					case '8':
						cout << "请输入节次" << endl;
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						cin >> a2;
						while (cin.fail() || a2 < 0 || a2 > 5)
						{
							cout << "请输入正确节次(1-5)" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> a2;
						}
						while (cin.rdbuf()->in_avail())
							getchar();
						cin.clear();
						sign = true; break;
					case '9':
						input_absent(a, b, c, a1, b1, c1, d1, a2, c2, d2);
						sign = true; break;
					case '0':sign = sign1 = true; sign3 = false; break;
					default:
						cout << "所选择功能不存在，请重新输入" << endl;
						Sleep(700); break;
					}
					if (sign == true)
						break;
				}
				if (sign1 == true)
					break;
				if (p == '1' || p == '2')
					if (judge_studentnumber(a1, b1, NULL, helper))
					{
						sign3 = false;
						break;
					}
				while (true)
				{
					char k;
					sign = sign1 = false;
					system("cls");
					cout << "────────────────────────────录入成功────────────────────────────" << endl;
					cout << a << "-" << b << "-" << c << "  " << a1 << "  " << b1 << "  " << c1 << "  " << d1 << "  " << "(第" << a2 << "节)  " << c2 << "  " << d2 << endl;
					cout << "────────────────────────────────────────────────────────────────" << endl;
					cout << "              [1]确认修改          [0]放弃修改并返回" << endl;
					while (cin.peek() == '\n')
						getchar();
					k = getchar();
					while (cin.rdbuf()->in_avail())
						getchar();
					cin.clear();
					switch (k)
					{
					case '1':sign = true; sign1 = true; break;
					case '0':sign = true; sign3 = false; break;
					default:
						cout << "所选择功能不存在，请重新输入" << endl;
						Sleep(700); break;
					}
					if (sign == true)
						break;
				}
				if (sign1 == true)
					break;
			}
			if (sign3)
			{
				helper->data.Setyear(a);
				helper->data.Setmonth(b);
				helper->data.Setdate(c);
				helper->data.reflect_day();
				helper->data.Setstudentname(a1);
				helper->data.Setstudentnumber(b1);
				helper->data.Setstudentclass(c1);
				helper->data.Setstudentgrade(d1);
				helper->data.Setclassnumber(a2);
				helper->data.Setclassname(c2);
				helper->data.Setform(d2);
			}
		}
	}
	else
	{
		system("cls");
		cout << "无数据！" << endl;
		Sleep(700);
	}
}
void delete_grade()
{
	bool sign = false, mark = false;
	grade* helper = Grade;
	char a[51], b[21], c[21], d[21], a1[51];
	int b1, c1;
	if (helper != NULL)
	{
		system("cls");
		cout << "────────────────────────────删除成绩────────────────────────────" << endl;
		cout << "请查找成绩记录" << endl;
		helper = searchmenu_grade();
		if (helper != NULL)
		{
			strcpy(a, helper->data.Getstudentname());
			strcpy(b, helper->data.Getstudentnumber());
			strcpy(c, helper->data.Getstudentclass());
			strcpy(d, helper->data.Getstudentgrade());
			strcpy(a1, helper->data.Getclassname());
			b1 = helper->data.Getclassmark();
			c1 = helper->data.Getmark();
			while (true)
			{
				char k;
				sign = false;
				system("cls");
				cout << a << "  " << b << "  " << c << "  " << d << "  " << a1 << "  " << b1 << "  " << c1 << endl;
				cout << "────────────────────────────────────────────────────────────────" << endl;
				cout << "              [1]确认删除          [0]放弃删除并返回" << endl;
				while (cin.peek() == '\n')
					getchar();
				k = getchar();
				while (cin.rdbuf()->in_avail())
					getchar();
				cin.clear();
				switch (k)
				{
				case '1':sign = true; mark = true; break;
				case '0':sign = true; break;
				default:
					cout << "所选择功能不存在，请重新输入" << endl;
					Sleep(700); break;
				}
				if (sign == true)
					break;
			}
			if (mark)
				list_delete(Grade, helper);
		}
	}
	else
	{
		system("cls");
		cout << "无数据！" << endl;
		Sleep(700);
	}

}
void delete_absent()
{
	bool sign = false, mark = false;
	absent* helper = Absent;
	int a, b, c;
	char a1[51], b1[21], c1[21], d1[21];
	int a2, b2;
	char c2[51], d2[5];
	if (helper != NULL)
	{
		system("cls");
		cout << "────────────────────────────删除考勤────────────────────────────" << endl;
		cout << "请查找成绩记录" << endl;
		helper = searchmenu_absent();
		if (helper != NULL)
		{
			a = helper->data.Getyear();
			b = helper->data.Getmonth();
			c = helper->data.Getdate();
			strcpy(a1, helper->data.Getstudentname());
			strcpy(b1, helper->data.Getstudentnumber());
			strcpy(c1, helper->data.Getstudentclass());
			strcpy(d1, helper->data.Getstudentgrade());
			a2 = helper->data.Getday();
			b2 = helper->data.Getclassnumber();
			strcpy(c2, helper->data.Getclassname());
			strcpy(d2, helper->data.Getform());
			while (true)
			{
				char k;
				sign = false;
				system("cls");
				cout << a << "-" << b << "-" << c << "  " << a1 << "  " << b1 << "  " << c1 << "  " << d1 << "  " << a2 << "-" << b2 << "  " << c2 << "  " << d2 << endl;
				cout << "────────────────────────────────────────────────────────────────" << endl;
				cout << "              [1]确认删除          [0]放弃删除并返回" << endl;
				while (cin.peek() == '\n')
					getchar();
				k = getchar();
				while (cin.rdbuf()->in_avail())
					getchar();
				cin.clear();
				switch (k)
				{
				case '1':sign = true; mark = true; break;
				case '0':sign = true; break;
				default:
					cout << "所选择功能不存在，请重新输入" << endl;
					Sleep(700); break;
				}
				if (sign == true)
					break;
			}
			if (mark)
				list_delete(Absent, helper);
		}
	}
	else
	{
		system("cls");
		cout << "无数据！" << endl;
		Sleep(700);
	}
}
//统计学生成绩
void analyze_grade_student()
{
	grade* helper = Grade;
	if (helper != NULL)
	{
		bool mark = false;
		double sum_point = 0;
		int sum_classmark = 0, count = 1;
		system("cls");
		cout << "────────────────────────统计学生成绩────────────────────────────" << endl;
		helper = list_search_studentnumber(helper, mark);
		if (helper != NULL)
		{
			sum_classmark = helper->data + sum_classmark;
			sum_point = helper->data + sum_point;
			system("cls");
			cout << "────────────────────────统计学生成绩────────────────────────────" << endl;
			helper->data.student::print();
			cout << endl;
			cout << "(" << count << ") " << helper->data.Getclassname() << " (" << helper->data.Getclassmark() << "学分)  " << helper->data.Getmark() << "  " << helper->data.Getgrade() << "  " << setiosflags(ios_base::fixed) << setprecision(1) << helper->data.Getpoint() << resetiosflags(ios_base::fixed) << endl;
			helper = helper->next;
			while (helper != NULL)
			{
				mark = true;
				helper = list_search_studentnumber(helper, mark);
				if (helper == NULL)
					break;
				sum_classmark = helper->data + sum_classmark;
				sum_point = helper->data + sum_point;
				count++;
				cout << "(" << count << ") " << helper->data.Getclassname() << " (" << helper->data.Getclassmark() << "学分)  " << helper->data.Getmark() << "  " << helper->data.Getgrade() << "  " << setiosflags(ios_base::fixed) << setprecision(1) << helper->data.Getpoint() << resetiosflags(ios_base::fixed) << endl;
				helper = helper->next;
			}
			cout << "————共" << count << "条记录————" << endl;
			cout << "已修课程平均绩点:" << setiosflags(ios_base::fixed) << setprecision(2) << sum_point / sum_classmark << resetiosflags(ios_base::fixed) << endl;
			cout << "────────────────────────────────────────────────────────────────" << endl;
			cout << "                       [输入任意字符返回]" << endl;
			while (cin.peek() == '\n')
				getchar();
			getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
		else
		{
			system("cls");
			cout << "无相关记录！" << endl;
			Sleep(700);
		}
	}
	else
	{
		system("cls");
		cout << "无数据！" << endl;
		Sleep(700);
	}
}
//统计学生考勤
void analyze_absent_student()
{
	absent* helper = Absent;
	if (helper != NULL)
	{
		bool mark = false;
		int count = 1;
		int count_[5] = { 0,0,0,0,0 };
		char a;
		system("cls");
		while (true)
		{
			bool sign = false;
			system("cls");
			cout << "┌────────────────────────────────────┐" << endl;
			cout << "│          请选择统计方式            │" << endl;
			cout << "│                                    │" << endl;
			cout << "│          [1]全部记录               │" << endl;
			cout << "│          [2]指定年                 │" << endl;
			cout << "│          [3]指定年月               │" << endl;
			cout << "│          [4]指定日期               │" << endl;
			cout << "│          [5]指定学期               │" << endl;
			cout << "│                                    │" << endl;
			cout << "└────────────────────────────────────┘" << endl;
			while (cin.peek() == '\n')
				getchar();
			a = getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			switch (a)
			{
			case '1':case '2':case '3':case '4':case '5':sign = true; break;
			default:
				cout << "所选择功能不存在，请重新输入" << endl;
				Sleep(700); break;
			}
			if (sign == true)
				break;
		}
		system("cls");
		cout << "────────────────────────统计学生考勤────────────────────────────" << endl;
		switch (a)
		{
		case '1':helper = list_search_studentnumber(helper, mark); break;
		case '2':helper = h1[0](helper, mark); break;
		case '3':helper = h1[1](helper, mark); break;
		case '4':helper = h1[2](helper, mark); break;
		case '5':helper = h1[3](helper, mark); break;
		}
		if (helper != NULL)
		{
			if (!(strcmp(helper->data.Getform(), "正常"))) count_[0]++;
			else if (!(strcmp(helper->data.Getform(), "迟到"))) count_[1]++;
			else if (!(strcmp(helper->data.Getform(), "早退"))) count_[2]++;
			else if (!(strcmp(helper->data.Getform(), "缺课"))) count_[3]++;
			else count_[4]++;
			system("cls");
			cout << "────────────────────────统计学生考勤────────────────────────────" << endl;
			helper->data.student::print();
			cout << endl;
			switch (a)
			{
			case '2':cout << "时间:" << helper->data.Getyear() << "年" << endl; break;
			case '3':cout << "时间:" << helper->data.Getyear() << "年" << helper->data.Getmonth() << "月" << endl; break;
			case '4':cout << "时间:" << helper->data.Getyear() << "年" << helper->data.Getmonth() << "月" << helper->data.Getdate() << "日" << endl; break;
			case '5':cout << "时间:" << helper->data.Getyear() << "年" << helper->data.Getsemester() << endl; break;
			}
			cout << "(" << count << ") ";
			helper->data.time::print();
			cout << helper->data.Getclassname() << "  " << helper->data.Getday() << "-" << helper->data.Getclassnumber() << "  " << helper->data.Getform() << endl;
			helper = helper->next;
			while (helper != NULL)
			{
				mark = true;
				switch (a)
				{
				case '1':helper = list_search_studentnumber(helper, mark); break;
				case '2':helper = h1[0](helper, mark); break;
				case '3':helper = h1[1](helper, mark); break;
				case '4':helper = h1[2](helper, mark); break;
				case '5':helper = h1[3](helper, mark); break;
				}
				if (helper == NULL)
					break;
				if (!(strcmp(helper->data.Getform(), "正常"))) count_[0]++;
				else if (!(strcmp(helper->data.Getform(), "迟到"))) count_[1]++;
				else if (!(strcmp(helper->data.Getform(), "早退"))) count_[2]++;
				else if (!(strcmp(helper->data.Getform(), "缺课"))) count_[3]++;
				else count_[4]++;
				count++;
				cout << "(" << count << ") ";
				helper->data.time::print();
				cout << helper->data.Getclassname() << "  " << helper->data.Getday() << "-" << helper->data.Getclassnumber() << "  " << helper->data.Getform() << endl;
				helper = helper->next;
			}
			cout << "————共" << count << "条记录————" << endl;
			cout << "正常" << count_[0] << "次  迟到" << count_[1] << "次  早退" << count_[2] << "次  缺课" << count_[3] << "次  请假" << count_[4] << "次" << endl;
			cout << "────────────────────────────────────────────────────────────────" << endl;
			cout << "                       [输入任意字符返回]" << endl;
			while (cin.peek() == '\n')
				getchar();
			getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
		else
		{
			system("cls");
			cout << "无相关记录！" << endl;
			Sleep(700);
		}
	}
	else
	{
		system("cls");
		cout << "无数据！" << endl;
		Sleep(700);
	}
}
//统计课程成绩
void analyze_grade_class()
{
	grade* helper = Grade;
	if (helper != NULL)
	{
		bool mark = false;
		double sum_point = 0;
		int count_student = 0, count = 1;
		system("cls");
		cout << "────────────────────────统计课程成绩────────────────────────────" << endl;
		helper = list_search_classname(helper, mark);
		if (helper != NULL)
		{
			count_student++;
			sum_point = helper->data.Getpoint() + sum_point;
			system("cls");
			cout << "────────────────────────统计课程成绩────────────────────────────" << endl;
			cout << helper->data.Getclassname() << " (" << helper->data.Getclassmark() << "学分)" << endl;
			cout << "(" << count << ") ";
			helper->data.student::print();
			cout << helper->data.Getmark() << "  " << helper->data.Getgrade() << "  " << setiosflags(ios_base::fixed) << setprecision(1) << helper->data.Getpoint() << resetiosflags(ios_base::fixed) << endl;
			helper = helper->next;
			while (helper != NULL)
			{
				mark = true;
				helper = list_search_classname(helper, mark);
				if (helper == NULL)
					break;
				count_student++;
				sum_point = helper->data.Getpoint() + sum_point;
				count++;
				cout << "(" << count << ") ";
				helper->data.student::print();
				cout << helper->data.Getmark() << "  " << helper->data.Getgrade() << "  " << setiosflags(ios_base::fixed) << setprecision(1) << helper->data.Getpoint() << resetiosflags(ios_base::fixed) << endl;
				helper = helper->next;
			}
			cout << endl << "————共" << count << "条记录————" << endl;
			cout << "选课学生平均绩点:" << setiosflags(ios_base::fixed) << setprecision(2) << sum_point / count_student << resetiosflags(ios_base::fixed) << endl;
			cout << "────────────────────────────────────────────────────────────────" << endl;
			cout << "                       [输入任意字符返回]" << endl;
			while (cin.peek() == '\n')
				getchar();
			getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
		else
		{
			system("cls");
			cout << "无相关记录！" << endl;
			Sleep(700);
		}
	}
	else
	{
		cout << "无数据！" << endl;
		Sleep(700);
	}
}
//统计课程考勤
void analyze_absent_class()
{
	absent* helper = Absent;
	if (helper != NULL)
	{
		bool mark = false;
		int count = 1;
		int count_[5] = { 0,0,0,0,0 };
		char a;
		system("cls");
		while (true)
		{
			bool sign = false;
			system("cls");
			cout << "┌────────────────────────────────────┐" << endl;
			cout << "│          请选择统计方式            │" << endl;
			cout << "│                                    │" << endl;
			cout << "│          [1]全部记录               │" << endl;
			cout << "│          [2]指定年                 │" << endl;
			cout << "│          [3]指定年月               │" << endl;
			cout << "│          [4]指定日期               │" << endl;
			cout << "│          [5]指定学期               │" << endl;
			cout << "│                                    │" << endl;
			cout << "└────────────────────────────────────┘" << endl;
			while (cin.peek() == '\n')
				getchar();
			a = getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
			switch (a)
			{
			case '1':case '2':case '3':case '4':case '5':sign = true; break;
			default:
				cout << "所选择功能不存在，请重新输入" << endl;
				Sleep(700); break;
			}
			if (sign == true)
				break;
		}
		system("cls");
		cout << "────────────────────────统计学生考勤────────────────────────────" << endl;
		switch (a)
		{
		case '1':helper = list_search_classname(helper, mark); break;
		case '2':helper = h2[0](helper, mark); break;
		case '3':helper = h2[1](helper, mark); break;
		case '4':helper = h2[2](helper, mark); break;
		case '5':helper = h2[3](helper, mark); break;
		}
		if (helper != NULL)
		{
			if (!(strcmp(helper->data.Getform(), "正常"))) count_[0]++;
			else if (!(strcmp(helper->data.Getform(), "迟到"))) count_[1]++;
			else if (!(strcmp(helper->data.Getform(), "早退"))) count_[2]++;
			else if (!(strcmp(helper->data.Getform(), "缺课"))) count_[3]++;
			else count_[4]++;
			system("cls");
			cout << "────────────────────────统计学生考勤────────────────────────────" << endl;
			cout << helper->data.Getclassname() << endl;
			switch (a)
			{
			case '2':cout << "时间:" << helper->data.Getyear() << "年" << endl; break;
			case '3':cout << "时间:" << helper->data.Getyear() << "年" << helper->data.Getmonth() << "月" << endl; break;
			case '4':cout << "时间:" << helper->data.Getyear() << "年" << helper->data.Getmonth() << "月" << helper->data.Getdate() << "日" << endl; break;
			case '5':cout << "时间:" << helper->data.Getyear() << "年  " << helper->data.Getsemester() << endl; break;
			}
			cout << "(" << count << ") ";
			helper->data.print();
			helper = helper->next;
			while (helper != NULL)
			{
				mark = true;
				switch (a)
				{
				case '1':helper = list_search_studentnumber(helper, mark); break;
				case '2':helper = h2[0](helper, mark); break;
				case '3':helper = h2[1](helper, mark); break;
				case '4':helper = h2[2](helper, mark); break;
				case '5':helper = h2[3](helper, mark); break;
				}
				if (helper == NULL)
					break;
				if (!(strcmp(helper->data.Getform(), "正常"))) count_[0]++;
				else if (!(strcmp(helper->data.Getform(), "迟到"))) count_[1]++;
				else if (!(strcmp(helper->data.Getform(), "早退"))) count_[2]++;
				else if (!(strcmp(helper->data.Getform(), "缺课"))) count_[3]++;
				else count_[4]++;
				count++;
				cout << "(" << count << ") ";
				helper->data.print();
				helper = helper->next;
			}
			cout << endl << "————共" << count << "条记录————" << endl;
			cout << "正常" << count_[0] << "人次  迟到" << count_[1] << "人次  早退" << count_[2] << "人次  缺课" << count_[3] << "人次  请假" << count_[4] << "人次" << endl;
			cout << "────────────────────────────────────────────────────────────────" << endl;
			cout << "                       [输入任意字符返回]" << endl;
			while (cin.peek() == '\n')
				getchar();
			getchar();
			while (cin.rdbuf()->in_avail())
				getchar();
			cin.clear();
		}
		else
		{
			system("cls");
			cout << "无相关记录！" << endl;
			Sleep(700);
		}
	}
	else
	{
		cout << "无数据！" << endl;
		Sleep(700);
	}
}
void rank_GPA()
{
	struct GPArecorder
	{
		char* name;
		char* number;
		char* Class;
		char* grade;
		int mark = 0;
		double pointsum = 0;
		double GPA = 0;
		GPArecorder* next;
	};
	grade* helper = Grade;
	GPArecorder* recorder = NULL, *helper1, *Operator, **ranker;
	int count = 1;
	bool sign = false;
	if (helper != NULL)
	{
		system("cls");
		cout << "计算排名中..." << endl;
		helper1 = new GPArecorder;
		helper1->name = new char[strlen(helper->data.Getstudentname()) + 1];
		strcpy(helper1->name, helper->data.Getstudentname());
		helper1->number = new char[strlen(helper->data.Getstudentnumber()) + 1];
		strcpy(helper1->number, helper->data.Getstudentnumber());
		helper1->Class = new char[strlen(helper->data.Getstudentclass()) + 1];
		strcpy(helper1->Class, helper->data.Getstudentclass());
		helper1->grade = new char[strlen(helper->data.Getstudentgrade()) + 1];
		strcpy(helper1->grade, helper->data.Getstudentgrade());
		helper1->mark = helper->data + helper1->mark;
		helper1->pointsum = helper->data + helper1->pointsum;
		list_insert(recorder, helper1);
		helper = helper->next;
		while (helper != NULL)
		{
			sign = false;
			Operator = recorder;
			while (Operator != NULL)
			{
				if (!(strcmp(Operator->number, helper->data.Getstudentnumber())))
				{
					Operator->mark = helper->data + Operator->mark;
					Operator->pointsum = helper->data + Operator->pointsum;
					helper = helper->next;
					sign = true;
					break;
				}
				else
					Operator = Operator->next;
			}
			if (!sign)
			{
				helper1 = new GPArecorder;
				count++;
				helper1->name = new char[strlen(helper->data.Getstudentname()) + 1];
				strcpy(helper1->name, helper->data.Getstudentname());
				helper1->number = new char[strlen(helper->data.Getstudentnumber()) + 1];
				strcpy(helper1->number, helper->data.Getstudentnumber());
				helper1->Class = new char[strlen(helper->data.Getstudentclass()) + 1];
				strcpy(helper1->Class, helper->data.Getstudentclass());
				helper1->grade = new char[strlen(helper->data.Getstudentgrade()) + 1];
				strcpy(helper1->grade, helper->data.Getstudentgrade());
				helper1->mark = helper->data + helper1->mark;
				helper1->pointsum = helper->data + helper1->pointsum;
				list_insert(recorder, helper1);
				helper = helper->next;
			}
		}
		Operator = recorder;
		ranker = new GPArecorder*[count];
		for (int i = 0; i < count; i++)
		{
			Operator->GPA = Operator->pointsum / Operator->mark;
			ranker[i] = Operator;
			Operator = Operator->next;
		}
		int m, k, j, i;
		GPArecorder* d;
		k = 0; m = count - 1;
		while (k < m)
		{
			j = m - 1; m = 0;
			for (i = k; i <= j; i++)
				if (ranker[i]->GPA < ranker[i + 1]->GPA)
				{
					d = ranker[i]; ranker[i] = ranker[i + 1]; ranker[i + 1] = d; m = i;
				}
				else if (ranker[i]->GPA == ranker[i + 1]->GPA)
					if (strcmp(ranker[i]->number, ranker[i + 1]->number))
					{
						d = ranker[i]; ranker[i] = ranker[i + 1]; ranker[i + 1] = d; m = i;
					}
			j = k + 1; k = 0;
			for (i = m; i >= j; i--)
				if (ranker[i - 1]->GPA < ranker[i]->GPA)
				{
					d = ranker[i]; ranker[i] = ranker[i - 1]; ranker[i - 1] = d; m = i;
				}
				else if (ranker[i - 1]->GPA == ranker[i]->GPA)
					if (strcmp(ranker[i - 1]->number, ranker[i]->number))
					{
						d = ranker[i]; ranker[i] = ranker[i - 1]; ranker[i - 1] = d; m = i;
					}
		}
		system("cls");
		cout << "────────────────────────查看学生排名────────────────────────────" << endl;
		for (int j = 0; j < count; j++)
			cout << "(" << j + 1 << ") " << ranker[j]->number << "  " << ranker[j]->name << "  " << ranker[j]->Class << "  " << ranker[j]->grade << "  " << setiosflags(ios_base::fixed) << setprecision(2) << ranker[j]->GPA << resetiosflags(ios_base::fixed) << endl;
		cout << endl << "————共" << count << "条记录————" << endl;
		cout << "────────────────────────────────────────────────────────────────" << endl;
		cout << "                       [输入任意字符返回]" << endl;
		while (cin.peek() == '\n')
			getchar();
		getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
	}
	else
	{
		cout << "无数据！" << endl;
		Sleep(700);
	}
}
//从文件中读取数据
void load_data()
{
	__int64 length, count;
	ifstream ip;
	grade* helper1;
	char a[51], b[21], c[21], d[21], e[51];
	int f, g;
	ip.open("grade", ios_base::binary | ios_base::in);
	ip.seekg(0, ios_base::end);
	length = (_int64)ip.tellg();
	ip.seekg(0, ios_base::beg);
	if (length != -1)
	{
		count = length / 173;
		system("cls");
		cout << "正在载入成绩数据...";
		for (__int64 j = 0; j < count; j++)
		{
			ip.read(a, 51);
			ip.read(b, 21);
			ip.read(c, 21);
			ip.read(d, 21);
			ip.read(e, 51);
			ip.read((char*)&f, 4);
			ip.read((char*)&g, 4);
			helper1 = new grade{ record_grade(a,b,c,d,e,f,g),NULL };
			list_insert(Grade, helper1);
		}
		ip.close();
	}
	absent* helper1_;
	int h, i;
	char t[5];
	ip.open("absent", ios_base::binary | ios_base::in);
	ip.seekg(0, ios_base::end);
	length = (_int64)ip.tellg();
	ip.seekg(0, ios_base::beg);
	if (length != -1)
	{
		count = length / 186;
		system("cls");
		cout << "正在载入考勤数据...";
		for (__int64 j = 0; j < count; j++)
		{
			ip.read((char*)&f, 4);
			ip.read((char*)&g, 4);
			ip.read((char*)&h, 4);
			ip.read(a, 51);
			ip.read(b, 21);
			ip.read(c, 21);
			ip.read(d, 21);
			ip.read((char*)&i, 4);
			ip.read(e, 51);
			ip.read(t, 5);
			helper1_ = new absent{ record_absent(f,g,h,a,b,c,d,i,e,t),NULL };
			list_insert(Absent, helper1_);
		}
		ip.close();
	}
}
//将数据写入文件并释放动态内存
bool clear()
{
	char a1;
	bool sign = false, sign1 = false, sign2 = false;
	grade* helper1 = Grade, *helper11;
	absent* helper2 = Absent, *helper22;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│     是否保存本次运行的数据更改？   │" << endl;
		cout << "│                                    │" << endl;
		cout << "│          [1]保存                   │" << endl;
		cout << "│          [2]不保存                 │" << endl;
		cout << "│          [0]取消并返回主菜单       │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a1 = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a1)
		{
		case '1':sign = true; sign1 = true; break;
		case '2':sign = true; break;
		case '0':sign = true; sign2 = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
	if (sign2);
	else
	{
		if (sign1)
		{
			ofstream of;
			of.open("grade", ios_base::binary | ios_base::trunc);
			cout << "正在保存成绩信息..." << endl;
			char a[51], b[21], c[21], d[21], e[51];
			int f, g;
			while (helper1 != NULL)
			{
				strcpy(a, helper1->data.Getstudentname());
				strcpy(b, helper1->data.Getstudentnumber());
				strcpy(c, helper1->data.Getstudentclass());
				strcpy(d, helper1->data.Getstudentgrade());
				strcpy(e, helper1->data.Getclassname());
				f = helper1->data.Getclassmark();
				g = helper1->data.Getmark();
				of.write(a, 51);
				of.write(b, 21);
				of.write(c, 21);
				of.write(d, 21);
				of.write(e, 51);
				of.write((char*)&f, 4);
				of.write((char*)&g, 4);
				helper1 = helper1->next;
			}
			of.close();
			of.open("absent", ios_base::binary | ios_base::trunc);
			system("cls");
			cout << "正在保存考勤信息..." << endl;
			int h, i;
			char j[5];
			while (helper2 != NULL)
			{
				strcpy(a, helper2->data.Getstudentname());
				strcpy(b, helper2->data.Getstudentnumber());
				strcpy(c, helper2->data.Getstudentclass());
				strcpy(d, helper2->data.Getstudentgrade());
				strcpy(e, helper2->data.Getclassname());
				strcpy(j, helper2->data.Getform());
				f = helper2->data.Getyear();
				g = helper2->data.Getmonth();
				h = helper2->data.Getdate();
				i = helper2->data.Getclassnumber();
				of.write((char*)&f, 4);
				of.write((char*)&g, 4);
				of.write((char*)&h, 4);
				of.write(a, 51);
				of.write(b, 21);
				of.write(c, 21);
				of.write(d, 21);
				of.write((char*)&i, 4);
				of.write(e, 51);
				of.write(j, 5);
				helper2 = helper2->next;
			}
			of.close();
		}
		while (helper1 != NULL)
		{
			helper11 = helper1->next;
			delete helper1;
			helper1 = helper11;
		}
		while (helper2 != NULL)
		{
			helper22 = helper2->next;
			delete helper2;
			helper2 = helper22;
		}
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│             保存成功！             │" << endl;
		cout << "│      学生信息管理系统即将退出...   │" << endl;
		cout << "│                                    │" << endl;
		cout << "│           欢迎下次使用！           │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		Sleep(700);
	}
	return sign2;
}
//菜单功能函数
void return_(bool &a, char t)
{
	char a1;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│             操作结束！             │" << endl;
		cout << "│                                    │" << endl;
		cout << "│           [1]继续本操作            │" << endl;
		cout << "│           [0]返回主菜单            │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a1 = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a1)
		{
		case '1':sign = true; cin.putback('\n'); cin.putback(t); break;
		case '0':sign = true; a = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
}
void return_1(bool &a)
{
	system("cls");
	cout << "┌────────────────────────────────────┐" << endl;
	cout << "│             操作结束！             │" << endl;
	cout << "│                                    │" << endl;
	cout << "│          即将返回主菜单...         │" << endl;
	cout << "└────────────────────────────────────┘" << endl;
	a = true;
	Sleep(700);
}
void programmer()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│            #开发者信息#            │" << endl;
		cout << "│                                    │" << endl;
		cout << "│              @郝千越               │" << endl;
		cout << "│             July,2019              │" << endl;
		cout << "│        Tsinghua University         │" << endl;
		cout << "│                                    │" << endl;
		cout << "│           [1]返回主菜单            │" << endl;
		cout << "│                                    │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
}
void grademenu()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│              成绩管理              │" << endl;
		cout << "│                                    │" << endl;
		cout << "│            [1]录入成绩             │" << endl;
		cout << "│            [2]修改记录             │" << endl;
		cout << "│            [3]删除记录             │" << endl;
		cout << "│            [4]统计学生成绩         │" << endl;
		cout << "│            [5]统计课程成绩         │" << endl;
		cout << "│            [6]查看学生排名         │" << endl;
		cout << "│            [7]返回主菜单           │" << endl;
		cout << "│                                    │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':establish_grade(); return_(sign, a); break;
		case '2':rewrite_grade(); return_(sign, a); break;
		case '3':delete_grade(); return_(sign, a); break;
		case '4':analyze_grade_student(); return_1(sign); break;
		case '5':analyze_grade_class(); return_1(sign); break;
		case '6':rank_GPA(); return_1(sign); break;
		case '7':sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
}
void absentmenu()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│              考勤管理              │" << endl;
		cout << "│                                    │" << endl;
		cout << "│          [1]录入考勤记录           │" << endl;
		cout << "│          [2]修改考勤记录           │" << endl;
		cout << "│          [3]删除考勤记录           │" << endl;
		cout << "│          [4]统计学生考勤记录       │" << endl;
		cout << "│          [5]统计课程考勤记录       │" << endl;
		cout << "│          [6]返回主菜单             │" << endl;
		cout << "│                                    │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':establish_absent(); return_(sign, a); break;
		case '2':rewrite_absent(); return_(sign, a); break;
		case '3':delete_absent(); return_(sign, a); break;
		case '4':analyze_absent_student(); return_1(sign); break;
		case '5':analyze_absent_class(); return_1(sign); break;
		case '6':sign = true; return_(sign, a); break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
	}
}
void mainmenu()
{
	char a;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│     欢迎使用学生信息管理系统 ！    │" << endl;
		cout << "│                                    │" << endl;
		cout << "│          [1]进入成绩管理           │" << endl;
		cout << "│          [2]进入考勤管理           │" << endl;
		cout << "│          [3]开发者信息             │" << endl;
		cout << "│          [0]退出系统               │" << endl;
		cout << "│                                    │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':grademenu(); break;
		case '2':absentmenu(); break;
		case '3':programmer(); break;
		case '0':if (clear());
				 else exit(0); break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
	}
}
int main()
{
	Grade = NULL;
	Absent = NULL;
	load_data();
	mainmenu();
	return 0;
}