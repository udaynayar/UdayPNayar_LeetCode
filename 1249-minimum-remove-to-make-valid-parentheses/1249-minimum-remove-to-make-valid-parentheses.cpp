class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        string ans;
        int c=0;
        stack<int> stac;
        int j=0;
        for (int i=0;i<s.length();i++) {
            
            if (s[i]==')') {
                
                
                
                if (c==0) continue;
                
                stac.pop();
                c--;
                
            }
            else if (s[i]=='(') {
                
                stac.push(j);
                
                c++;
            }
            
            
            
            ans.push_back(s[i]);
            j++;
        }
        
        vector<bool> scam(ans.length(),false);
        
        while (!stac.empty()) {
            int i = stac.top();
            stac.pop();
            scam[i]=true;
        }
        
        string answ=ans;
        ans="";
        
        for (int i=0;i<scam.size();i++) {
            
            if (scam[i]) continue;
            ans.push_back(answ[i]);
            
        }
        
        
        return ans;
    }
};