int zAlgorithm(string s, string p, int n, int m){
	int count=0;
	for(int i=0;i<=n-m;i++){
		string str = s.substr(i,m);
		if(str == p)	count++;
	}
	return count;
}
