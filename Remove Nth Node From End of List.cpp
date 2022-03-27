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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        
        if( head == NULL || head->next == NULL ) return NULL;
        
        ListNode* temp = head;
        int k = 0;
        while( temp ){
            temp = temp->next;
            k++;
        }
        
        if( k == n ){
            return head->next;
        }
        
        k -= n;
        temp = head; n = 0;
        while( head ){
            n++;
            if( n != k ) head = head->next;
            else {
                head->next = head->next->next;
            }
        }
        
        return temp;
    }
};
