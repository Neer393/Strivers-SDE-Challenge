#include <bits/stdc++.h> 
class Queue {
public:
    vector<int>arr;
    int frontptr;
    int backptr;
    Queue() {
        arr= vector<int>((int)(1e5));
        frontptr=backptr=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return frontptr==-1 && backptr==-1;
    }

    void enqueue(int data) {
        if(frontptr==-1){
            frontptr++;
        }
        backptr++;
        arr[backptr]=data;
    }

    int dequeue() {
        if(frontptr==-1 || frontptr>backptr)   return -1;
        int ans=arr[frontptr];
        frontptr++;
        if(frontptr>backptr){
            frontptr=-1;
            backptr=-1;
        }
        return ans;
    }

    int front() {
        if(frontptr==-1 || frontptr>backptr) return -1;
        return arr[frontptr];
    }
};
