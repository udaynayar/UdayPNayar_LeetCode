class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long x=0;
        
        int n = nums.size();
        vector<int> left(n,-1), right(n,n);
        stack<int> st,st_;
        vector<int> left_(n,-1), right_(n,n);
        
        for (int i=0; i<n; i++) {
            
            while (!st.empty() && nums[i]<=nums[st.top()]) st.pop();
            
            if (!st.empty()) left[i] = st.top();
            st.push(i);
            
        }
        while (!st.empty()) st.pop();
        
        
        for (int i=n-1; i>-1; i--) {
            
            while (!st.empty() && nums[i]<nums[st.top()]) st.pop();
            
            if (!st.empty()) right[i] = st.top();
            st.push(i);
            
        }

        
        
        //
        for (int i=0; i<n; i++) {
            
            while (!st_.empty() && nums[i]>=nums[st_.top()]) st_.pop();
            
            if (!st_.empty()) left_[i] = st_.top();
            st_.push(i);
            
        }
        while (!st_.empty()) st_.pop();
        
        
        for (int i=n-1; i>-1; i--) {
            
            while (!st_.empty() && nums[i]>nums[st_.top()]) st_.pop();
            
            if (!st_.empty()) right_[i] = st_.top();
            st_.push(i);
            
        }
        long long _,__;
        for (int i=0; i<n; i++) {
            _=(i-left[i])*(right[i]-i);
            __=(i-left_[i])*(right_[i]-i);
            x += nums[i]*(__-_);
        }
        
        
        return x;
    }
};