class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        idx, cnt = 0, 0
        for i in nums:
            if i != val:
                nums[idx] = i
                idx += 1
                cnt += 1
        return cnt