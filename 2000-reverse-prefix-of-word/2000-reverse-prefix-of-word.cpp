class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int i; int n = word.length();
        for (i=0;i<n;i++) {
            
            if (word[i]==ch) break;
        }
        if (i==n) return word;
        
        i++;
        for (int j=0;j<i/2;j++) {
            char t = word[j];
            word[j] = word[i-1-j];
            word[i-1-j] = t;
        }
        return word;
        
    }
};