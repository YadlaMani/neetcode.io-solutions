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
    int helper(TreeNode* root,int &res){
        if(!root){//base case
            return 0;
        }
        //max left sum 
        int left=max(0,helper(root->left,res));
        //max right sum
        int right=max(0,helper(root->right,res));
        //seeing the sum including the root
        res=max(res,left+right+root->val);
        //return either max left sum or max right sum
        return root->val+max(left,right);

    }
    int maxPathSum(TreeNode* root) {
        //initialize result to minimum
        int res=INT_MIN;
        helper(root,res);
        return res;
    }
};
