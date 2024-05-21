/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0, sum;
    struct ListNode* output = malloc(sizeof(struct ListNode));
    struct ListNode* current = output;
    while (l1 != NULL || l2 != NULL || carry !=0){
        int val1 = (l1 == NULL) ? 0 : l1->val;
        int val2 = (l2 == NULL) ? 0 : l2->val;
        sum = val1 + val2 + carry;
        carry = sum / 10;

        struct ListNode* temp = malloc(sizeof(struct ListNode));
        temp->val = sum % 10;
        
        current->next = temp;
        current = temp;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    current->next = NULL;
    output = output->next;
    return output;
}
