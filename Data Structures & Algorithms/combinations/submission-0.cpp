class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int idx, vector<int>&nums,int k,vector<int>&temp){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int j=idx;j<nums.size();j++){
            temp.push_back(nums[j]);
            backtrack(j+1, nums, k,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i] = i+1;
        }
        vector<int>temp;
        backtrack(0,nums,k,temp);
        return ans;
    }
};