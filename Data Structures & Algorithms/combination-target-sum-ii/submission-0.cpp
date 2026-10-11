class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int idx,int sum,vector<int>&temp,vector<int>&nums, int target){
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        if(idx>=nums.size()){
            return;
        }

        for(int j=idx;j<nums.size();j++){
            if(j>idx && nums[j] == nums[j-1])continue;
            if(sum+nums[j]>target){
                break;
            }

            temp.push_back(nums[j]);
            backtrack(j+1,sum+nums[j],temp,nums,target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        backtrack(0,0,temp,candidates,target);
        return ans;
    }
};
