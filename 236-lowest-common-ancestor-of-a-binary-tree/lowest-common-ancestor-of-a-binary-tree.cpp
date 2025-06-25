/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solving(TreeNode* root,vector<TreeNode*> &ans, int B){
     if(root == NULL) return false;
     
     ans.push_back(root);
     if(root->val== B) return true;
     if(solving(root->left,ans,B) || solving(root->right,ans, B)) return true;
     
     ans.pop_back();
     return false;
 }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ansP;
        vector<TreeNode*> ansQ;
        if(root == NULL) return 0;
        
        solving(root, ansP, p->val);
        solving(root, ansQ, q->val);
        TreeNode* lca = nullptr;
        for (int i = 0; i < min(ansP.size(), ansQ.size()); i++) {
            if (ansP[i] == ansQ[i]) {
                lca = ansP[i];
            } else {
                break;
            }
        }

    return lca;
    }
};