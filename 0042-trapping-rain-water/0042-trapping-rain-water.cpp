class Solution {
public:
    int trap(vector<int>& height) {
        
        stack<int> st;
        int n = height.size();
        int ans = 0;
        
        int xx = 0;
        while (xx<n) {
            if (height[xx]) break;
            xx++;
        }
        if (xx==n) return 0;
        
        for (int i=xx; i<n; i++) {

            while (!st.empty() && height[i]>height[st.top()]) {
                
                int id = st.top();
                st.pop(); 
                
                if (st.empty()) break;
                
                int base = height[id];
                
                int hei = min(height[st.top()], height[i]) - base;
                
                if (hei<0) return -1;
                
                ans += (hei * (i - st.top() - 1));
                cout << ans << endl;
                
            }
            
            st.push(i);
            
            
            cout << i << " -\n";
        }
        
        return ans;
        
    }
};