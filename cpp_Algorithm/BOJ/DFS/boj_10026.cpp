#include <iostream>

using namespace std;

#define MAX_LEN 100
char arr[MAX_LEN][MAX_LEN];
bool visit[MAX_LEN][MAX_LEN];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N;
int cnt_NoRG = 0;
int cnt_RG = 0;

void dfs_NoRG(int x, int y, char color)
{
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (!visit[nx][ny] && arr[nx][ny] == color)
			{
				dfs_NoRG(nx, ny, color);
			}
		}
	}
}

void dfs_RG(int x, int y, char color)
{
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (!visit[nx][ny] && arr[nx][ny] == color)
			{
				dfs_RG(nx, ny, color);
			}
		}

	}
}

void setting()
{
	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++)
		{
			if (arr[i][k] == 'R' || arr[i][k] == 'G') arr[i][k] = 'G';
			visit[i][k] = false;
		}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str_temp;
		cin >> str_temp;
		for (int k = 0; k < N; k++)
		{
			arr[i][k] = str_temp[k];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			if (!visit[i][k])
			{
				dfs_NoRG(i, k, arr[i][k]);
				cnt_NoRG++;
			}
		}
	}
	setting();
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			if (!visit[i][k])
			{
				dfs_RG(i, k, arr[i][k]);
				cnt_RG++;
			}
		}
	}

	cout << cnt_NoRG << " " << cnt_RG;

}