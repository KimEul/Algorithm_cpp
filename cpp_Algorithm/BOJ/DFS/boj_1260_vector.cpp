#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> vertex(1001);
vector<bool> visit = { false, };



void dfs(int start)
{
	visit[start] = true;
	cout << start << " ";
	for (auto node : vertex[start])
	{
		if (!visit[node])
		{
			dfs(node);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	visit[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int x = q.front();
		cout << x << " ";
		q.pop();
		for (auto node : vertex[x])
		{
			if (!visit[node])
			{
				q.push(node);
				visit[node] = true;
			}
		}
	}
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		vertex[x].push_back(y);
		vertex[y].push_back(x);
	}
	dfs(v);
	cout << endl;
	visit.resize(visit.size(), false);
	bfs(v);
}