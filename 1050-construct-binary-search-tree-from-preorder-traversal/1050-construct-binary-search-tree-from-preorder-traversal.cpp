#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        // Initialize the root with the first element in preorder
        TreeNode* root = new TreeNode(preorder[0]);

        // Stack to keep track of nodes for which we are looking to insert children
        stack<TreeNode*> st;
        st.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            
            // If the current value is smaller than the node at the top of the stack, it is the left child
            if (preorder[i] < st.top()->val) {
                st.top()->left = node;
            } else {
                // If it's larger, pop from the stack until we find where it should go as a right child
                TreeNode* parent = nullptr;
                while (!st.empty() && preorder[i] > st.top()->val) {
                    parent = st.top();
                    st.pop();
                }
                parent->right = node;
            }
            // Push the new node to the stack
            st.push(node);
        }
        return root;
    }
};
