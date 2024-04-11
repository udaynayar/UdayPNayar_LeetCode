class Solution {
public:

    
    vector<int> mostCompetitive(vector<int>& nums, int K) {
        
        int n = nums.size();
        int k = n-K;
        
        // now, try to remove 'k' elements such that what we get is most competitive
        
        vector<int> stack;
        int t = -1;
        
        for (auto num: nums) {
            
            while (k > 0 && t >= 0 && stack[t] > num) {
                
                stack.pop_back();
                t--;
                k--;
                
            }
            
            stack.push_back(num);
            t++;
            
        }
        while (k >0) {
            
            
            stack.pop_back();
            k--;
        }
        
        
        return stack;
    }
};