class Solution {
public:
int find(vector<int>nums){
    int n=nums.size();
        int ans=0;
        //first xor number from 0 to n
        for(int i=1;i<=n;i++){
            ans^=i;
            
        }
        //and check the number if the number array if they are repeated or not
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        return ans;
}
    int missingNumber(vector<int>& nums) {

        
        return find(nums);

    }
};
