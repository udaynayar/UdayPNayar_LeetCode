class Solution(object):
    def lengthLongestPath(self, input_):
        """
        :type input: str
        :rtype: int
        """
        
        p = input_.split('\n')
        c = 0
        su = 0
        
        
        L = []
        
        i = 0 #tracks length of array
        for st in p:
            print(st)
            ii = st[:i+1].count('\t')+1
            
            if ii==i+1:
                L.append(st[ii-1:])
                i+=1
                su += (1 + len(L[-1]))
                
            #elif ii==i:
             #   su -= len(L[-1])
              #  L[-1] = p[ii:]
               # su += len(L[-1])
            
            
            else:
                while ii < i:
                    
                    su -= (1 + len(L.pop()))
                    i-=1
                su -= len(L[-1])
                L[-1] = st[ii-1:]
                su += len(L[-1])
                
            print(su)
            if '.' in L[-1]:
                c = max(c, su)
                
            
        return max(0,c-1)