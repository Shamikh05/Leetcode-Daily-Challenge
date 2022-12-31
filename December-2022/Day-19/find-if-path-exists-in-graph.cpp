class Solution {
private:
    bool dfs(int vertex, int &destination, vector<int> adj[], vector<bool> &vis) {
        if(vertex == destination) {
            return true;
        }

        vis[vertex] = 1;
        for(auto it : adj[vertex]) {
            if(vis[it] == false) {
                bool destReached = dfs(it, destination, adj, vis);
                
                if(destReached) {
                    return true;
                }
            }
        }

        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, 0);
        return dfs(source, destination, adj, vis);
    }
};