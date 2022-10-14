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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* res = new ListNode();
        ListNode *temp = res;
        
        int carry = 0;
        
        while(l1 || l2){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* node = new ListNode(sum);
            temp->next = node;
            temp = temp->next;
        }
        
        
        if(carry != 0){
            ListNode* node = new ListNode(carry);
            temp->next = node;
        }
        
        return res->next;
    }
};