#include <iostream>

using namespace std;

#define MAX_LEN 20

int ans = 0;
int R;
int C;
char arr[MAX_LEN][MAX_LEN];
bool visit[26] = { 0, };

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void dfs(int x, int y, int cnt)
{
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if (!visit[arr[nx][ny] - 'A'])
		{
			visit[arr[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			visit[arr[nx][ny] - 'A'] = false;
		}
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int k = 0; k < C; k++)
		{
			cin >> arr[i][k];
		}

	visit[(arr[0][0] - 'A')] = 1;
	dfs(0, 0, 1);
	cout << ans << endl;
}