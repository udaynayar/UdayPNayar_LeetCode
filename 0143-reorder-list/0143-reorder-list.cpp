class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        vector<ListNode*> ting;
        int n=0;
        while (head!=NULL) {
            ting.push_back(head);
            head=head->next;
            ting[n]->next=nullptr;
            n++;
        }
        for (int i=0;i<n/2;i++) {
            ting[i]->next=ting[n-i-1];
            if (n%2==0 && i==n/2 - 1) break;
            ting[n-i-1]->next=ting[i+1];
        }
        
    }
};

/*
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return; // Handle empty or single-node lists
        
        vector<ListNode*> nodes;
        ListNode* curr = head;
        
        // Store all nodes in the list
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        
        int n = nodes.size();
        int i = 0, j = n - 1;
        
        // Reorder the list
        while (i < j) {
            nodes[i]->next = nodes[j];
            i++;
            
            if (i == j) break; // Handle odd-length lists
            
            nodes[j]->next = nodes[i];
            j--;
        }
        
        // Set the next pointer of the last node to nullptr
        nodes[i]->next = nullptr;
    }
};


*/