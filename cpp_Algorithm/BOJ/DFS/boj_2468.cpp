#include <iostream>
#include <cstring>

using namespace std;


#define MAX_SIZE 100
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int arr[MAX_SIZE][MAX_SIZE] = { 0, };
int temp[MAX_SIZE][MAX_SIZE] = { 0, };
bool visit[MAX_SIZE][MAX_SIZE] = { 0, };

int N;

void dfs(int x, int y)
{
    visit[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= MAX_SIZE || ny >= MAX_SIZE) continue;
        if (!visit[nx][ny] && temp[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

void copy(int depth)
{
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++)
        {
            if (arr[i][k] > depth) temp[i][k] = 1;
        }
}

void Oninit()
{
    memset(visit, false, sizeof(visit));
    memset(temp, 0, sizeof(temp));
}

int main()
{
    int height;
    int count = 1;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            cin >> arr[i][k];
        }
    }

    for (int j = 1; j <= 100; j++)
    {
        Oninit();
        copy(j);
        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            for (int k = 0; k < N; k++)
            {
                if (!visit[i][k] && temp[i][k])
                {
                    dfs(i, k);
                    cnt++;
                }
            }
        }

        count = max(count, cnt);

    }

    cout << count << endl;
}