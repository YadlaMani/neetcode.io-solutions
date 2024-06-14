class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        int sum=0;//use sliding window
        while(left<right){
            sum=numbers[left]+numbers[right];//find current sum
            if(sum==target){
                return {left+1,right+1};
            }
            else if(sum>target){//lwft slide
                right--;
}
            else{//right slide
                left++;
            }
           
}
        return {-1};
    }
};
