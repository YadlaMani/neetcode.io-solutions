class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;//intialize left to 1 and right to max contraint
        int r = 1000000000;
        while(l<=r){
            int mid=l+(r-l)/2;//caculate mid
            if(check(piles,mid,h)){//check if the condition is possible with the mid
                r=mid-1;//now try to calculate minimum from that array again
            }
            else{
                l=mid+1;///else try to calculate in between
            }
        }
        return l;
    }
    bool check(vector<int>&piles,int k,int h){
        double sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=(piles[i]/k);//checking time consumed to devour each pile by koko
            if(piles[i]%k!=0) sum++;
            
            
        }
       
        return sum<=h;
    }
};
