//Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ 
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie ){
        if( ps > pe ) return nullptr;
        if( is > ie ) return nullptr;
        int pos = is;
        int val = preorder[ps];
        for( int i = is; i<=ie; i++ ){
            if( val == inorder[i] ){
                pos = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(val);
        node->left = build(preorder, inorder, ps+1, ps+pos-is, is, pos-1);
        node->right = build(preorder, inorder, pe- (ie-pos)+1, pe, pos+1, ie);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};