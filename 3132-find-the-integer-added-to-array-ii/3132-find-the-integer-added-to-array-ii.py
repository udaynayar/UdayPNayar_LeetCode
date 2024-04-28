class Solution(object):
    def minimumAddedInteger(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        nums1.sort()
        nums2.sort()
        
        m = len(nums1)
        
        n = m-2 #==len(nums2)
        
        a = nums2[0] - nums1[0]
        b = nums2[0] - nums1[1]
        c = nums2[0] - nums1[2]
        
        A,B,C=0,0,0
        aa,bb,cc=None,None,None
        
        
        for i in range(3,m):
            if nums2[i-2]-nums1[i]!=c:
                C+=1
                break
        if not C:
            cc = c
            
            
        for i in range(2,m):
            try:
                if nums2[i-1-B] - nums1[i] != b:
                    B += 1
                    i += 1
            except:
                break
                
            if (B > 1):
                break
        if B <= 1:
            bb = b
            
            
        for i in range(1,m):
            try:
                if nums2[i-A] - nums1[i] != a:
                    A += 1
                    i += 1
            except:
                break
                
            if (A > 2):
                break
        if A <= 2:
            aa = a
            
                
                
        ANS = 2000
        if aa is not None:
            ANS = min(ANS, aa)
        if bb is not None:
            ANS = min(ANS, bb)
        if cc is not None:
            ANS = min(ANS, cc)
        
        return ANS
        
        """
        a,b,c=0,0,0
        
        for i in range(1,n):
            if nums1[i] - nums2[i] == nums1[i-1] - nums2[i-1]:
                a+=1
            else:
                break
                
        for i in range(1,n):    
            if nums1[i+2] - nums2[i] == nums1[i+1] - nums2[i-1]:
                b+=1
            else:
                break
                
        
        
        
        
        A = 2000
        if """
        
        
        
        
        
        
        
        
        