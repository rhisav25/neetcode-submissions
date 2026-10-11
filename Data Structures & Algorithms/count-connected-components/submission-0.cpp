class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&vis){
        vis[node] = true;

        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
