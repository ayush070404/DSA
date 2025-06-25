/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes in the format:
        // horizontal distance -> level -> sorted list of values
        map<int, map<int, multiset<int>>> nodes;

        // Queue to perform level order traversal
        // Each element in the queue: (node, horizontal distance, level)
        queue<tuple<TreeNode*, int, int>> q;

        // Start from the root with horizontal distance = 0, level = 0
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [currNode, hd, lvl] = q.front();
            q.pop();

            // Insert the current node's value into the map
            nodes[hd][lvl].insert(currNode->val);

            // Add left child with updated hd and level
            if (currNode->left) {
                q.push({currNode->left, hd - 1, lvl + 1});
            }

            // Add right child with updated hd and level
            if (currNode->right) {
                q.push({currNode->right, hd + 1, lvl + 1});
            }
        }

        // Now collect the result from the map in sorted order
        vector<vector<int>> result;

        // Traverse the map from leftmost HD to rightmost HD
        for (auto it : nodes) {
            vector<int> col;
            for (auto lvlPair : it.second) {
                col.insert(col.end(), lvlPair.second.begin(), lvlPair.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};
