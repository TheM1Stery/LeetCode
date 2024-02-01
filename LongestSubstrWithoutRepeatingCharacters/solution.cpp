#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <format>


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> map;
        int max_length = 0;
        int window_start = 0;
        for (int i = 0; i < s.length(); i++){
            auto find = map.find(s[i]);
            if (find != map.end() && find->second >= window_start){
                window_start = find->second + 1;
            }
            map[s[i]] = i;
            max_length = std::max(i - window_start + 1, max_length);
        }
        return max_length;
    }
};

int main (int argc, char *argv[]) {
    Solution sol;
    std::string input = "dvdfv";
    std::cout << std::format("Input: {}\n", input);
    std::cout << std::format("Answer: {}\n", sol.lengthOfLongestSubstring(std::move(input)));
    return 0;
}
