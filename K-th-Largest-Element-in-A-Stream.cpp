#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    Kthlargest(int k, vector<int> &arr) {
       for(auto i:arr)  pq.push(i);
    }

    void add(int num) {
        pq.push(num);
        pq.pop();
    }

    int getKthLargest() {
       return pq.top();
    }

};
