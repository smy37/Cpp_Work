#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> m;
    for (int i = 0; i < phone_book.size(); i++)
    {
        m[phone_book[i]] = 1;
    }
    for (int i = 0; i < phone_book.size(); i++)
    {
        string temp = "";
        int idx;
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            temp += phone_book[i][j];
            if (m.find(temp) != m.end() && temp != phone_book[i])
            {
                cout << "test, "<< temp  << endl;
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}

//int main()
//{
//    vector<string> phone_book = { "123", "456", "789" };
//	cout << solution(phone_book);
//}