class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end())return "";

        auto & p = m[key];

        int low = 0, high = p.size()-1;
        string ans = "";

        while(low<=high){
            int mid = low + (high-low)/2;
            if(p[mid].first<= timestamp){
                low = mid+1;
                ans = p[mid].second;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};
