class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;

        //example xor of 2^2^2=2->number preserves
        //xor of 3^3=0->number becomes zero
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};
