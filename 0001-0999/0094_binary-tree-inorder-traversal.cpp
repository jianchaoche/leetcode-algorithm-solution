//Link: https://leetcode.com/problems/binary-tree-inorder-traversal/ 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *p = root;
        while(stk.size() || p ){
            if( p != NULL ){
                stk.push(p);
                p = p->left;
            }else{
                p = stk.top();
                stk.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }
};