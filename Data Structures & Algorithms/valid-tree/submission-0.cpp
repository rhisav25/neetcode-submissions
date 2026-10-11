class Solution {
public:
    bool dfs(int node, int parent,vector<vector<int>> adj, vector<int>&vis){
        if(vis[node])return false;

        vis[node] = true;
        for (auto it : adj[node]) {
            if (it == parent) continue; 
            if (!dfs(it, node, adj, vis)) {      
                return false;                    
            }
    }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
          if(edges.size()!=n-1)return false;
          vector<vector<int>>adj(n);
          for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
          }
          vector<int>vis(n,0);
          if(!dfs(0,-1,adj,vis))return false;

          for(int i=0;i<n;i++){
            if(!vis[i])return false;
          }
        return true;
    }
};
