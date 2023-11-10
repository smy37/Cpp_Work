#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    for (int i = 0; i < completion.size(); i++) {
        if (m.find(completion[i]) == m.end()) {
            m[completion[i]] = 1;
		}
		else {
			m[completion[i]] += 1;
        }
    }
    for (int i = 0; i < participant.size(); i++){
        if (m.find(participant[i]) == m.end()) {
            answer = participant[i];
            break;
        }
        else
        {
            if (m[participant[i]] > 0)
            {
                m[participant[i]] -= 1;
            }
            else
            {
                answer = participant[i];
                break;
            }
        }
    }
    return answer;
}

int main() {
    vector<string> p = { "leo", "kiki", "eden" };
    vector<string> c = { "eden", "kiki" };
    cout << solution(p, c);
    return 0;
}