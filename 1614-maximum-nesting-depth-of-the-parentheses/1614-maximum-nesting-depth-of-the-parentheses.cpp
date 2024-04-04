class Solution {
public:
    int maxDepth(string s) {
        int a = 0;
        int c = 0;
        for (int i=0;i<s.length();i++) {
            if (s[i]=='(') a++;
            else if (s[i]==')') a--;
            
            if (a>c) c=a;
        }
        return c;
    }
};