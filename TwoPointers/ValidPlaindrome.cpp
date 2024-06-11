class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                str+=tolower(s[i]);
            }
}//add the elements of the string to another string when they are alphabets and also in lower case
        for(int i=0;i<str.size()/2;i++){
            if(str[i]!=str[str.size()-i-1]){//using two pointer approach traverse the string checking the left and right pointer
                return false;
            }
}
        return true;
        
    }
};
