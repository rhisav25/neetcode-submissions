class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int idx,int sum, vector<int>&temp,int target,vector<int>&nums){
        if(idx>=nums.size()){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }

        if(sum==target){
             ans.push_back(temp);
             return;
        }
       
       temp.push_back(nums[idx]);
       if(sum+nums[idx]<=target){
        backtrack(idx,sum+nums[idx],temp,target,nums);
       }
       temp.pop_back();
       backtrack(idx+1,sum,temp,target,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        backtrack(0,0,temp,target,nums);
        return ans;
    }
};
