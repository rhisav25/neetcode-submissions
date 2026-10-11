class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int ans = INT_MIN;
        for(int i=0;i<prices.size();i++){
            buy = min(prices[i],buy);
            int currPro = prices[i] - buy;
            ans = max(currPro,ans);
        }
        return ans;
    }
};
