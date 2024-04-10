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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> answer(m, vector<int>(n,-1));
        
        ListNode* node = head;
        
        int i=0, j=0;
        bool right = true;
        bool down = false, left = false, up = false;
        
        if (n==1) {
            int i=0;
            while (node) {
                answer[i++][0] = node->val;
                node=node->next;
            }
            return answer;
            
        }
        
        if (m==1) {
            
            int j=0;
            while (node) {
                answer[0][j++] = node->val;
                node=node->next;
            }
            return answer;
        }
        
        while (node) {
            answer[i][j] = node->val;
            cout << i << " " << j << " " << node->val<<endl;
            if (right) {
                j++;
                cout << "KIck";
                if (j+1 >= n || answer[i][j+1]!=-1) {
                    right = false;
                    down = true;
                    cout << "ass";
                }
            }
            else if (down) {
                i++;
                if (i+1 >= m || answer[i+1][j]!=-1) {
                    down = false;
                    left = true;
                }
            } 
            else if (left) {
                j--;
                if (j<=0 || answer[i][j-1]!=-1) {
                    left = false;
                    up = true;
                }
            }
            else if (up) {
                i--;
                if (i <= 0 || answer[i-1][j]!=-1) {
                    up = false;
                    right = true;
                }
            }
            
            
            
            node = node->next;
        }
        
        
        
        return answer;
    }
};