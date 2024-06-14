class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxl=0,maxr=0;
        int sum=0;
        while(l<=r){//sliding window approach
            if(height[l]<=height[r]){//maximize height of left
                if(height[l]>maxl){
                    maxl=height[l];
                }
                else{
                    sum+=maxl-height[l];
                }
                l++;
            }
            else{//maximize the height of the right
                if(height[r]>maxr){
                    maxr=height[r];
                }
                else{
                    sum+=maxr-height[r];
                    
                }
                r--;
            }
        }
        return sum;
    }
};
