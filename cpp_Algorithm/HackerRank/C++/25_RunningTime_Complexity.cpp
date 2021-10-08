//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//int main() {
//    int count;
//    cin >> count;
//    while (count > 0) {
//        int n;
//        cin >> n;
//        string output = "";
//        if (n == 1 || n == 2) {
//            output = n == 1 ? "Not prime" : "Prime";
//            cout << output << "\n";
//            --count;
//            continue;
//        }
//        else if (n % 2 == 0) {
//            cout << "Not prime\n";
//            --count;
//            continue;
//        }
//        int i = 3;
//        for (; i * i <= n; i += 2) {
//            if (n % i == 0) {
//                output = "Not prime";
//                //break;
//            }
//        }
//        if (output.compare("Not prime") != 0) {
//            output = "Prime";
//        }
//        cout << output << "\n";
//        --count;
//    }
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

void prime(int num)
{
	string result;
	int count = 0;
	if (num == 1 || num ==2)
	{
		result = num == 1 ? "Not prime" : "Prime";
		cout << result << endl;
	}
	else if (num % 2 == 0)
	{
		cout << "Not prime" << endl;
	}
	else
	{
		for (int i = 3; i*i < num; i += 2)
		{
			if (num % i == 0)
			{
				result = "Not Prime";
				cout << "Not Prime" << endl;
				break;
			}
		}
		if (result != "Not Prime")
		{
			cout << "Prime" << endl;
		}
	}
}

int main() 
{
	int T;
	cin >> T;
	int number;
	while (T)
	{
		cin >> number;
		prime(number);
		T--;
	}
}