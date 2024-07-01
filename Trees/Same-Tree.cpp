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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL){//if both null then both same
            return true;
        }
        else{//if either one is null and other is not return false
            if(p&&!q){
                return false;
            }
            if(!p&&q){
                return false;
            }
        }
        if(p->val==q->val){//if both values are same check left and right subtree too
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
        else{
            return false;
        }
    }
};
