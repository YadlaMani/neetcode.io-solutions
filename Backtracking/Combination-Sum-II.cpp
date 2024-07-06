class Solution {
public:
    void backTrack(vector<int>&can,int sum,int i,int target,vector<vector<int>>&ans,vector<int>&temp){
        //when the sum is equal to target sum append to the ans
       if (sum == target) {
            ans.push_back(temp);
            return;
        }
        //if we reach end of the vector or sum exceeds target return end recurrsion
        if (i == can.size() || sum > target) {
            return;
        }

        for (int j = i; j < can.size(); ++j) {
            //to avoid duplicate combinations
            if (j > i && can[j] == can[j - 1]) {
                continue;
            }
            //push the distant element
            temp.push_back(can[j]);
            //backtrack
            backTrack(can, sum + can[j], j + 1, target, ans, temp); 
            //remove the element
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        //sort the candidates vector
        sort(can.begin(),can.end());
        
        vector<vector<int>>ans;
        vector<int>temp;
        //use backtracking to solve the problem
        backTrack(can,0,0,target,ans,temp);
        return ans;
    }
};
