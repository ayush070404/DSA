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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        map<int , int> mpp;  // hD, values
        queue<pair<Node* , int>> q;   // node , HD
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node * node = it.first;
            int Hdist = it.second;
            
            if(mpp.find(Hdist) == mpp.end()) mpp[Hdist] = node->data;
            
            if(node->left != NULL){
                q.push({node->left , Hdist-1});
            }
            if(node->right != NULL){
                q.push({node->right , Hdist+1});
            }
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
    return ans;
    }
};