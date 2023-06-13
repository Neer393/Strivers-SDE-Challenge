// #include <bits/stdc++.h> 
// Stack class.
class Stack {
    public:
    vector<int>arr;
    int topPtr;
    int sz;
    
    Stack(int capacity) {
        arr=vector<int>(capacity);
        topPtr=-1;
        sz=capacity;
    }

    void push(int num) {
        if(topPtr==sz-1)   return;
        topPtr++;
        arr[topPtr]=num;
    }

    int pop() {
        if(topPtr==-1) return -1;
        int ans = arr[topPtr];
        topPtr--;
        return ans;
    }
    
    int top() {
        if(topPtr==-1) return -1;
        return arr[topPtr];
    }
    
    int isEmpty() {
        return topPtr==-1;
    }
    
    int isFull() {
        return topPtr==sz-1;
    }
    
};
