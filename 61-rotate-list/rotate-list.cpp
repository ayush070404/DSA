class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        // Step 1: Count the nodes
        int cnt = 0;
        ListNode* temp = head;
        ListNode* tail = NULL;

        while(temp != NULL) {
            tail = temp;
            temp = temp->next;
            cnt++;
        }

        // Step 2: Modulo reduction
        k = k % cnt;
        if(k == 0) return head;

        // Step 3: Find the new tail (cnt - k - 1) and new head
        int steps_to_new_tail = cnt - k;
        temp = head;
        for(int i = 1; i < steps_to_new_tail; i++) {
            temp = temp->next;
        }

        // Now temp is new tail
        ListNode* new_head = temp->next;
        temp->next = NULL;        // Break the list
        tail->next = head;        // Link end to head

        return new_head;
    }
};
