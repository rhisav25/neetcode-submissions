class Solution {
public:
    int f(int idx,vector<int>&dp,vector<int>& cost){
        if(idx>=cost.size())return 0;

        if(dp[idx]!=-1)return dp[idx];

        return dp[idx] = cost[idx] + min(f(idx+1,dp,cost),f(idx+2,dp,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);

        return min(f(0,dp,cost),f(1,dp,cost));
    }
};
