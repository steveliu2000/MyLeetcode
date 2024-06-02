/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* current = head,* pre_target = head;
    n++;
    while (current != NULL) {
        current = current->next;
        if (n == 0) pre_target = pre_target->next;
        else n--;
    }
    if (n > 0) { // remove head
        head = head->next;
        free(pre_target);
        return head;
    }
    struct ListNode* target = pre_target->next;
    pre_target->next = target->next;
    free(target);
    return head;
}
