class Solution {
public:
    
    
    bool checkValidString(string s) {
        
        stack<int> starIndex, stackIndex;
        
        int i=0;
        for (auto c: s) {
            
            if (c == '(') {
                stackIndex.push(i);
            }
            else if(c == ')') {
                
                if (stackIndex.empty() && starIndex.empty()) {
                    return false;
                }
                
                if (!stackIndex.empty()) {
                    stackIndex.pop();
                }
                else { // !starIndex.empty()
                    starIndex.pop();
                }
                
            }
            else {
                starIndex.push(i);
            }
            
            i++;
        }
        
        
        while (!stackIndex.empty()) {
            if (starIndex.empty()) return false;
            
            if (starIndex.top() < stackIndex.top())
                return false;
            
            
            starIndex.pop();
            stackIndex.pop();
            
        }
        
        return true;
        
        
    }
        
};