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
    //program for checking if the trees are equal or not
    bool check(TreeNode* p,TreeNode* q){
        if(!p&&!q){
            return true;
        }
        if(p && q && p->val==q->val){
            return check(p->left,q->left) && check(p->right,q->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //recursive approach
        if(!root){//if we reach end of the root without getting the subRoot return false
            return false;
        }
        if(root->val==subRoot->val){//if we got a starting matching root then check they the subtree and subroot tree are equal if not go for left and right again
            return check(root,subRoot)|| isSubtree(root->left,subRoot)|| isSubtree(root->right,subRoot);
        }
        else{//if not equal values check left and right subtree too
            return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
        }
    }
};
