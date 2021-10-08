#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{	
	int N;
	cin >> N;
	int test5 = N / 5;
	int test3;
	while (1)
	{
		if (test5 < 0)
		{
			cout << -1 << endl;
			return 0;
		}

		if ((N - (test5 * 5)) % 3 == 0)
		{
			test3 = (N - (test5 * 5)) / 3;
			break;
		}
		test5--;
	}

	cout << test3 + test5 << endl;
	return 0;
}