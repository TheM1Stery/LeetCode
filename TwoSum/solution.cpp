#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
       auto map = std::unordered_map<int, int>();
       for(int i = 0; i < nums.size(); i++){
           int diff = target - nums[i];
           auto search = map.find(diff);
           if (search != map.end()){
               return {i, search->second};
           }
           map[nums[i]] = i;
       }
       return {0,0};
    }
};

int main (int argc, char *argv[]) {
    Solution sol;
    std::vector<int> vec{2, 7,11, 15};
    for (auto& val : sol.twoSum(vec, 26)) {
        std::cout << val << '\n';
    }
    return 0;
}
