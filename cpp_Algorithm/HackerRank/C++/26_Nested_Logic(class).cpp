#include <bits/stdc++.h>

using namespace std;

class Book 
{
private:
	int day;
	int month;
	int year;
public :
	Book(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	void Display()
	{
		cout << "day : " << day << " " << "month : " << month << " "  << "year : " << year << endl;
	}

	void calculate(int a,int b,int c)
	{
		if (year == c)
		{
			if (month == b)
			{
				cout << 15 * (day - a) << endl;
			}
			else cout << 500 * (month - b) << endl;
		}
		else cout << "10000" << endl;
	}
};

int main()
{
	int day_returned,day_expected;
	int month_returned,month_expected;
	int year_returned,year_expected;
	cin >> day_returned >> month_returned >> year_returned;
	Book Book_returned(day_returned, month_returned, year_returned);
	cin >> day_expected >> month_expected >> year_expected;
	Book Book_expected(day_expected, month_expected, year_expected);
	Book* Book1 = new Book(1, 2, 3);

	Book_returned.Display();
	Book_expected.Display();


	Book_returned->calculate();
}