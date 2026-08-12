class Solution {
public:

    vector<vector<int>> ans;

    void dfs(int node, int destination,
             vector<int>& path,
             vector<vector<int>>& graph) {

        path.push_back(node);

        if(node == destination) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(int neighbour : graph[node]) {
            dfs(neighbour, destination, path, graph);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(
        vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        dfs(0, n - 1, path, graph);
        return ans;
    }
};