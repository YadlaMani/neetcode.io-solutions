class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int ans=INT_MAX;//intitialize to ans to maximum integer
        while(l<=r){
            int mid=l+(r-l)/2;//calculate mid value
            if(nums[mid]<=nums[l]&&nums[mid]<=nums[r]){//if mid value it lower than both left and right check it with answer
                ans=min(ans,nums[mid]);
                r=mid-1;//but it's not the final answer go to left of it to find the lower value than that
            }
            else{
                if(nums[l]>nums[r]){//if left value is greater go right
                    l=mid+1;
                }
                else{//if right value is greater go left
                    r=mid-1;
                }
                
            }
                
            
        }
        return ans;
        
    }
};
