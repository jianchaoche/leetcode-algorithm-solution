//Link: https://leetcode.com/problems/merge-two-sorted-lists/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while(l1 || l2){
            ListNode** next = l1?&l1:&l2;
            if( l1 && l2 ){
                if(l1->val > l2->val ){
                    next = &l2;
                }else{
                    next = &l1;
                }
            }
            node->next = *next;
            node = node->next;
            *next = (*next)->next;
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};