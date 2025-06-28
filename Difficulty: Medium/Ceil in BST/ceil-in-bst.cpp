int findCeil(Node* root, int input) {
    int ceilVal = -1;
    
    while (root != nullptr) {
        if (root->data == input) {
            return root->data;
        } else if (root->data < input) {
            root = root->right;
        } else { // root->data > input
            ceilVal = root->data;  // potential ceil
            root = root->left;     // try to find a smaller one
        }
    }
    
    return ceilVal;
}
