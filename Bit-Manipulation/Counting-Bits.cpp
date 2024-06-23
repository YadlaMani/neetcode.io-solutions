class Solution {
public:
    vector<int> countBits(int n) {
        //create a look up vector
        vector<int>arr(n+1);
        arr[0]=0;
        for(int i=1;i<=n;i++){
            arr[i]=arr[i&i-1]+1;//computing the ans based on previous stored values
        }
        return arr;

    }
};
