#include <string>
#include <vector>
#include <algorithm>

int solutionSort3(std::vector<int> cite) {
    std::sort(cite.begin(), cite.end(), [](int a, int b) {
        return a < b;
    });
    int answer = 0;
    int cri = 0;
    for (int i = 0; i < cite.size(); i++)
    {
        cri = cite.size() - i;
        if (cri >= cite[i])
        {
            answer = cite[i];
        }
        else { 
            answer = std::max(answer, cri);
            break;
        }
    }

    return answer;
}