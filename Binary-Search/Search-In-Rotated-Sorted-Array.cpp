class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target==nums[mid]){
                return mid;
            }
            else{
                //left sorted portion
                if(nums[l]<=nums[mid]){
                    if(target>nums[mid] or target<nums[l]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
                //right sorted portion
                else{
                    if(target<nums[mid] or target>nums[r]){
                        r=mid-1;
                        
                    }
                    else{
                        l=mid+1;
                    }
                }
            }
        }
        return -1;
    }
};
