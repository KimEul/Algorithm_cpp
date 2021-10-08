#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LEN 25

typedef vector<vector<int>> v2;
typedef vector<int> v1;

vector<vector<int>> arr(MAX_LEN, vector<int>(MAX_LEN, 0));
int visit[MAX_LEN][MAX_LEN];

//int node[MAX_LEN][MAX_LEN];
//int visit[MAX_LEN][MAX_LEN];
int Number;
int house_cnt = 0;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };

vector<int>result;

void dfs(int x, int y)
{
	house_cnt++;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= Number || ny < 0 || ny >= Number) continue;
		if (arr.at(nx).at(ny) == 1 && visit[nx][ny] == false)
			dfs(nx, ny);

	}
}

int main()
{
	string str;
	cin >> Number;
	for (int i = 0; i < Number; i++)
	{
		cin >> str;
		for (int k = 0; k < Number; k++)
		{
			arr[i][k] = str[k] - '0';
		}
	}

	for (int i = 0; i < Number; i++)
		for (int k = 0; k < Number; k++)
		{
			if (arr.at(i).at(k) == 1 && visit[i][k] == false)
			{
				house_cnt = 0;
				dfs(i, k);
				result.push_back(house_cnt);
			}
		}

	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result.at(i) << endl;
	}
	return 0;
}