class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size()-1;
        vector<int> ans(n+1,0);
        stack<pair<int,int>> st;
        for(int i=n;i>=0;i--){
            while(!st.empty() && st.top().first <= temp[i]) {
                st.pop();
            }

            if(!st.empty()) {
                ans[i] = st.top().second - i;
            }

            st.push({temp[i], i}); 
        }
        return ans;
    }
};
