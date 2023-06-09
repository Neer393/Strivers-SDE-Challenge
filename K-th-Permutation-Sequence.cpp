string kthPermutation(int n, int k) {
    vector<int> fact;
    int temp=1;
    for(int i=1;i<n;i++){
        temp*=i;
        fact.push_back(i);
    }
    fact.push_back(n);
    string ans="";
    k--;
    while(true){
        ans+=to_string(fact[k/temp]);
        fact.erase(fact.begin()+(k/temp));
        if(fact.size()==0)  break;
        k=k%temp;
        temp/=fact.size();
    }
    return ans;
}
