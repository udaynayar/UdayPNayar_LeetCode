class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        if (nums[n-1]!=nums[n-2]) return nums[n-1];
        if (nums[0] != nums[1]) return nums[0];
        
        
        int low = 0, high = (n-1)/2;
        int mid = (low+high)/2;
        while (low<high) {
            
            if (nums[2*mid] != nums[2*mid + 1]) {
                
                if (nums[2*mid]!=nums[2*mid - 1])
                    return nums[2*mid];
                
                
                high = mid;
                mid = (low+high)/2;
                
            }
            
            else {
                
                low = mid+1;
                mid = (low+high)/2;
            }
            
            
            
            
        }
        
        return nums[2*mid];
        
        
        
        //return -1;
    }
};