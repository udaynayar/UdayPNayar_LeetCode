class Solution {
public:
    void recurse(vector<int>& nums, int i, int n, int st, int &ref) {
        
        if (i == n) {
            
            ref += st;
            return;
        }
        
        recurse(nums, i + 1, n, st, ref);
        
        recurse(nums, i + 1, n, st ^ nums[i], ref);
        
        
    }
    int subsetXORSum(vector<int>& nums) {
        
        
        int n = nums.size();
        int x = 0;
        recurse(nums, 0,n, 0, x);
        return x;
        
        
    }
};