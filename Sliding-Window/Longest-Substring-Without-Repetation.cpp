class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
       map<char,int>mp;//initialize a map for storing count
        int l=0;//sliding window
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){//if the key is already present
                while(mp[s[i]]){//slide the left pointer till the count of that particulare window becomes 0
                    mp[s[l]]--;
                    l++;//slide the window
                }
            }
            mp[s[i]]++;//finally add the new element
            ans=max(ans,i-l+1);//and find if the size is maximum or not
            
        }
        return ans;
    
    }
};
