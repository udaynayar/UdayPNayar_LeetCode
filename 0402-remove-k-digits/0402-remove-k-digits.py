class Solution(object):
    def removeKdigits(self, num, k):
        
        if k==0:
            if not num:
                return "0"
            return str(int(num))
        
        stack = []
        
        for dig in num:
            
            #stack.append(dig)
            
            while k>0 and stack and stack[-1]>dig:
                
                stack.pop()
                k-=1
                
                
            stack.append(dig)
        
        
        while k>0:
            
            stack.pop()
            k-=1
            
        if not stack:
            return "0"
        
        s = ""
        flag=False
        for elem in stack:
            if elem=='0' and not flag:
                continue
            
            if elem!='0':
                flag=True
                
            s = s + elem
        
        return s or "0"