#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LEN 100
int arr[MAX_LEN][MAX_LEN];
bool visit[MAX_LEN][MAX_LEN];
int M, N, K;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int cnt;

void dfs(int y, int x)
{
	cnt++;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
		//if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		//{
		if (!visit[ny][nx] && arr[ny][nx] == 0)
		{
			dfs(ny, nx);
		}
		//}
	}

}

int main()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int yy = y1; yy < y2; yy++)
		{
			for (int xx = x1; xx < x2; xx++)
			{
				arr[yy][xx] = 1;
			}
		}
	}

	vector<int> result;

	for (int i = 0; i < M; i++)
	{
		for (int k = 0; k < N; k++)
		{
			if (!visit[i][k] && arr[i][k] == 0)
			{
				cnt = 0;
				dfs(i, k);
				result.push_back(cnt);

			}
		}
	}

	cout << result.size() << endl;

	int result_size = result.size();
	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}