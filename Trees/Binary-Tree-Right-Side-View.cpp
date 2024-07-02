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
//First approach
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int flag = 1;
            TreeNode* temp = q.front();
            ans.push_back(temp->val);
            queue<TreeNode*> q2;
            while (!q.empty()) {
                temp = q.front();
                q.pop();
                if (temp->right)
                    q2.push(temp->right);
                if (temp->left)
                    q2.push(temp->left);
            }
            while (!q2.empty()) {
                q.push(q2.front());
                q2.pop();
            }
        }
        return ans;
    }
};
//Second approach
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
    void find(TreeNode* root,int level,vector<int>&ans){
        if(root==NULL) return;
        if(ans.size()==level) ans.push_back(root->val);//if we get a value at the current level add that
        find(root->right,level+1,ans);//after that do recursion of and add right and increse the level 
        find(root->left,level+1,ans);//similarly left
    }
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
       find(root,0,ans);//based on current level
       return ans;
    }

};
