class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode * newNode = new StackNode(x);
        newNode-> next = top;
        top = newNode;
        
    }

    int pop() {
        // code here
        if(top == NULL) return -1;
        int el = top-> data;
        StackNode * temp = temp;
        top = top-> next;
        return el;
    }

    MyStack() { top = NULL; }
};
