#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &prices) {
    vector<int>ans;
    stack<pair<int,int>> st;
    for(auto i: prices){
        int days=1;
        while(!st.empty() && st.top().first <= i){
            days+=st.top().second;
            st.pop();
        }
        st.push(make_pair(i,days));
        ans.push_back(days);
    }
    return ans;
}
