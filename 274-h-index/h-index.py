class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse = True)
        
        for i in range(1, len(citations)+1):
            if citations[i-1] < i:
                i -= 1
                break
            
        return i