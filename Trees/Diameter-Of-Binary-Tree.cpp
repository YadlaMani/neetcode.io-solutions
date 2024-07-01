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
    int res=0;
    int find(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int left=find(root->left);//get max height in left subtree
        int right=find(root->right);//get max height in right subtree
        res=max(res,left+right+1);//add the left and right to get diameter
        return 1+max(left,right);//return max height

       
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int temp=find(root);
        return res-1;

    }
};
