class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans(n,-1);
        if (n < 1 + 2*k) return ans;
        
        long long s = 0;
        for (int i=0;i<n;i++) {
            
            s += nums[i];
            
            if (i-2*k>0) {
                s -= nums[i-2*k-1];
            }
            
            if (i-k>=k && i-k<n-k) {
                ans[i-k] = s/(1+(2*k));
            }
            
        }
              
        return ans;
    }
};