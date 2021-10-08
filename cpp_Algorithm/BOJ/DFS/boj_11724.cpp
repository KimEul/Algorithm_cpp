#include <iostream>
#include <vector>



using namespace std;

int vertex;
int line;
int result = 0;
#define MAX_LEN 1001

int map[MAX_LEN][MAX_LEN] = { 0, };
bool visit[MAX_LEN] = { 0, };

void dfs(int start)
{
	visit[start] = true;
	for (int i = 1; i <= vertex; i++)
	{
		if (!visit[i] && map[start][i]) dfs(i);
	}
}

int main()
{

	cin >> vertex >> line;
	for (int i = 0; i < line; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	for (int i = 1; i <= vertex; i++)
	{
		if (!visit[i])
		{
			dfs(i);
			result++;
		}
	}

	cout << result << endl;
}