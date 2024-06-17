class TimeMap {
public:
    map<string,map<int,string>>mp;//map initialization for storing values
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)!=mp.end()){//checking if the key is present or not
            auto it=mp[key].lower_bound(timestamp);//calculating lower bound
            if(it->first==timestamp){//if present return value
                return it->second;
            }
            it--;//else check if lower value timestamp is less than the given
            if(it->first<timestamp){
                return it->second;
            }
            
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
