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

/* Approach 1 using Map */

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        int c = 0;
        unordered_map<int,ListNode*> mapp;
        while( head ){
            mapp[c] = head;
            head = head->next; c++;
        }
        c = mapp.size()-k;
        swap( mapp[k-1]->val, mapp[c]->val );
        
        return mapp[0];
    }
};
