//Maximum product Subarray//

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        left,right,prod=1,1,nums[0]
        for i in range(len(nums)):
            if left==0:left=1
            if right==0:right=1
            left=nums[i]*left
            right=nums[len(nums)-1-i]*right
            prod=max(prod,max(left,right))
        return prod
