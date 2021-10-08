#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int arr[26];
int cnt = 0;
int index_number;

int main()
{
	// 대소문자 구분없이 제일 많이 쓰여진 단어
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			arr[(str[i]) - '0' - 49]++;
		}
		else if (str[i] >= 65 && str[i] <= 90)
		{
			arr[str[i] - '0' - 17]++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt < arr[i])
		{
			cnt = arr[i];
			index_number = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt == arr[i] && i != index_number)
		{
			cout << "?" << endl;
			return 0;
		}
	}

	cout << char(index_number + 65);
}