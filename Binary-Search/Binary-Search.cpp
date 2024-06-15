class Solution {
public:
    int findAns(vector<int>&nums,int target){
         int l=0;//start from initializing left and right pointer
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;//calculate the mid index
            if(nums[mid]==target){//check the value at mid index if found return
                return mid;
            }
            else if(nums[mid]>target){//if element at the mid>target
                r=mid-1;
            }
            else{//if element at the mid<target
                l=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return findAns(nums,target);
    }
};
