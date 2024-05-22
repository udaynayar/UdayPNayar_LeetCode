class Solution {
public:
    bool isPalindrome(string str, int n) {
        //int n = str.length();
        for (int i = 0; i < n/2 ; i++)
            if (str[i] != str[n-1-i])
                return false;
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        
        int nn = s.length();
        
        if (nn == 1) {
            return {{s.substr(0,1)}};
        }
        vector<vector<string>> ans;
        
        
        for (int n=1; n<=nn-1; n++) {
            
            
            
            if (isPalindrome(s, n)) {
                vector<vector<string>> store = partition(s.substr(n,nn));
                
                for (auto seg: store) {
                    vector<string> NEW;
                    NEW.push_back(s.substr(0, n));
                    for (auto stip: seg) {
                        NEW.push_back(stip);
                    }
                    ans.push_back(NEW);
                }
            }
            
        }
        
        if (isPalindrome(s, nn)) {
            ans.push_back({s});
        }
        
        
        return ans;
    }
};