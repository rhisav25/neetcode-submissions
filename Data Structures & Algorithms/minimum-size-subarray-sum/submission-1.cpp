class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            sum += nums[j];
            while(sum>=target){
                ans = min(ans,j-i+1);
                sum = sum-nums[i];
                i++;
            }
        }
        if(ans!=INT_MAX)return ans;
        return 0;
    }
};