class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(auto it:nums){
            if(mp[it]== true){
                return true;
            }
            mp[it] = true;
        }
        return false;
    }
};