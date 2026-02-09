class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return buildBalancedBST(nodes, 0, nodes.size() - 1);
    }
    
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
    
    TreeNode* buildBalancedBST(vector<int>& nodes, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildBalancedBST(nodes, left, mid - 1);
        root->right = buildBalancedBST(nodes, mid + 1, right);
        return root;
    }
};