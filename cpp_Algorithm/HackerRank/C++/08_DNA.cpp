#include <bits/stdc++.h>
using namespace std;


int main() {
    map <string, int> phonebook;
    int n;
    cin >> n;

    string name;
    int number;

    for (int i = 0; i < n; ++i)
    {
        cin >> name >> number;
        phonebook.insert(make_pair(name, number));
    }

    
    {
        cin >> name;
        auto itr = phonebook.find(name);
        if (itr != phonebook.end())
        {
            cout << name << "=" <<  phonebook.find(name)->second << endl;
        }
        else 
        {
            cout << "Not found" << endl;
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}