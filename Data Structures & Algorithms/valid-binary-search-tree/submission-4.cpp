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
    // void valid(TreeNode* root, vector<int>& temp){
    //     if(root==nullptr) return;
    //     if(root->left) valid(root->left,temp);
    //     temp.push_back(root->val);
    //     if(root->right) valid(root->right,temp);
    // }

    int prev=INT_MIN;
    bool valid(TreeNode* root){
        if(root == nullptr)
            return true;

        if(!valid(root->left))
            return false;

        if(root->val <= prev)
            return false;

        prev = root->val;

        return valid(root->right);
    }

    bool isValidBST(TreeNode* root) {
        // vector<int> temp;
        // valid(root,temp);
        // int n=temp.size();
        // for(int i=1;i<n;i++){
        //     if(temp[i]<=temp[i-1]) return false;
        // }
        // return true;

        return valid(root);
    }
};
