class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        bool vis[n];//construct a visited array of false
        fill(vis,vis+n,false);
        for(int i=0;i<n;i++){
            if(!vis[nums[i]]){//if number has never been visited make it true
                vis[nums[i]]=true;
            }
            else{//if number is already visited then reutrn that number
                return nums[i];
            }
        }
        return -1;
    }
};
