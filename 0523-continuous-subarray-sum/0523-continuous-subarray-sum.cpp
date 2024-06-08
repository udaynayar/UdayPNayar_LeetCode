class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> check(n);
        check[0] = nums[0];
        for (int i=1; i<n; i++)
            check[i] = check[i-1] + nums[i];
        
        map<int,int> mp;
        
        for (int i=0; i<n; i++) {
            
            int num = check[i];
            if (mp[num%k] && i && 
                (((num-check[i-1])%k) || mp[num%k]>1)
               ) return true;
            mp[num%k]++;
            
            if (i && num%k==0) {cout << "fuck"; return true;}
            
        }
        
        
        
        
        return false;
    }
};