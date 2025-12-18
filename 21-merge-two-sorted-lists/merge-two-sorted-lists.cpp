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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* judge = new ListNode();
        ListNode* head = judge;

        while(list1 || list2) { 
            if(list1->val <= list2->val) { // list1 is better
                judge->next = list1; 
                judge = judge->next;
                if(list1->next == nullptr) {
                    list1->next = list2;
                    return head->next;
                }
                list1 = list1->next;
            }
            else { // list2 is better
                judge->next = list2; 
                judge = judge->next;
                if(list2->next == nullptr) {
                    list2->next = list1;
                    return head->next;
                }
                list2 = list2->next;
            }
        }
        head = head->next;
        delete judge;
        return head;
    }
};