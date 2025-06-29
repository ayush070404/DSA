class Solution {
  public:
    // Helper function to count total nodes
    int inordercntN(Node* root, int &count) {
        if (root == nullptr) return count;
        inordercntN(root->left, count);
        count++;
        inordercntN(root->right, count);
        return count;
    }

    // Helper function to find the (n-k+1)th node in inorder (kth largest)
    void inorder(Node* root, int k, int &cnt, int &ans , int n) {
        if (root == nullptr) return;

        inorder(root->left, k, cnt, ans, n);

        cnt++;
        if (cnt == n - k + 1) {
            ans = root->data;
            return;
        }

        inorder(root->right, k, cnt, ans, n);
    }

    int kthLargest(Node *root, int k) {
        int count = 0;
        int n = inordercntN(root, count);  // total nodes
        int cnt = 0, ans = -1;
        inorder(root, k, cnt, ans , n);    // find (n-k+1)th smallest
        return ans;
    }
};
