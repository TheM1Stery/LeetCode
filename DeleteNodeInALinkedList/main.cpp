#include <iostream>
#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *create_node(int val) {
    struct ListNode *node = new ListNode(val);
    return node;
}

ListNode *createLL(std::vector<int> numbers) {
    ListNode* head = create_node(numbers[0]);
    ListNode* curr = head;
    for (int i = 1; i < numbers.size(); i++){
        curr->next = create_node(numbers[i]);
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}



class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};


int main(){
    auto numbers = std::vector<int>{4,5,1,9};
    Solution solution;
    auto ll = createLL(numbers);
    std::cout << ll->next->val << '\n';
    solution.deleteNode(ll);
    std::cout << ll->next->val << '\n';
}
