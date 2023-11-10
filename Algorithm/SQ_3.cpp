#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	int temp;
	for (int i = 0; i < progresses.size(); i++) {
		temp = ceil(static_cast<double>(100 - progresses[i]) / speeds[i]);
		q.push(temp);
	}
	int cur = 0;
	cur = q.front();
	q.pop();
	int cnt = 1;
	for (int i = 1; i < speeds.size(); i++) {
		if (q.front() > cur) {
			answer.push_back(cnt);
			cnt = 1;
			cur = q.front();
			q.pop();
		}
		else {
			cnt += 1;
			q.pop();
		}
	}
	if (cnt != 0) {
		answer.push_back(cnt);
	}
	return answer;
}

//int main() {
//	vector<int> progresses = { 93,30,55 };
//	vector<int> speeds = { 1,30,5 };
//	vector<int> answer = solution(progresses, speeds);
//	for (int i = 0; i < answer.size(); i++) {
//		cout << answer[i] << " " << endl;
//	}
//	
//	return 0;
//}