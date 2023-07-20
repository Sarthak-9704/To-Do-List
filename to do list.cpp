#include <iostream>
#include <vector>
#include <string>
using namespace std;
void fun();
void inp_task();
void view_to_do();
void mark();
void view_done();
vector<string>to_do;
vector<string>done;
string task;

void mark()
{
	cout<<"enter the serial number of the task to be marked done ";
	int a;
	cin>>a;
	a=a-1;
	done.push_back(to_do[a]);
	vector<string>::iterator it;
	it = to_do.begin() + a;
	to_do.erase(it);
}
void inp_task()
{
	cout<<"Enter tasks and press '000' to exit \n";
	do {
		getline(cin,task);
		if(task=="000")
		break;
		to_do.push_back(task);
	}
	while(task!="000");
}

void view_to_do()
{
	int n;
	cout<<"the tasks not completed are \n";
	for(n=0; n<to_do.size();++n)
	{
		cout<< n+1 <<". "<<to_do[n]<<endl;
	}
}
void view_done()
{
	int n;
	cout<<"the tasks completed are \n";
	for(n=0; n<done.size();++n)
	{
		cout<< n+1 <<". "<<done[n]<<endl;
	}
}

void fun()
{
	int a;
	cout<<"enter 1 for entering tasks \nenter 2 for viewing tasks \nenter 3 for viewing completed tasks \nenter 4 for marking tasks as done ";
	cin>>a;
	
	switch (a)
	{
		case 1:
			inp_task();
			fun();
		case 2:
			view_to_do();
			fun();
		case 3:
			view_done();
			fun();
		case 4:
			mark();
			fun();
		default:
			cout<<"invalid input"<<endl;
			fun();
	}
	
	// cout<<"fun called";
}

int main()
{
	
	cout<<"This is a program to make a To-Do List"<<endl;
	fun();
	
//	inp_task();
//	view_to_do();
//	mark();
//	view_done();
//	view_to_do();
	
}
