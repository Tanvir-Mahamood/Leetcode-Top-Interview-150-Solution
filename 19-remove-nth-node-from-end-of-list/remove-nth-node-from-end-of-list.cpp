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
        int len = 0, pos;
        ListNode* curr = head;
        while(curr) {
            len++;
            curr = curr->next;
        }
        pos = len - n + 1;

        if(pos == 1) return head->next;
        if(len == 1) return nullptr; 
        
        ListNode* prev = head;
        curr = head->next;

        n = 2;
        while(n != pos) {
            prev = curr;
            curr = curr->next;
            n++;
        }

        prev->next = curr->next;
    
        delete curr;

        return head;
    }
};