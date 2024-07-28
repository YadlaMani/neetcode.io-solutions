class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        //using a dp
        vector<int>dp(n+1,0);
        dp[0]=1;
        //checking if the first character is not '0'
        if(s[0]!='0'){
            dp[1]=1;
        }
        else{
            return 0;
        }
        //traverse the string
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){//if the current char is not '0' add previous ways
                dp[i]+=dp[i-1];
            }
            if(s[i-2]=='1' || (s[i-2]=='2'&&s[i-1]<='6')){//and they are in between 10 and 26 add the previous of previous one
                dp[i]+=dp[i-2];
            }
        }
        //return the all possible combinations from the last index
        return dp[n];
    }
};
