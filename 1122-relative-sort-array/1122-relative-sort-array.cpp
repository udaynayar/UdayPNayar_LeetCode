class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        int n = arr1.size();
        
        for (int i=0; i<n; i++) {
            mp[arr1[i]]++;
        }
        
        vector<int> arr_1, arr_2;
        for (auto nu: arr2) {
            //int nu = _.first;
            
            for (int j=0;j<mp[nu];j++)
                arr_1.push_back(nu);
            
            mp[nu]=0;
        }
        
        for (auto _: mp) {
            int nu = _.first;
            
    
            for (int j=0;j<mp[nu];j++)
                arr_2.push_back(nu);
        }
        sort(arr_2.begin(), arr_2.end());
        
        for (auto el: arr_2)
            arr_1.push_back(el);
        
        
        return arr_1;    
    }
};