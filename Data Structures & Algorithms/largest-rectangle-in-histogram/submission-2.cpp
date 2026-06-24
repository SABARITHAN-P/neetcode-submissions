class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.size()==1) return height[0];
        int ans=0;
        stack<int> st;
        int pse=0,nse=0;
        for(int i=0;i<height.size();i++){
            while(!st.empty() and height[st.top()]>=height[i]){
                int ind=st.top();
                st.pop();
                pse=st.empty()?-1:st.top();
                nse=i;
                ans=max(ans,height[ind]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            nse=height.size();
            int ind=st.top();
            st.pop();
            pse=st.empty()?-1:st.top();
            ans=max(ans,height[ind]*(nse-pse-1));
        }
        return ans;
    }
};
