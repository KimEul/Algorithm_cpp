#include <bits/stdc++.h>

using namespace std;



int main()
{
    int maximum=0;
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) 
    {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            int temp=0;
            // °¡·Î µ¡¼À
            temp += arr[i][k];
            temp += arr[i][k+1];
            temp += arr[i][k+2];
            //Áß¾Ó
            temp += arr[i+1][k+1];
            // ¼¼·Î µ¡¼À
            temp += arr[i+2][k];
            temp += arr[i+2][k+1];
            temp += arr[i+2][k+2];

            if (temp > maximum || maximum == 0)
            {
                maximum = temp;
            }

        }

    }

    cout << maximum << endl;
 
    return 0;
}

// 00 01 02
//    11
// 20 21 22

// 00 01 02 03 04 05
// 10 11 12 13 14 15
// 20 21 22 23 24 25
// 30 31 32 33 34 35
// 40 41 42 43 44 45
// 50 51 52 53 54 55