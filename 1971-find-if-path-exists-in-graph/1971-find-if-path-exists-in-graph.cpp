class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // edges to adj
        vector<vector<int>> adj(n);
        for(auto e : edges){
            int u  = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);            
        }
        vector<bool> visited(n , false);
        return dfs(source, destination, adj, visited);
    }
    bool dfs(int u,int des, vector<vector<int>>& adj, vector<bool>& visited ){
        if( u == des) return true;
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){
                if(dfs(v,des, adj,visited)) return true;
            }
        }
        return false;
    }
};