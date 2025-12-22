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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode* smallHead = new ListNode();
        ListNode* smallPtr = smallHead;
        ListNode* bigHead = new ListNode();
        ListNode* bigPtr = bigHead;

        while(curr) {
            if(curr->val < x) {
                smallPtr->next = curr;
                smallPtr = smallPtr->next;
            }
            else {
                bigPtr->next = curr;
                bigPtr = bigPtr->next;
            }
            if(curr->next) curr = curr->next;
            else break;
        }

        smallPtr->next = bigHead->next;
        bigPtr->next = nullptr;
        return smallHead->next;

    }
};