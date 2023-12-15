#include <string>
#include <vector>
#include <algorithm>
#include <iostream> 

std::string solutionSort2(std::vector<int> numbers) {
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        std::string A = std::to_string(a);
        std::string B = std::to_string(b);
        return A + A + A + A > B + B + B+ B;
    }
    );

    std::string answer2 = "";

    for (int i = 0; i < numbers.size(); i++) {
        answer2 += std::to_string(numbers[i]);
    }

    if (answer2[0] == '0')
    {
        return "0";
    }
    std::cout << '0' << std::endl;
    std::cout << "012314123" << std::endl;
    return answer2;
}

