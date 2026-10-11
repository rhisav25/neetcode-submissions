class Solution {
public:
    vector<vector<int>>ans;
    vector<bool>vis;
    void backtrack(int idx,vector<int>&temp, vector<int>&nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!vis[i] ){
                if(i>0 && nums[i] == nums[i-1] && !vis[i-1])continue;
                vis[i] = true;
                temp.push_back(nums[i]);
                backtrack(i+1,temp,nums);
                vis[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vis = vector<bool>(nums.size(),false);
        vector<int>temp;
        sort(nums.begin(),nums.end());
        backtrack(0,temp,nums);
        return ans;
    }
};