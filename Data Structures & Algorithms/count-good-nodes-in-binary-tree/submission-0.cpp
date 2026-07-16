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
    void find(TreeNode* root,int &cnt,int x){
        if(root==nullptr) return;
        if(root->val>=x) {
            x=root->val;
            cnt++;
        }
        if(root->left){
            find(root->left,cnt,x);
        }
        if(root->right){
            find(root->right,cnt,x);
        }
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        find(root,cnt,root->val);
        return cnt;
    }
};
