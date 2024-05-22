/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    current->next = NULL;
    // 當兩個鏈表都不為空
    while (list1 != NULL && list2 != NULL){
        if (list1->val < list2->val){
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    // 其中個鏈表都不為空
    if (list1 != NULL) current->next = list1;
    if (list2 != NULL) current->next = list2;
    return dummy.next;
}
