class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="") return "";//edge case
        map<char,int>mp;//map for t
        map<char,int>win;//map for s window
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;//get the count of the t string
        }
       
        int need=mp.size();//no.of terms need to match
        int curr=0;//currently matched terms
      int start=0;//start index
        int minLen=INT_MAX;//minLen
        int l=0;
        for(int r=0;r<s.size();r++){
            char c = s[r];
            win[c]++;//incrase the count in window map
            
            if (mp.find(c) != mp.end() && win[c] == mp[c]) {//check if the key is present in the mp if yes check if the count is equal with the window then we found a match
                curr++;//increase curr
            }
            
            while(curr==need){//if all the characters are present in window
                if(r-l+1<minLen){//caculate minimum
                    minLen=r-l+1;
                    start=l;
                }//apply sliding window
                win[s[l]]--;//decrease count of the left most element
                if(mp.find(s[l])!=mp.end() && win[s[l]]<mp[s[l]]){//if that element is present in the temp and now the window count is less then the mp decrease current
                    curr--;

                }
                l++;//slide window
            }
            
        }
       
         return minLen==INT_MAX? "":s.substr(start,minLen);//substr(start,start+minLen)
    }
};
