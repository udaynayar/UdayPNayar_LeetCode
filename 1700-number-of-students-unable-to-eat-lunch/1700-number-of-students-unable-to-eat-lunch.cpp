class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int n = sandwiches.size();
        queue<int> q;
        for (int i=0; i<n;i++)
            q.push(students[i]);
        int q_size = n;
        
        int st = 0;
        int x = 0;
        
        while (st < n) {
            if (q_size <= x) break;
            if (sandwiches[st] == q.front()) {
                st++;
                q.pop();
                q_size--;
                x=0;
            }
            
            else {
                
                int f = q.front();
                q.pop();
                q.push(f);
                x++;
            }
            
        }
        
        return q_size;
    }
};