class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> check(n);
        check[0] = nums[0];
        for (int i=1; i<n; i++)
            check[i] = check[i-1] + nums[i];
        
        int ans = 0;
        map<int,int> mp;
        
        for (int i=0; i<n; i++) {
            
            mp[((check[i])%k+k)%k]++;
            
            if (check[i]%k==0) {
                ans++;
                
            }
        }
            
        for (const auto& pair : mp) {
        
            int a = pair.second;
            ans += ((a * (a-1)) / 2);
        }
        

        return ans;
    }
};