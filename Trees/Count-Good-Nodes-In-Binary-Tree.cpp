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
    //always the count count will be atleast one because of root node
    int c=1;
    void count(TreeNode * root,int prevVal){
        if(!root) return;//base case
        if(root->val>=prevVal){//the subnode val is greater than the root node we have good node
            c++;//increase count
            prevVal=root->val;//make the current node prev node now
        }//again traverse the left and right sub nodes
        count(root->left,prevVal);
        count(root->right,prevVal);

    }
    int goodNodes(TreeNode* root) {
        //traverse left and right keeping the root value
        count(root->left,root->val);
        count(root->right,root->val);
        return c;

        
    }
};
