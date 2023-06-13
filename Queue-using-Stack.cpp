#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int>st;
    public:
    Queue() {
        
    }

    void enQueue(int val) {
        if(st.empty()){
            st.push(val);
            return;
        }
        int topo = st.top();
        st.pop();
        enQueue(val);
        st.push(topo);
    }

    int deQueue() {
        if(st.empty())  return -1;
        int topo = st.top();
        st.pop();
        return topo;
    }

    int peek() {
        if(st.empty())  return -1;
        return st.top();
    }

    bool isEmpty() {
        return st.empty();
    }
};
