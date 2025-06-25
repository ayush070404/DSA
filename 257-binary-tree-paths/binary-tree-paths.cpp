class Solution {
public:
    void solve(TreeNode* root, string path, vector<string>& ans) {
        if (root == NULL) return;

        // Append current node's value to the path
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);

        // If it's a leaf node, add the path to the result
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // Recur left and right
        solve(root->left, path, ans);
        solve(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) return ans;

        solve(root, "", ans);
        return ans;
    }
};
