#include <format>
#include <iostream>
#include <stack>
#include <string>

class Solution {
  public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
                continue;
            }
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (stack.empty()) {
                    return false;
                }
                auto top = stack.top();
                if ((s[i] == ')' && s[i] != top + 1) ||
                    (s[i] != ')' && s[i] != top + 2)) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    std::string input = "({{{{}}}))";

    std::cout << std::format("Input: {}\n", input);

    bool isValid = solution.isValid(std::move(input));

    std::cout << std::format("Output: {}\n", isValid);

    return 0;
}
