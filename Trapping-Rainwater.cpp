#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    stack<long> st;
    long ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            long t = st.top();
            st.pop();
            if(st.empty())  break;
            else{
                int width = i-st.top()-1;
                ans+=width*(min(arr[i],arr[st.top()])-arr[t]);
            }
        }
        st.push(i);
    }
    return ans;
}
