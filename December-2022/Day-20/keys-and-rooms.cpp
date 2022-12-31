class Solution {
private:
    void dfs(int house, vector<vector<int> > &rooms, vector<bool> &vis) {
        vis[house] = true;

        for(auto it : rooms[house]) {
            if(vis[it] == false) {
                dfs(it, rooms, vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);

        bool ans = true;
        for(bool isVis : vis) {
            ans &= isVis;
        }

        return ans;
    }
};