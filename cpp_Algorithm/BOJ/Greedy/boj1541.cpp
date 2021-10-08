#include <iostream>

using namespace std;

bool flag;
int temp;
int sum = 0;

int main()
{
	string expr;
	cin >> expr;

	for (int i = 0; i <= expr.size(); i++)
	{
		if (expr[i] == '-' || expr[i] == '+' || i== expr.size())
		{
			if (flag == false)
			{
				sum += temp;
				temp = 0;
			}
			else 
			{
				sum -= temp;
				temp = 0;
			}

			if (expr[i] == '-') flag = true;

		}
		else
		{
			temp *= 10;
			temp += expr[i] - '0';
		}
	}
	cout << sum << endl;

}