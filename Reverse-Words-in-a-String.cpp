#include<bits/stdc++.h>

string reverseString(string &str){
	stack<string> st;
	string temp="";
	int n=str.length();
	for(int i=0;i<n;i++){
		if(str[i]==' '){
			if(temp!=""){
				st.push(temp);
				temp="";
			}
		}
		else	temp.push_back(str[i]);
	}
	if(temp!=""){
		st.push(temp);
		temp="";
	}
	while(!st.empty()){
		auto x = st.top();
		st.pop();
		if(temp!="")	temp.push_back(' ');
		temp+=x;
	}
	return temp;
}
