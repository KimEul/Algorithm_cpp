#include <iostream>
#include <string>
#include <vector>
#include<iomanip>

using namespace std;

bool isValid(char c)
{
    if (isalnum(c)) return true;
    if (c == '-' || c == '_' || c == '.') return true;

    return false;
}

string solution(string new_id) {
    string answer = "";

    bool lastDot = false;
    for (char ch : new_id)
    {
        if (isValid(ch) == false) continue;
        if (ch == '.')
        {
            if (answer.length() == 0 || lastDot) continue;
            lastDot = true;
        }
        else
        {
            lastDot = false;
        }

        ch = tolower(ch);
        answer.push_back(ch);
    }

    if (answer.length() >= 16)
        answer.resize(15);
    if (answer.length() == 0)
        answer.push_back('a');
    if (answer.back() == '.')
        answer.pop_back();

    if (answer.length() <= 2)
    {
        char ch = answer.back();
        while (answer.length() < 3)
        {
            answer.push_back(ch);
        }
    }

    return answer;
}

int main()
{
    vector<string> input{ "...!@BaT#  * ..y.abcdefghijklm","z-+.^.","=.=","123_.def","abcdefghijklmn.p" };
    vector<string> tc = input;

    vector<string> result{ "bat.y.abcdefghi" ,"z--" ,"aaa" ,"123_.def" ,"abcdefghijklmn" };
    vector<string> ans = result;

    for (int i = 0; i < 5; i++)
    {
        cout << "입력값 : " << input.at(i) << endl;
        cout << "변환값 : " << solution(input.at(i)) << endl;
        cout << "기댓값 : " << ans.at(i) << endl;
        if (solution(input.at(i)) == ans.at(i)) cout << "일치" << endl;
        else cout << "불일치" << endl;
        cout << endl;
    }

    return 0;
}