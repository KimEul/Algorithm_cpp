#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
int m;
int v;
int vertex[1001][1001];
bool visit[1001];
queue<int> q;

void dfs(int start)
{
	cout << start << " ";
	visit[start] = true;
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i] && vertex[start][i])
		{
			dfs(i);
		}
	}
}

void bfs(int start)
{
	visit[start] = true;
	q.push(start);
	while (!q.empty())
	{
		start = q.front();
		q.pop();

		cout << start << " ";
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i] && vertex[start][i])
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}
	
}

int main()
{
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++)
	{
		int x;
		int y;
		cin >> x >> y;
		vertex[x][y] = 1;
		vertex[y][x] = 1;
	}
	dfs(v);
	cout << endl;
	memset(visit, false, sizeof(visit));
	bfs(v);
}