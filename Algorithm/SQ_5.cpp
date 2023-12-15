#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int cur_w = 0;
	int cur_t = 0;
	queue<int> q_1;
	queue<vector<int>> q_2;
	
	for (int i = 0; i < truck_weights.size(); i++) {
		q_1.push(truck_weights[i]);
	}
	
	while (q_1.size() > 0) {
		if (q_2.size() == 0) {
			cur_t += 1;
			int t = q_1.front();
			q_1.pop();
			cur_w += t;
			vector<int> temp = {t, cur_t + bridge_length};
			q_2.push(temp);
		}
		else {
			int t = q_1.front();
			if (cur_w + t > weight) {
				vector<int> temp2 = q_2.front();
				cur_t = temp2[1];
				cur_w -= temp2[0];
				q_2.pop();
				if (cur_w + t > weight) {
					continue;
				}
				else {
					q_1.pop();
					cur_w += t;
					vector<int> temp = { t, cur_t + bridge_length };
					q_2.push(temp);
				}
			}
			else {
				cur_t += 1;
				q_1.pop();
				cur_w += t;
				vector<int> temp = { t, cur_t + bridge_length };
				q_2.push(temp);
				vector<int> temp2 = q_2.front();
				if (temp2[1] <= cur_t) {
					cur_w -= temp2[0];
					q_2.pop();
				}
			}
		}
	}
	while (q_2.size() > 0) {
		answer = q_2.front()[1];
		q_2.pop();
	}
	return answer;
}