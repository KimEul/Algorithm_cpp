#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, int> map;
vector<int> List[4][3][3][3];
vector<int> ans;


vector<int> solution(vector<string> info, vector<string> query) 
{

    vector<int> answer;

    map["-"] = 0;
    map["cpp"] = 1;
    map["java"] = 2;
    map["python"] = 3;
    map["backend"] = 1;
    map["frontend"] = 2;
    map["junior"] = 1;
    map["senior"] = 2;
    map["chicken"] = 1;
    map["pizza"] = 2;

    for (auto str : info)
    {
        stringstream ss(str);
        string a, b, c, d;
        int score;
        ss >> a >> b >> c >> d >> score;
        int arr[4] = { map[a],map[b],map[c],map[d] };
        for (int i = 0; i < (1 << 4); i++)
        {
            int idx[4] = { 0 };
            for (int j = 0; j < 4; j++)
            {
                if (i & (1 << j))
                {
                    idx[j] = arr[j];
                }
            }
            List[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
        }
    }

    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            for (int c = 0; c < 3; c++)
            {
                for (int d = 0; d < 3; d++)
                {
                    sort(List[a][b][c][d].begin(), List[a][b][c][d].end());
                }
            }
        }
    }

    for (auto str : query)
    {
        stringstream ss(str);
        string a, b, c, d, temp;
        int score;
        ss >> a >> temp >> b >> temp >> c >> temp >> d >> score;
        auto& slist = List[map[a]][map[b]][map[c]][map[d]];
        vector<int>::iterator low = lower_bound(slist.begin(), slist.end(), score);

        answer.push_back(slist.end() - low);
    }
    return answer;
}

int main()
{
    vector<string> info{ "java backend junior pizza 150",
                         "python frontend senior chicken 210",
                         "python frontend senior chicken 150",
                         "cpp backend senior pizza 260",
                         "java backend junior chicken 80",
                         "python backend senior chicken 50" };

    vector<string> query{ "java and backend and junior and pizza 100",
                          "python and frontend and senior and chicken 200",
                          "cpp and - and senior and pizza 250",
                          "- and backend and senior and - 150",
                          "- and - and - and chicken 100","- and - and - and - 150" };

    ans = solution(info, query);
    for (auto a = ans.begin(); a != ans.end(); a++) 
    {
         cout << *a << " ";
    }
}