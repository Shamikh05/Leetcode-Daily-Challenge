class Solution {
private:
    void dfs(int idx, vector<vector<int>> &graph, int n, vector<int> &temp, vector<vector<int> > &ans) {
        if(idx == (n-1)) {
            ans.push_back(temp);
            return;
        }

        for(auto it : graph[idx]) {
            temp.push_back(it);
            dfs(it, graph, n, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> temp;
        temp.push_back(0);
        vector<vector<int> > ans;
        dfs(0, graph, n, temp, ans);

        return ans;
    }
};