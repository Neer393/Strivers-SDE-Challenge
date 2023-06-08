#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	if(n<3)	return ans;
	set<vector<int>>st;
	for(int i=0;i<n-2;i++){
		int target = K-arr[i];
		int s=i+1,e=n-1;
		while(s<e){
			int sum = arr[s]+arr[e];
			if(sum==target){
				vector<int> temp;
				temp.push_back(arr[i]);
				temp.push_back(arr[s]);
				temp.push_back(arr[e]);
				sort(temp.begin(),temp.end());
				st.insert(temp);
				s++;
				e--;
			}
			else if(sum<target)	s++;
			else	e--;
		}
	}
	
	while(!st.empty()){
		auto x = *(st.begin());
		st.erase(x);
		ans.push_back(x);
	}
	return ans;

}
