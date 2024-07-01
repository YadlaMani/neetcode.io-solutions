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
public:
    void inorder(TreeNode* root){
        if(root==NULL){//when root is null return
            return;
        }
        TreeNode* left=root->left;//store left pointer
        TreeNode *right=root->right;//store right pointer
        //swap the pointers
        root->left=right;
        root->right=left;
        //repeat the traversal
        inorder(root->left);
        inorder(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        inorder(root);//do a inorder traversal
        return root;
    }
};
