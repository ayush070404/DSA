/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
        ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;  /// 

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow; /// stores the prev node before increment;
            slow = slow->next;
        }

        // 'slow' is at the middle node, 'prev' is node before middle
        prev->next = slow->next;
        // delete slow; //to delete the node

        return head;
    }

};