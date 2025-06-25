/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;

        // Map to store the last node's value at each horizontal distance
        map<int, int> mpp;  // hd -> node->data

        // Queue for level order traversal: stores (node, horizontal distance)
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second;

            // Always update the value at this horizontal distance (last seen = bottom-most)
            mpp[hd] = node->data;

            if (node->left) {
                q.push({node->left, hd - 1});
            }

            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // Collect values from the map in order of HD (left to right)
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
