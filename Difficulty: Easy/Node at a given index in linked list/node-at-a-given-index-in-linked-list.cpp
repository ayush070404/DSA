class Solution {
  public:
    int GetNth(Node *head, int index) {
        if(head == NULL) return -1;
        Node *temp = head;
        int cnt = 0;

        while(temp){
            if(cnt == index-1){
                return temp->data;
            }
            cnt++;
            temp = temp->next;
        }
        return -1;
        
    }
};

