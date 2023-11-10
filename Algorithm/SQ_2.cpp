#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> sk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') {
            sk.push(s[i]);
        }
        else if (s[i] == ')') {
            if (sk.empty()) {
                return false;
            }
            if (sk.top() == '(') {
                sk.pop();
            }
            else if (sk.top() == ')') {
                return false;
            }
        }
    }
    if (sk.empty()) answer = true;
    else answer = false;
    return answer;
}

