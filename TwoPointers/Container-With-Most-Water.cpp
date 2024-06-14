class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int ans=-1;//traverse using sliding window and intialize ans as -1
        while(l<r){
            ans=max(ans,(r-l)*(min(height[l],height[r])));//caculate width and height of the rectangle
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
            
        }
        return ans;
    }
};
