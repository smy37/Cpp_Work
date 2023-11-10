#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	int cri = nums.size() / 2;
	map<int, int> m;
	for (auto i : nums)
	{
		if (m.find(i) == m.end())
		{
			m[i] = 1;
		}
	}
	answer = min(cri, (int)m.size());
	return answer;
}

int main()
{
	vector<int> nums = { 3,1,2,3 };
	cout << solution(nums);
	return 0;
}