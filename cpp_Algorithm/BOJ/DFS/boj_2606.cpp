#include <iostream>
#include <vector>

using namespace std;

#define MAX_LEN 100

int arr[MAX_LEN][MAX_LEN] = { 0, };
bool visit[MAX_LEN];
int Number;
int paired;
int result = 0;

void dfs(int x)
{

	visit[x] = true;
	for (int i = 1; i <= Number; i++)
	{
		if (visit[i] == false && arr[x][i] == 1)
		{
			result++;
			dfs(i);
		}
	}
}
int main()
{

	cin >> Number;
	cin >> paired;
	for (int i = 0; i < paired; i++)
	{
		int x, y;
		cin >> x >> y;

		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	dfs(1);
	cout << result << endl;
	return 0;
}