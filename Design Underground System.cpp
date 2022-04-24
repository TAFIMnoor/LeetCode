class UndergroundSystem {
    
    map<int, pair<string,int>> checkin;
    map<string,pair<int,int>> checkout;
    
public:
    UndergroundSystem() { }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id].first = stationName;
        checkin[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        
        auto &[start_s,start_t] = checkin[id];
        string query = start_s +" "+ stationName;
        
        checkout[query].first += t - start_t;
        checkout[query].second += 1;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string query = startStation+" "+endStation;
        return (double) checkout[query].first / checkout[query].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
