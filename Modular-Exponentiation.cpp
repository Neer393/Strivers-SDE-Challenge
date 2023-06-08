#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	if(m==1)	return 0;
	long long int ans =1;
    while(n>0){
        if(n&1){
            ans = ((ans) * (x)%m)%m;
        }
        x = (1LL * (x)%m * (x)%m)%m;
        n=n>>1;
    }
    return ans;
}
