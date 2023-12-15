#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> solution(vector <int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> s_vec;
	int s, e, idx;
	for (int i = 0; i < commands.size(); i++) {
		s = commands[i][0]-1;
		e = commands[i][1];
		idx = commands[i][2]-1;
		for (int j = s; j < e; j++)
		{
			s_vec.push_back(array[j]);
		}
		sort(s_vec.begin(), s_vec.end(), [](const auto& a, const auto& b) {return a < b; });
		answer.push_back(s_vec[idx]);
		s_vec.clear();
	}
	return answer;
}


//int main() {
//    // 테스트할 배열
//    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
//
//    // 테스트할 명령어들
//    vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };
//
//    // 결과를 계산
//    vector<int> result = solution(array, commands);
//
//    // 결과 출력
//    cout << "Result: ";
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}