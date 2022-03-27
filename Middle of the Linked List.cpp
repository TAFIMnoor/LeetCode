/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if( head == NULL || head->next == NULL ){
            return head;
        }
        
        map<int, ListNode*> mapp;
        int k = 1;
        while( head ){
            mapp[k++] = head;
            head = head->next;
        }
        
        if(k&1) return mapp[(k+1)/2];
        else return mapp[k/2];
    }
};
