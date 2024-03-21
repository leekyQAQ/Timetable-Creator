#include<iostream>
#include"event.h"
#include"timeTable.h"
using namespace std;

int main()
{
	vector<int> ID{ 123,234,345 };
	event event1(1, "event1", ID);
	event event2(2, "EVENT2", 9.30, 11.30, 1, ID);
	event event3(3, "EVENT3", 3.23, 5.20, 1, ID);
	event event4(4, "EVENT4", 10.00, 23.00, 2, ID);
	event event5(5, "EVENT5", 9.30, 11.30, 2, ID);
	timeTable test(vector<event>{ event2, event3, event4,event5});
	cout<<test.timeConfilctCheck();


}