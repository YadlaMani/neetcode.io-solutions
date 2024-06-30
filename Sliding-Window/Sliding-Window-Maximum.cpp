class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        deque<int>dq;//using two sided queue(descending queue)
        for(int i=0;i<n;i++){
            if(!dq.empty()&&dq.front()==i-k) dq.pop_front();//checking if the current element at the front is in the sliding window or not if not remove
           while(!dq.empty()&&nums[dq.back()]<nums[i]){//maintaining the decending queue
            dq.pop_back();
           }
           dq.push_back(i);//adding the current element
           
           if(i>=k-1){//if sliding window
            res.push_back(nums[dq.front()]);//max element at front index
           }
        }
        return res;
    }
};
