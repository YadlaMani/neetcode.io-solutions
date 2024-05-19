class Solution {
public:
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<vector<int>>freq(n+1);
        //storing the frequency of each element
        //1->3 2->2 3->1
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            
        }
        //storing them according to count in freq array
        //0->0 1->3 2->2 3->1 4->0 5->0
        
        for(auto m:mp){
            //index->array[nums]
            freq[m.second].push_back(m.first);
        }
        vector<int>res;
        for(int i=freq.size()-1;i>0;i--){
            //iterating through the freq array
            for(int n:freq[i]){
                res.push_back(n);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;
        
       
       
       
       
        
        
    }
};
