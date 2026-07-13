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
        ListNode* temp = new ListNode();
        temp -> next = head;
        int count = 0;
        while(temp->next != nullptr){
            count++;
            temp = temp->next;
        }

        ListNode* temp1 = new ListNode();
        temp1 -> next = head;
        ListNode* ans = temp1;
        int count1 = 0;
        while(temp1->next != nullptr){
            if(count1 == count - n){
                temp1->next = temp1->next->next;
                count1++;
                break;
            }
            temp1 = temp1->next;
            count1++;
        }
        return ans->next;
    }
};












