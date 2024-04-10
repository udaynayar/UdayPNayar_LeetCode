class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = (tickets[k]-1)*n + k + 1;
        
        for (int i=0;i<k;i++) {
            
            if (tickets[i]<tickets[k]) ans-=(tickets[k]-tickets[i]);
            
        }
        for (int i=k+1;i<n;i++) {
            
            if (tickets[i]<tickets[k]-1) ans-=(tickets[k]-tickets[i]-1);
            
        }
        return ans;
    }
};