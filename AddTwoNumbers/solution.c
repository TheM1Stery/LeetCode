#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *create_node(int val) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void rememberIfHigherThan10(int* num, int* remember){
    if (*num >= 10){
        *remember = 1;
        *num -= 10;
    }else {
        *remember = 0;
    }
}


struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int remember = 0;
    struct ListNode *l1_curr = l1;
    struct ListNode *l2_curr = l2;
    struct ListNode *answer_list = NULL;
    struct ListNode* answer_curr = answer_list;
    int sum = 0;
    while (l1_curr != NULL && l2_curr != NULL) {
        sum = l1_curr->val + l2_curr->val + remember;
        rememberIfHigherThan10(&sum, &remember);
        l1_curr = l1_curr->next;
        l2_curr = l2_curr->next;
        if (answer_list == NULL){
            answer_list = create_node(sum);
            answer_curr = answer_list;
            continue;
        }
        answer_curr->next = create_node(sum);
        answer_curr = answer_curr->next;
    }

    while (l1_curr != NULL) {
        sum = l1_curr->val + remember;
        rememberIfHigherThan10(&sum, &remember);
        l1_curr = l1_curr->next;
        answer_curr->next = create_node(sum);
        answer_curr = answer_curr->next;
    }

    while (l2_curr != NULL) {
        sum = l2_curr->val + remember;
        rememberIfHigherThan10(&sum, &remember);
        l2_curr = l2_curr->next;
        answer_curr->next = create_node(sum);
        answer_curr = answer_curr->next;
    }

    if (remember > 0){
        answer_curr->next= create_node(remember);
    }

    return answer_list;
}

struct ListNode *createLL(int array[], int length) {
    struct ListNode *head = create_node(array[0]);
    struct ListNode *curr = head;
    for (int i = 1; i < length; i++) {
        curr->next = create_node(array[i]);
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}

void printLL(struct ListNode *ll) {
    printf("%d", ll->val);
    if (ll->next)
        printf("->");
    else {
        printf("\n");
        return;
    }
    return printLL(ll->next);
}

int main() {
    int first[] = {9,9,9,9,9,9,9};
    int second[] = {9,9,9,9};
    struct ListNode *f_head = createLL(first, sizeof(first)/sizeof(first[0]));
    struct ListNode *s_head = createLL(second, sizeof(second)/sizeof(second[0]));
    printLL(f_head);
    printLL(s_head);
    struct ListNode *answer = addTwoNumbers(f_head, s_head);
    printLL(answer);
}
