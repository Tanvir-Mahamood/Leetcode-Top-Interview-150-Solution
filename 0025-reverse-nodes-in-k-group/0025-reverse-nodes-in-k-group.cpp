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
private:
    ListNode* getGroupEnd(ListNode* node, int k) {
        while(node && k>0) {
            node = node->next;
            k--;
        }
        return node;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode* groupPrev = dummy;
        while(true) {
            ListNode* kth = getGroupEnd(groupPrev, k);
            if(!kth) break;
            ListNode* groupNext = kth->next;
            ListNode* curr = groupPrev->next;
            ListNode* prev = groupNext;
            while(curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy->next;
    }
};