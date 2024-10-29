
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }

    private: 
    void postorderHelper(TreeNode* root, vector<int>& result){
        if (root == nullptr){
            return;
        }

        postorderHelper(root->left, result);

        postorderHelper(root->right, result);

        result.push_back(root->val);
    }
};