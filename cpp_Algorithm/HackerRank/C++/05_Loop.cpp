#include <bits/stdc++.h>
using namespace std;


int main() 
{
    vector <string> vec;
    string s;
    string s1;
    string s2;
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> s;


        for (int k = 0; k < s.size(); ++k)
        {
            if (k % 2 == 0)
            {
                s1 += s[k];
            }
            else
            {
                s2 += s[k];
            }
        }

        vec.push_back(s1);
        vec.push_back(s2);
        s1.clear();
        s2.clear();
    }
    for (int i = 0; i < 2 * T; ++i)
    {
        cout << vec[i] << " " ;
        if (i % 2 !=0)
        {
            cout << endl;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
},

