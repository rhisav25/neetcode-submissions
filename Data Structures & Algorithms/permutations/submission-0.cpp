class Solution {
public:
    vector<vector<int>>ans;
    vector<bool>pick;
    void backtrack(int idx, vector<int>&temp, vector<int>& nums){
        if(nums.size()==temp.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!pick[i]){
                pick[i] = true;
                temp.push_back(nums[i]);
                backtrack(i+1,temp,nums);
                temp.pop_back();
                pick[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        pick = vector<bool>(n,false);
        vector<int>temp;
        backtrack(0,temp,nums);
        return ans;
    }
};
