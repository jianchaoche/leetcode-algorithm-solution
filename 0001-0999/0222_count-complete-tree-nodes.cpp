//Link: https://leetcode.com/problems/count-complete-tree-nodes/ 
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
    int countNodes(TreeNode* root) {
        return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
    }
    int countNodes1(TreeNode* root) {
        if(!root) return 0;
        int l = lh(root);
        int r = rh(root);
        if(l == r) return pow(2, l) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int lh(TreeNode* root) {
        return root ? 1 + lh(root->left) : 0;
    }
    int rh(TreeNode* root) {
        return root ? 1 + rh(root->right) : 0;
    }
    int countNodes2(TreeNode* root) {
        if(!root ) return 0;
        int left_level = 0,right_level = 0;
        auto node = root;
        while(node){
            left_level++;
            node = node->left;
        }
        node = root;
        while(node){
            right_level++;
            node = node->right;
        }
        
        if( left_level == right_level)
            return pow(2, left_level) - 1;
        int last_level_node = 0;
        dfs(root, right_level, last_level_node);
        //cout<<left_level << " "<<right_level <<" "<<last_level_node<<endl;
        return pow(2, right_level) + last_level_node-1;
    }
    
    bool dfs(TreeNode* root, int level, int &last_level_node){
        if( level == 0 ){
            if( root ){
                last_level_node++;
                return true;
            }
            return false;
        }
        if( !root )
            return false;
        bool res = dfs(root->left, level-1, last_level_node);
        if( res == false )
            return false;
        res = dfs(root->right, level-1, last_level_node);
        if(res == false )
            return false;
        return true;
    }
};