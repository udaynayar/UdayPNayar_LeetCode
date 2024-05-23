class Solution {
public:
    
    void recurse(int freq_dp[], vector<int>& nums, int k, int& ans, int i, int n) {
        
        if (i == n) {       
            ans++;
            return;
        }

        recurse(freq_dp, nums, k, ans, i+1, n);
        
        if (nums[i]-k < 0 || (freq_dp[nums[i] - k] == 0) && (nums[i]+k > 1000 || (freq_dp[nums[i] + k] == 0))) {
            
            freq_dp[nums[i]]++;
            recurse(freq_dp, nums, k, ans, i+1, n);
            freq_dp[nums[i]]--;
            
        }
        
        
    }
    
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        int freq_dp[1001] = {0};
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        recurse(freq_dp, nums, k, ans, 0, n);
        
        
        
        return ans - 1;
    }
};