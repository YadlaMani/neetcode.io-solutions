class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;//take a map to count the freq of the characters
        int l=0;//left pointer
        int maxf=0;//current max frequency count
        int ans=0;

        for(int r=0;r<s.size();r++){
            mp[s[r]]++;//update the map
           maxf=max(maxf,mp[s[r]]);//check for max frequency
            while((r-l+1)-maxf>k){//if the (windowSize-maxFrequency)-> no.of defects >k 
               
                mp[s[l]]--;//decrease the count by removing left value
                l++;//move the left pointer
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
