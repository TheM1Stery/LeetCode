#include <climits>
#include <cmath>
#include <format>
#include <iostream>

class Solution {
  public:
    int reverse(int x) {
        long answer = 0;
        bool negative = x < 0;
        long num = x;
        if (negative){
            num *= -1;
        }
        double number_of_digits = floor(log10(num) + 1);
        long pow = std::pow(10, number_of_digits - 1);
        while(number_of_digits > 0){
            int digit = num % 10;
            std::cout << digit << '\n';
            answer += digit * pow;
            number_of_digits--;
            pow /= 10;
            num /= 10;
        }
        answer *= negative ? -1 : 1;
        if (answer < INT_MIN) {
            answer = 0;
        } else if (answer > INT_MAX) {
            answer = 0;
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int input;
    std::cin >> input;
    std::cout << std::format("Input: {}", input) << std::endl;
    auto answer = s.reverse(input);
    std::cout << std::format("Answer: {}", answer) << std::endl;
}
