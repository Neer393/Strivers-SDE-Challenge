#include<bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<vector<int>> v(start.size());
    for(int i=0;i<start.size();i++){
        v[i].push_back(start[i]);
        v[i].push_back(finish[i]);
    }
    sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    });
    int stime = v[0][0];
    int endtime = v[0][1];
    int cnt=1;
    for(int i=1;i<start.size();i++){
        if(v[i][0]>=endtime || v[i][1]<=stime){
            cnt++;
            stime = v[i][0];
            endtime = v[i][1];
        }
    }
    return cnt;
}
