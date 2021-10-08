#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
private:
    vector<int> elements;

public:
    int maximumDifference; 
    Difference(vector <int> elem)
    {
        elements = elem;
    }
    int computeDifference()
    {
        for (int i = 0; i < elements.size()-1; ++i)
            for (int k = 1; k < elements.size(); ++k)
            {
                int temp = abs(elements[i] - elements[k]);
                    if (temp > maximumDifference || k==1)
                    {
                        maximumDifference = temp;
                    }
            }
        return maximumDifference;
    }


    // Add your code here

}; // End of Difference class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}