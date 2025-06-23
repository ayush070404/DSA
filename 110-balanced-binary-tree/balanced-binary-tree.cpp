class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);

        if (abs(leftH - rightH) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    // return true;
    }
};
