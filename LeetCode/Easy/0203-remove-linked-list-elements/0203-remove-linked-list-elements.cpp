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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode();
        ListNode* ans = prev;
        prev->next = head;

        while(prev != nullptr){
            while(prev->next != nullptr && prev->next->val == val){
                prev->next = prev->next->next;
            }
            prev = prev->next;
        }
        return ans->next;
    }
};












