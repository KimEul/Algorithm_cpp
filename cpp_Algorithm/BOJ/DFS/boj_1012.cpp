#include <iostream>
#include <vector>

using namespace std;

#define MAX_LEN 50
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
int arr[MAX_LEN][MAX_LEN] = { 0, };
int visit[MAX_LEN][MAX_LEN] = { 0, };
int result = 0;
int xside;
int yside;
vector<int> total_result;


void dfs(int x, int y)
{

	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= xside || ny < 0 || ny >= yside) continue;
		if (arr[nx][ny] == 1 && visit[nx][ny] == false)
			dfs(nx, ny);
	}
}

void initialize()
{
	for (int i = 0; i < xside; i++)
		for (int k = 0; k < yside; k++)
		{
			arr[i][k] = false;
			visit[i][k] = false;
		}
	result = 0;
}

int main()
{
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{

		int chu_num;
		cin >> xside >> yside >> chu_num;
		for (int k = 0; k < chu_num; k++)
		{
			int arr_x;
			int arr_y;
			cin >> arr_x >> arr_y;
			arr[arr_x][arr_y] = 1;
		}
		for (int a = 0; a < xside; a++)
		{
			for (int b = 0; b < yside; b++)
			{
				if (visit[a][b] == false && arr[a][b] == 1)
				{
					dfs(a, b);
					result++;

				}
			}
		}

		total_result.push_back(result);
		initialize();

	}
	for (int i = 0; i < total_result.size(); i++)
	{
		cout << total_result[i] << endl;
	}
}