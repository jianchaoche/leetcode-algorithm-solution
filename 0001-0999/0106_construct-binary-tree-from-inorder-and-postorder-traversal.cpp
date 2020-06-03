//Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ 
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
    TreeNode* build( vector<int>& inorder, vector<int>& postorder, int in_s, int in_e, int po_s, int po_e ){
        if(po_s > po_e ) return nullptr;
        int po_val = postorder[po_e];
        int pos = 0;
        for( int i = in_s; i<= in_e; i++){
            if( po_val == inorder[i]){
                pos = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(po_val);
        node->left = build(inorder, postorder, in_s, pos-1, po_s, po_s+pos-in_s-1);
        node->right = build(inorder, postorder, pos+1, in_e, po_e-in_e+pos, po_e-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};