class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector< pair <int,int> > vect;//make pair of position and speed
        int n=position.size();
        for(int i=0;i<n;i++){
            vect.push_back(make_pair(position[i],speed[i]));
}
         sort(vect.begin(), vect.end());//sort them
        stack<float>ans;
        for(int i=vect.size()-1;i>=0;i--){
            //if a car at the back reaches the target faster than the car at the front don't add it into the stack else add it to the stack
            float val=(target-vect[i].first)*1.0/vect[i].second;//time=distance/speed;
           
            if(ans.empty()){
                ans.push(val);
            }
            else{
                
                if(val>ans.top())
                ans.push(val);
            }
            
        }
        return ans.size();
    }
};
