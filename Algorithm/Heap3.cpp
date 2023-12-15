#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    //vector<int> answer;
    //priority_queue<int> maxHeap;
    //priority_queue<int, vector<int>, greater<int>> minHeap;
    //int cnt = 0;
    //
    //for (int i = 0; i < operations.size(); i++) {
    //    size_t blankPos = operations[i].find(' ');
    //    string cmd = operations[i].substr(0, blankPos);
    //    int num = stoi(operations[i].substr(blankPos + 1));
    //    if (cnt == 0) {
    //        while (!minHeap.empty()) minHeap.pop();
    //        while (!maxHeap.empty()) maxHeap.pop();
    //    }
    //    if (cmd == "I") {
    //        maxHeap.push(num);
    //        minHeap.push(num);
    //        cnt += 1; 
    //    }
    //    else if (cmd == "D") {
    //        if (num == -1) {
    //            if (minHeap.size() > 0) {
    //                minHeap.pop();
    //                cnt -= 1;
    //            }
    //        }
    //        else if (num == 1) {
    //            if (maxHeap.size() > 0) {
    //                maxHeap.pop();
    //                cnt -= 1;
    //            }
    //        }
    //    }
    //}
    //if (cnt == 0)
    //{
    //    answer.push_back(0);
    //    answer.push_back(0);
    //}
    //else
    //{
    //    answer.push_back(minHeap.top());
    //    answer.push_back(maxHeap.top());
    //}

    //return answer;
    ////////////////////////////////////////////////////////////////////////

    vector<int> answer;
    multiset<int> multiSet;
   
    
    for (int i = 0; i < operations.size(); i++) {
        size_t blankPos = operations[i].find(' ');
        string cmd = operations[i].substr(0, blankPos);
        int num = stoi(operations[i].substr(blankPos + 1));
    
        if (cmd == "I") {
            multiSet.insert(num);
        }
        else if (cmd == "D") {
            if (num == -1) {
                if (!multiSet.empty()) {
                    multiSet.erase(multiSet.begin());
                }
            }
            else if (num == 1) {
                if (!multiSet.empty()) {
                    multiSet.erase(--multiSet.end());
                }
            }
        }
    }
    if (multiSet.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*multiSet.begin());
        answer.push_back(*--multiSet.end());
    }

    return answer;
}

//int main() {
//    std::vector<int> ans;
//    ans = solution({ "I 1", "I 3", "I 5", "I 7", "D 1", "D 1", "I 6", "D -1", "D -1" });
//    /*ans = solution({ "I 1", "I 3", "I 5", "I 7", "I 9", "D -1", "D -1", "D 1", "I 2", "D 1", "D 1" });*/
//    for (int i = 0; i < ans.size(); i++) {
//        std::cout << ans[i] << std::endl;
//    }
//}