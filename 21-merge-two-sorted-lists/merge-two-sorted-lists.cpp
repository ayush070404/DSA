class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Use if-else instead of ternary
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
