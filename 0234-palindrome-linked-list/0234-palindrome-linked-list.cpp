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
    
    ListNode* reverseList(ListNode* head, vector<int>& shit) {
        if (head) shit.push_back(head->val);
        
        if (!head || !head->next) return head;
        
        ListNode* st = head->next;
        
        ListNode* thing = reverseList(st, shit);
        head->next->next = head;
        
        head->next = NULL;

        
        return thing;
    }
    
    bool isPalindrome(ListNode* head) {
        vector<int> shit;
        ListNode* head2 = reverseList(head, shit);
        
        
        
        
        int i=0;
        
        while (head2) {
            if (shit[i++] != head2->val) return false;
            

            head2 = head2->next;
            
        }
        return true;
    }
};