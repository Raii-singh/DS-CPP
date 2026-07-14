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
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        //mid
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        //reverse

        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //compare
        ListNode* first = dummy;
        while(prev != nullptr){
            if(first->val != prev->val) return false;
            first = first->next;
            prev = prev->next;
        }
        return true;        
    }
};















