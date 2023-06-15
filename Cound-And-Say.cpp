#include <bits/stdc++.h> 

string solve(int n){
	if(n==1)	return "1";

	string temp = solve(n-1);
	string res = "";
	for(int i=0;i<temp.length();i++){
		int cnt=1;
		while(i<temp.length()-1 && temp[i]==temp[i+1]){
			cnt++;
			i++;
		}
		res+=to_string(cnt);
		res+=temp[i];
	}
	return res;
}

string writeAsYouSpeak(int n) {
	return solve(n);
}
