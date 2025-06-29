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

    void inorder(TreeNode* root, vector<int> &arr){
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node-> left;
            }
            else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                arr.push_back(node->val);
                node = node-> right;
            }
        }

    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};