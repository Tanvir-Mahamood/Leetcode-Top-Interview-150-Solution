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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* HEAD = new ListNode(0, head);
        ListNode*  TAIL(0);
        head = HEAD;
        ListNode* num1;
        ListNode* num2;
        ListNode* num3;
        ListNode* lft;
        ListNode* prev_left;
        int i, cnt = 0, len = right - left; 

        while(head->next) {
            if(cnt == left - 1) {
                prev_left = head;
                lft = head->next;
            }
            head = head->next;
            cnt++;
        }
        head->next = TAIL;

        num1 = lft;
        num2 = lft->next;
        num3 = lft->next->next;
        
        for(i=0; i<len-1; i++) {
            num2->next = num1;
            num1 = num2;
            num2 = num3;
            num3 = num3->next;
        }
        num2->next = num1;

        prev_left->next = num2;
        lft->next = num3;
        lft->next = (num3 == TAIL) ? nullptr : num3;
        HEAD = HEAD->next;

        return HEAD;
    }
};