/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* a, struct ListNode* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    struct ListNode dummy, *current = &dummy;
    dummy.next = NULL;
    while (a && b) {
        if (a->val < b->val) {
            current->next = a;
            current = current->next;
            a = a->next;
        }
        else {
            current->next = b;
            current = current->next;
            b = b->next;
        }
    }
    if (a != NULL) current->next = a;
    else current->next = b;
    return dummy.next;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;
    for (int i = listsSize - 2; i >= 0; --i)
        lists[i] = merge(lists[i], lists[i+1]);
    return lists[0];
}
