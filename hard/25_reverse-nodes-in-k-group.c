/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    
    struct ListNode dummy = {-1, NULL}, *current = &dummy;
    struct ListNode *ptr, *temp;
    while (1) {
        ptr = head;
        for (int i = 0; i < k - 1; ++i)
            if (ptr != NULL) ptr = ptr->next;
        if (ptr == NULL) break;
        // reverseKnode
        ptr = ptr->next; // ptr points to the first node of the next group
        for (int i = 0; i < k; ++i) {
            temp = head->next;
            head->next = ptr;
            ptr = head;
            head = temp;
        }
        current->next = ptr;
        for (int i = 0; i < k; ++i) current = current->next;
    }
    return dummy.next;
}
