#include <bits/stdc++.h> 
 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   sort(arr.begin(),arr.end());
   vector<vector<int>> ans;
   int n=arr.size();
   int start=0,end=n-1;
   while(start<end){
      int sum = arr[start]+arr[end];
      if(sum==s){
         ans.push_back({arr[start],arr[end]});
         int temps = start+1,tempe=end-1;
         while(tempe>start && arr[tempe]==arr[end]){
            ans.push_back({arr[start],arr[tempe]});
            tempe--;
         }
         while(temps<end && arr[temps]==arr[start]){
            ans.push_back({arr[temps],arr[end]});
            temps++;
         }
         start++;
         end--;
      }
      else if(sum<s){
         start++;
      }
      else{
         end--;
      }
   }
   return ans;
}
