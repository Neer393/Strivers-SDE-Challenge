#include<bits/stdc++.h>
 vector<int>nextsmaller(vector<int> &heights,int n){
    vector<int>next(n);
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){ 
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        next[i]=st.top();
        st.push(i);
    }
    return next;
}

vector<int>prevsmaller(vector<int> &heights,int n){
    vector<int>next(n);
    stack<int>st;
    st.push(-1);
    for(int i=0;i<n;i++){
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        next[i]=st.top();
        st.push(i);
    }
    return next;
}

int largestRectangle(vector < int > & heights) {
    int n=heights.size();
    vector<int>next(n);
    next=nextsmaller(heights,n);
    
    vector<int>prev(n);
    prev=prevsmaller(heights,n);
    int ans=-1;
    for(int i=0;i<n;i++){
        int l=heights[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int b=next[i]-prev[i]-1;
        ans=max(ans,l*b);
    }
    return ans;
 }
