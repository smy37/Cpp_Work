#include <string>
#include <vector>
#include <iostream>
#include <stack>


using namespace std;

vector<int> solution8(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<vector<int>> s;
    vector<vector<int>> new_p;
    for (int i = 0; i < prices.size(); i++) {
        new_p.push_back({ prices[i],i });
    }
    s.push(new_p[0]);
    for (int i = 1; i < new_p.size(); i++) {
        while (s.size() > 0) {
            if (s.top()[0] > new_p[i][0]) { // 가격이 떨어지는 케이스
                answer[s.top()[1]] = i - s.top()[1];
                s.pop();
            }
            else {
                s.push(new_p[i]);
                break;
            }
        }
        if (s.size() == 0) {
            s.push(new_p[i]);
        }
    }
    while (s.size() > 0) {
        answer[s.top()[1]] = new_p[new_p.size() - 1][1] - s.top()[1];
        s.pop();
    }
    return answer;
}

//int main() {
//
//    vector<int> prices = { 1, 2, 3, 2, 3 };
//    vector<int> ans = solution8(prices);
//    cout << "Answer: ";
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << ", ";
//    }
//    cout << endl;
//
//    return 0;
//}