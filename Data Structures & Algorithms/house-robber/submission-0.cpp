class Solution {
public:
    int f(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size())return 0;

        if(dp[idx]!=-1)return dp[idx];
        int take = nums[idx] + f(idx+2,nums,dp);
        int not_take = f(idx+1,nums,dp);

        return dp[idx] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

        return f(0,nums,dp);
    }
};
