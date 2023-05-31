class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> inMap;
    map<pair<string, string>, pair<long long, int> > timeNCnt;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        inMap[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> startInfo = inMap[id];
        string startStation = startInfo.first;
        int startTime = startInfo.second;

        timeNCnt[{startStation, stationName}].first += (t - startTime);
        ++timeNCnt[{startStation, stationName}].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> info = timeNCnt[{startStation, endStation}];
        int totalTime = info.first;
        int totalPass = info.second;
        return (double)(totalTime / (double)totalPass);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */