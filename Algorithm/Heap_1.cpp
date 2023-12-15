//[1, 2, 3, 9, 10, 12]	7	2

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int solution_hq1(vector<int> scoville, int K) {
    int answer = 0;
    int t1;
    int t2;
    priority_queue<int, vector<int>, greater<int>> hq;
    for (int i = 0; i < scoville.size(); i++) {
        hq.push(scoville[i]);
    }
    while (hq.top() < K) {
        if (hq.size() == 1) {
            return -1;
        }
        t1 = hq.top();
        hq.pop();
        t2 = hq.top();
        hq.pop();
        int new_s = t1 + 2 * t2;
        hq.push(new_s);
        answer += 1;
    }
    return answer;
}

//int main() {
//    vector<int> scovile = { 1, 2, 3, 9, 10, 12 };
//    int K = 7;
//    int answer = solution_hq1(scovile, K);
//    cout << answer << endl;
//    return 0;
//}