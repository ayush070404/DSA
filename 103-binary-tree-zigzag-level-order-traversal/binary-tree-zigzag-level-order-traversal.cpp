class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front(); q.pop();

                // More readable version of index calculation
                int index;
                if (leftToRight) {
                    index = i;
                } else {
                    index = n - 1 - i;     // insertion from right side
                }

                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight;  // changing the flag for left side and right side insertion
        }

        return result;
    }
};
