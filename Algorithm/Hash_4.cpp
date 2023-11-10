#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> mClothNum;
	for (int i = 0; i < clothes.size(); i++) {
		if (mClothNum.find(clothes[i][1]) == mClothNum.end()) {
			mClothNum[clothes[i][1]] = 1;
		}
		else {
			mClothNum[clothes[i][1]] += 1;
		}
	}
	for (const auto& key : mClothNum) {
		answer *= (key.second + 1);
	}
	answer -= 1;
	return answer;
}
//
//int main() {
//	vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };
//	solution(clothes);
//}