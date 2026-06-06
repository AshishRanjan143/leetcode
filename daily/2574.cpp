class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i:nums){
            totalSum+=i;
        }
        vector<int> ans(n);
        int leftSum=0;
        for(int i=0;i<n;i++){
            totalSum-=nums[i];
            ans[i]=abs(totalSum-leftSum);
            leftSum+=nums[i];
        }
        return ans;
        
    }
};