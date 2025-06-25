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
            auto front = q.front(); // get the front tuple
            q.pop();

            TreeNode* currNode = get<0>(front); // node
            int hd = get<1>(front);             // horizontal distance
            int lvl = get<2>(front);            // level


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

        // Traverse from leftmost HD to rightmost
        for (auto& [hd, levels] : nodes) {
            vector<int> column;

            // Top to bottom at each HD
            for (auto& [level, values] : levels) {
                for (int val : values) {
                    column.push_back(val); // simpler than insert
                }
            }

            result.push_back(column);
        }

        return result;
    }
};
