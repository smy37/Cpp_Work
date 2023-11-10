#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    /*vector<pair<int, int>> mod_p;*/
    queue<vector<int>> q;
    vector<vector<int>> mod_p;
    
    for (int i = 0; i < priorities.size(); i++) {
        vector<int> temp;
        temp.push_back(priorities[i]);
        temp.push_back(i);
        q.push(temp);
    }
    sort(priorities.begin(), priorities.end(), [](const int a, const int b) {return a > b; });
    int cur_idx = 0;

    int front = q.front()[0];
    int cur_loc = q.front()[1];
    while (true) {
        if (priorities[cur_idx] == front) {
            q.pop();
            cur_idx += 1;
            if (cur_loc == location) break;
        }
        else {
            q.pop();
            q.push({ front, cur_loc });
        }

        front = q.front()[0];
        cur_loc = q.front()[1];
        
    }
    answer = cur_idx;
    return answer;
}

//int main() {
//    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
//	int location = 0;
//	cout << solution(priorities, location) << endl;
//    return 0;
//}