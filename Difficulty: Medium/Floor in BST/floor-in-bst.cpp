// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int floorVal = -1;
        
        while(root != nullptr){
            if(root->data == x){
                floorVal = root->data;
                return floorVal;
            }
            else if(root->data > x){
                root = root->left;
              
            }
            else{
                floorVal = root->data;
                root = root->right;
            }
        }
    return floorVal;   
    }
};