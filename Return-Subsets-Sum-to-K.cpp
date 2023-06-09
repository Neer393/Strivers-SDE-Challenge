
void solve(int idx,int n,int &sum,int &k,vector<int>&temp,vector<vector<int>>&ans,vector<int>&arr){
    if(idx>=n){
        if(sum==k){
            ans.push_back(temp);
        }
        return;
    }
    solve(idx+1,n,sum,k,temp,ans,arr);
    temp.push_back(arr[idx]);
    sum+=arr[idx];
    solve(idx+1,n,sum,k,temp,ans,arr);
    sum-=arr[idx];
    temp.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int>temp;
    int sum=0;
    vector<vector<int>>ans;
    solve(0,n,sum,k,temp,ans,arr);
    return ans;
}
