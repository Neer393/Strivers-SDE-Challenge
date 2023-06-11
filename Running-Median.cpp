#include<bits/stdc++.h>

void insert(priority_queue<int,vector<int>,greater<int>>&pqmin,priority_queue<int,vector<int>>&pqmax,int x){
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

int median(priority_queue<int,vector<int>,greater<int>>&pqmin,priority_queue<int,vector<int>>&pqmax){
    if(pqmax.size()==pqmin.size()){
        return (floor(pqmax.top()+pqmin.top())/2.0);
    }
    else if(pqmax.size()>pqmin.size()){
        return pqmax.top();
    }
    return pqmin.top();
}

void findMedian(int *arr, int n){
    priority_queue<int,vector<int>,greater<int>> pqmin;
    priority_queue<int,vector<int>> pqmax;
    for(int i=0;i<n;i++){
        insert(pqmin,pqmax,arr[i]);
        cout<<median(pqmin,pqmax)<<" ";
    }
    cout<<endl;
}
