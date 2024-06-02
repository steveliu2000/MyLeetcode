/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode dummy;
    struct ListNode* ptr1 = head, * ptr2;
    if (ptr1 != NULL) ptr2 = ptr1->next;
    head = &dummy;

    while (ptr1 && ptr2) {
        ptr1->next = ptr2->next;
        ptr2->next = ptr1;
        head->next = ptr2;
        head = ptr1;
        ptr1 = ptr1->next;
        if (ptr1 != NULL) ptr2 = ptr1->next;
    }
    return dummy.next;
}
