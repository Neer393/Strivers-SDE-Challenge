#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<pair<pair<int,int>,int>>meetings;
    int n=start.size();
    for(int i=0;i<n;i++)
        meetings.push_back({{start[i],end[i]},i+1});
    sort(meetings.begin(),meetings.end(),[&](pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
        return a.first.second==b.first.second ? a.second<b.second : a.first.second<b.first.second;
    });
    int endtime=-1;
    vector<int>ans;
    for(auto i:meetings){
        if(i.first.first>endtime){
            endtime = i.first.second;
            ans.push_back(i.second);
        }
    }
    return ans;
}
