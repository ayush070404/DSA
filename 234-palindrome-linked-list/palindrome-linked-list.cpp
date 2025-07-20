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

    ListNode* reverseLinkedList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *newNode = NULL;

        while(head != NULL){
            ListNode * nextNode = head->next;
            head->next = newNode;
            newNode = head;
            head = nextNode;
        }
    return newNode;
    }


    bool isPalindrome(ListNode* head) {
        if(head == NULL || head-> next == NULL) return true;

        ListNode * slow = head;
        ListNode *fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLinkedList(slow-> next);
        ListNode *first = head;
        ListNode* second = newHead;

        while(second!= NULL){
            if(first-> val != second->val){
                reverseLinkedList(newHead);
                return false;
            }
            second = second->next;
            first = first->next;
        }
        reverseLinkedList(newHead);
        
        return true;

    }
    
    
};