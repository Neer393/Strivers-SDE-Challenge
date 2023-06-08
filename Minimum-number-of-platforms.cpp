int calculateMinPatforms(int at[], int dt[], int n) {
    vector<int> v(2400,0);
    for(int i=0;i<n;i++){
        v[at[i]]++;
        v[dt[i]+1]--;
    }
    int cnt=0;
    for(int i=1;i<2400;i++){
        v[i]+=v[i-1];
        cnt=max(cnt,v[i]);
    }
    return cnt;

}
