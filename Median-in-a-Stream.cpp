#include <bits/stdc++.h>

void insert(int x,priority_queue<int,vector<int>>&pqmax,priority_queue<int,vector<int>,greater<int>>&pqmin){
    if(pqmin.size()==pqmax.size()){
        if(pqmax.size()==0){
            pqmax.push(x);
            return;
        }

        if(x<pqmax.top()){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }
    }
    else{
        if(pqmax.size() > pqmin.size()){
            if(x>=pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp=pqmax.top();
                pqmax.pop();
                pqmax.push(x);
                pqmin.push(temp);
            }
        }
        else{
            if(x<=pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp=pqmin.top();
                pqmin.pop();
                pqmin.push(x);
                pqmax.push(temp);
            }
        }
    }
}

int median(priority_queue<int,vector<int>>&pqmax,priority_queue<int,vector<int>,greater<int>>&pqmin){
    if(pqmax.size()==pqmin.size()){
        return floor((pqmax.top()+pqmin.top())/2.0);
    }
    else if(pqmax.size()>pqmin.size()){
        return pqmax.top();
    }
    return pqmin.top();
}

vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int,vector<int>> pqmax;
	priority_queue<int,vector<int>,greater<int>> pqmin;
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		insert(arr[i],pqmax,pqmin);
		ans[i]=(median(pqmax,pqmin));
	}
	return ans;
}
