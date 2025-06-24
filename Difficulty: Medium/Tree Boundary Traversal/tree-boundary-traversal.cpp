class Solution {
  public:
    bool isLeaf(Node* node) {
        if( !node->left && !node->right) return true;
        else return false;
    }

    void addLeftBoundary(Node* node, vector<int>& res) {
        Node* curr = node->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            curr = (curr->left) ? curr->left : curr->right;
        }
    }

    void addRightBoundary(Node* node, vector<int>& res) {
        Node* curr = node->right;
        vector<int> tmp;
        while (curr) {
            if (!isLeaf(curr)) tmp.push_back(curr->data);
            curr = (curr->right) ? curr->right : curr->left;
        }
        // Add in reverse
        for (int i = tmp.size() - 1; i >= 0; --i)
            res.push_back(tmp[i]);
    }

    void addLeaves(Node* node, vector<int>& res) {
        if (!node) return;
        if (isLeaf(node)) {
            res.push_back(node->data);
            return;
        }
        addLeaves(node->left, res);
        addLeaves(node->right, res);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};
