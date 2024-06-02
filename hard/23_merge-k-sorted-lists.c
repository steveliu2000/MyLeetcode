/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize == 1 && lists[0] == NULL)
        return NULL;
    struct ListNode dummy, *current = &dummy;
    dummy.next = NULL;
    while (1) {
        int minIndex = -1;
        // 找到列表中最小值的節點
        for (int i = 0; i < listsSize; ++i) {
            if (lists[i] != NULL) {
                if (minIndex == -1 || lists[i]->val < lists[minIndex]->val) {
                    minIndex = i;
                }
            }
        }
        if (minIndex == -1)
            break;
        current->next = lists[minIndex];
        current = current->next;
        lists[minIndex] = lists[minIndex]->next;
    }
    return dummy.next;
}
