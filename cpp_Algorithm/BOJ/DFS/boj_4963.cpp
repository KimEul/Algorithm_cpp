#include <iostream>
#include <vector>

using namespace std;

#define MAX_LEN 50

int arr[MAX_LEN][MAX_LEN] = { 0, };
bool visit[MAX_LEN][MAX_LEN] = { 0, };
int width;
int height = 0;
int result;

int dx[8] = { -1,-1,1,1,1,0,0,-1 };
int dy[8] = { 1,-1,1,-1,0,-1,1,0 };

void dfs(int x, int y)
{
	visit[x][y] = true;
	for (int i = 0; i < 8; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= MAX_LEN || ny >= MAX_LEN) continue;
		if (arr[nx][ny] && !visit[nx][ny])
		{
			dfs(nx, ny);
		}
	}
}

void initialize()
{
	for (int i = 0; i < MAX_LEN; i++)
		for (int k = 0; k < MAX_LEN; k++)
		{
			arr[i][k] = 0;
			visit[i][k] = 0;
		}
	result = 0;
}

int main()
{
	while (1)
	{
		cin >> height >> width;
		if (width == 0 && height == 0) break;
		for (int i = 0; i < width; ++i)
		{
			for (int k = 0; k < height; ++k)
			{
				cin >> arr[i][k];
			}
		}

		for (int i = 0; i < width; ++i)
		{
			for (int k = 0; k < height; ++k)
			{
				if (!visit[i][k] && arr[i][k])
				{
					result++;
					dfs(i, k);
				}

			}
		}
		cout << result << endl;
		initialize();
	}
	return 0;
}