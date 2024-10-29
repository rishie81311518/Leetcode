class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
private:
    void inorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        // First traverse left subtree
        inorderHelper(root->left, result);
        
        // Then process current node
        result.push_back(root->val);
        
        // Finally traverse right subtree
        inorderHelper(root->right, result);
    }
};