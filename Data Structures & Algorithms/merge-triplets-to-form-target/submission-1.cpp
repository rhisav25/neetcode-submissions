class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int>good;

        for(const auto it:triplets){
            if(it[0]>target[0] || it[1]>target[1] || it[2]>target[2]){
                continue;
            }

            for(int i=0;i<it.size();i++){
                if(it[i]==target[i]){
                    good.insert(i);
                }
            }
        }
        return good.size() == 3;
    }
};
