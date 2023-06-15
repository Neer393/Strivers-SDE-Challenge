vector<int> stringMatch(string &str, string &pat) {
    int n=str.length(),m=pat.length();
    vector<int>ans;
    string temp="";
    for(int i=0;i<m;i++)    temp.push_back(str[i]);
    if(temp==pat)   ans.push_back(0);
    for(int i=m;i<n;i++){
        temp = temp.substr(1);
        temp.push_back(str[i]);
        if(temp==pat)   ans.push_back(i-m+1);
    }
    return ans;
}
