class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int idx,vector<int>&temp,vector<int>&nums){
        ans.push_back(temp);

        for(int j=idx;j<nums.size();j++){
            temp.push_back(nums[j]);
            backtrack(j+1,temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        backtrack(0,temp,nums);
        return ans;
    }
};
