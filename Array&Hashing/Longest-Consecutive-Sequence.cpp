class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());//sort the array for traversal
       int ans=1;//intialize the count and answer
        int c=1;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1||nums[i]-nums[i-1]==0){//apply the condition of the problem
                if(nums[i]-nums[i-1]==0){
                    continue;
                }
                c++;
                ans=max(ans,c);
            }
            else{//if condition doesn't match check the current count with ans and make the count 1
                ans=max(ans,c);
                c=1;
            }
        }
        return ans;
        
        
    }
};
