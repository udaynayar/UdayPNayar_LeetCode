class Solution {
public:
    void recurse(vector<vector<int>>& pwerset, vector<int>& nums, vector<int>& store, int i, int n) {
        
        if (i == n) {
            
            pwerset.push_back(store);
            
            return;
        }
        
        store.push_back(nums[i]);
        recurse(pwerset, nums, store, i+1, n);
        store.pop_back();
        recurse(pwerset, nums, store, i+1, n);
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        vector<vector<int>> pwerset;
        vector<int> store;
        int n = nums.size();
        recurse(pwerset, nums, store, 0, n);
        return pwerset;
        
        
        
    }
};