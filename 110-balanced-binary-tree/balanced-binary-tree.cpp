class Solution {
public:
    // Helper returns height if balanced, -1 if not
    int check(TreeNode* root) {
        if (!root) return 0;

        int lh = check(root->left);
        if (lh == -1) return -1;

        int rh = check(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(check(root) == -1) return false;
        else return true;
    }
};
