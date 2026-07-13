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
        ListNode* ans = new ListNode();
        ListNode* merged = ans;
        while(list1 != NULL && list2 != NULL){
            if(list1->val > list2->val){
                merged->next = list2;
                list2 = list2->next;
                merged = merged->next;
            }
            else{
                merged->next = list1;
                list1 = list1->next;
                merged = merged->next;
            }
        }
        while(list1 != NULL){
            merged->next = list1;
            list1 = list1->next;
            merged = merged->next;
        }
        while(list2 != NULL){
            merged->next = list2;
            list2 = list2->next;
            merged = merged->next;
        }
        return ans->next;
    }
};














