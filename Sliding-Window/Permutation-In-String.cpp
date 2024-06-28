class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int freq[26]={0};//maintain a freq array for s1
        for(auto ch:s1){
            freq[ch-'a']++;
        }
        int l=0;//sliding window
        int cfreq[26]={0};//a freq array for s2
        for(int r=0;r<s2.size();r++){
            cfreq[s2[r]-'a']++;//increase count of current char
            while(cfreq[s2[r]-'a']>freq[s2[r]-'a']){//if the current char in s2 but not int s1
                cfreq[s2[l]-'a']--;//decrease count of left character
                l++;//move left window
            }
            if(r-l+1==s1.size()){
                return true;
            }
        }
        return false;
       

    }
};
