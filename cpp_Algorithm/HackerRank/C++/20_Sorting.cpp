#include <bits/stdc++.h>

using namespace std;

void Bubblesort(vector<int> &A)
{
    int numberofswap = 0;
    for (int i = 0; i < A.size(); ++i)
    {  
        for (int j = 0; j < A.size() - 1; ++j)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                numberofswap++;
            }
        }
        if (numberofswap == 0)
        {
            break;
        }

    }
    cout << "Array is sorted in " << numberofswap << " swaps." << endl;
    cout << "First Element: " <<  A[0] << endl;
    cout << "Last Element: "<< A[A.size() - 1] << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int result=0;
    for (int a_i = 0; a_i < n; a_i++) 
    {
        cin >> a[a_i];
    }
    // Write Your Code Here
    Bubblesort(a);
    return 0;
}