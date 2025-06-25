/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
   
   void solve(Node* root ,vector<int> arr, vector<vector<int>> &ans){
       if(root == NULL) return;
       arr.push_back(root->data);
       
       if(root->left == NULL && root->right == NULL) {
           ans.push_back(arr);
 
       }
       
       solve(root->left, arr ,  ans);
       solve(root->right,arr, ans);
       
       
       arr.pop_back();
   }
   
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> arr;
        solve(root ,arr,  ans);
        return ans;
    }
};