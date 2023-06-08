#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    });
    vector<vector<int>> ans;
    int starttime = intervals[0][0];
    int endtime = intervals[0][1];
    int n=intervals.size();
    for(int i=1;i<n;i++){
        if((intervals[i][0]>=starttime && intervals[i][0]<=endtime) || (intervals[i][1]>=starttime && intervals[i][1]<=endtime)){
            starttime = min(starttime,intervals[i][0]);
            endtime = max(endtime,intervals[i][1]);
        }
        else{
            ans.push_back({starttime,endtime});
            starttime = intervals[i][0];
            endtime = intervals[i][1];
        }
    }
    ans.push_back({starttime,endtime});
    return ans;
}
