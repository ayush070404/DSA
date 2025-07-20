class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = new ListNode(list1->val);  // create new node
                list1 = list1->next;
            } else {
                tail->next = new ListNode(list2->val);  // create new node
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Copy remaining nodes from list1 or list2
        while (list1 != nullptr) {
            tail->next = new ListNode(list1->val);
            list1 = list1->next;
            tail = tail->next;
        }
        while (list2 != nullptr) {
            tail->next = new ListNode(list2->val);
            list2 = list2->next;
            tail = tail->next;
        }

        ListNode* head = dummy->next;
        delete dummy;  // clean up dummy node
        return head;
    }
};
