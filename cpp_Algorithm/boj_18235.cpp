#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
    int curLoc, day, jump;
};
int arr[500001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int len, a, b, result = -1;
    cin >> len >> a >> b;
    queue<info> q;
    q.push({ a,0,0 });
    q.push({ b,0,0 });
    while (!q.empty()) {
        int cc = q.front().curLoc;
        int cd = q.front().day;
        int cj = q.front().jump;
        q.pop();
        int dist = cj == 0 ? 1 : cj * 2;
        int next = cc + dist;
        if (next <= len) {        //우측 이동
            if (arr[next] == cd + 1) {
                result = cd + 1;
                break;
            }
            else {
                arr[next] = cd + 1;
                q.push({ next,cd + 1,dist });
            }
        }
        next = cc - dist;
        if (next > 0) {        //좌측 이동
            if (arr[next] == cd + 1) {
                result = cd + 1;
                break;
            }
            else {
                arr[next] = cd + 1;
                q.push({ next,cd + 1,dist });
            }
        }
    }
    cout << result;
    return 0;
}