#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    stack<int> s;
    int temp;
    for (int i = 0; i < arr.size(); i++) {
        if (!s.empty()) {
            temp = s.top();
            if (temp == arr[i]){
                continue;
            }
            else {
                s.push(arr[i]);
                answer.push_back(arr[i]);
            }
        }
        else {
            s.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }
    return answer;
}
