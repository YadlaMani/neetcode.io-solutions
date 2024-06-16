class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {//very complex problem try watching youtube video reference:https://youtu.be/jC_cWLy7jSI?si=aq7Ei7r35s_kaJYu
        stack<int>st;
        int n=heights.size();
        int ans=0;
        int width;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){//when the top element is greater than the current element pop that and caculate the left and right minimum and use that to find width and caculate max area
                int height=heights[st.top()];
                st.pop();
                if(st.empty()) width=i;
                else width=i-st.top()-1;
                ans=max(ans,height*width);
            }
            st.push(i);//pushing the minimum element into the stack
        }
        return ans;
    }
};
