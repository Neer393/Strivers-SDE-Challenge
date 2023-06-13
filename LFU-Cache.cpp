#include<bits/stdc++.h>
class LFUCache {
    int capacity;
    int minimunFrequency;
    unordered_map<int,pair<int,int>> cache;
    unordered_map<int,list<int>> frequencymp;
    unordered_map<int,list<int>::iterator> position;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minimunFrequency = 0;
    }
    int get(int key) {
       if(cache.find(key) != cache.end()){
           int freq = cache[key].second;
           frequencymp[freq].erase(position[key]);
           freq++;
           frequencymp[freq].push_front(key);
           position[key] = frequencymp[freq].begin();
           if(frequencymp[minimunFrequency].empty())
            minimunFrequency++;
           return cache[key].first;
       }else    
        return -1;
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            cache[key].first = value;
            int freq = cache[key].second;
            frequencymp[freq].erase(position[key]);
            freq++;
            frequencymp[freq].push_front(key);
            position[key] = frequencymp[freq].begin();
            if(frequencymp[minimunFrequency].empty())
                minimunFrequency++;
            return;
        }
        if(capacity == cache.size()){
            int key = frequencymp[minimunFrequency].back();
            cache.erase(key);
            position.erase(key);
            frequencymp[minimunFrequency].pop_front();
        }
        cache[key] = {value, 1};
        frequencymp[1].push_front(key);
        position[key] = frequencymp[1].begin();
        minimunFrequency=1;
    }
};
