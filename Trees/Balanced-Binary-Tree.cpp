/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* node) {
        if (node == NULL) return 0;
        else {

            int lDepth = height(node->left);
            int rDepth = height(node->right);

            return 1+max(lDepth,rDepth);
        }
    }
    bool find(TreeNode* root) {
        if (!root) return true;
        int l = height(root->left);//left height
        int r = height(root->right);// right height
        if (abs(l - r) <= 1) return find(root->left) && find(root->right);//find the balance if true check for next subtree
        return false;//if not balanced return true
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return find(root);
    }
};
