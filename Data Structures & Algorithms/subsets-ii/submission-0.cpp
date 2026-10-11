class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int idx, vector<int>& temp, vector<int>&nums){
        ans.push_back(temp);

        for(int j = idx;j<nums.size();j++){
            if(j>idx && nums[j] == nums[j-1])continue;

            temp.push_back(nums[j]);
            backtrack(j+1,temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        backtrack(0,temp,nums);
        return ans;
    }
};
