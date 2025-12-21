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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(0, head);
        int len = 0, segment;
        ListNode* curr = dummy;
        ListNode* temp;

        while(curr->next) {
            curr = curr->next;
            len++;
        }

        k %= len;
        if(k == 0) return head;

        segment = len - k;

        temp = dummy;
        while(segment--) {
            temp = temp->next;
        }
        
        dummy->next = temp->next;
        temp->next = nullptr;
        temp = dummy->next;

        while(temp->next) {
            temp = temp->next;
        }
        temp->next = head;

        temp = dummy->next;
        delete dummy;
        return temp;

    }
};