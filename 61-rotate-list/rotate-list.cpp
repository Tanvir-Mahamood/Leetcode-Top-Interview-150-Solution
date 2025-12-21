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
        int len = 1, part1, part2;
        ListNode* curr = head;
        ListNode* prev;

        while(curr->next) {
            curr = curr->next;
            len++;
        }

        k %= len;
        if(k == 0) return head;
        
        part1 = len - k;
        part2 = part1 + 1;

        curr = dummy;
        while(part1) {
            curr = curr->next;
            part1--;
        }
        prev = curr;
        curr = curr->next;

        prev->next = nullptr;
        prev = curr;
        while(curr->next) {
            curr = curr->next;
        }

        curr->next = head;
        dummy->next = prev;

        return dummy->next;

    }
};