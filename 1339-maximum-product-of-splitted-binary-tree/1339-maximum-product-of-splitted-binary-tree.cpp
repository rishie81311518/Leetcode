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
private: 
 long long maxSum = 0;
 long long totalSum;
 const int MOD = 1e9 + 7;

 long long dfs(TreeNode* node){
    if (node == nullptr){
        return 0;
    }

    long long leftSum = dfs(node->left);
    long long rightSum = dfs(node->right);

    long long subTreeSum = node->val + leftSum + rightSum;
    long long  product = subTreeSum * (totalSum - subTreeSum);

    maxSum = max(maxSum, product);

    return subTreeSum;

 }

 long long calculateTotalSum(TreeNode* node){
   if (node == nullptr){
    return 0;
   }

   return node->val + calculateTotalSum(node->left) + calculateTotalSum(node->right);
 }




public:
    int maxProduct(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }

        totalSum = calculateTotalSum(root);

        dfs(root);

        return maxSum % MOD;

        
        
    }
};