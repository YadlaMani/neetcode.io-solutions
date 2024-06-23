class Solution {
public:
    int hammingWeight(int n) {
        int c=0;
       while(n){
        //count if possible
        c++;
        n=n&(n-1);
        //sets the one bit from right to zero everytime
        
       }
       return c;
    }
};
