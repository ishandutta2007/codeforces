#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAX_N = 1e7 + 6;

LL pow1(LL a,LL n) {
	if (n==1) return a;
	else if (n==0) return 1;
	else {
		LL ret=pow1(a,n/2);
		if (ret>MAX_N) return MAX_N;
		ret *= ret;
		if (ret>MAX_N) return MAX_N;
		if (n&1) ret*=a;
		if (ret>MAX_N) return MAX_N;
		return ret;
	}
}

int main () {
	LL n,l,r;
	while (scanf("%I64d %I64d %I64d",&n,&l,&r) != EOF) {
		if (n==1) printf("%I64d\n",r-l+1);
		else if (n==2) printf("%I64d\n",(r-l)*(r-l+1));
		if(n<=2) continue;
		vector<LL> v;
		for(int i=1;;i++) {
			LL ret=pow1(i,n-1);
			if (ret>r) break;
			v.push_back(ret);
		}
		int sz=v.size();
		LL ans=0;
		for (int i=sz-1;i>=0;i--) {
			LL mx=r/v[i];
			for (int j=i-1;j>=0;j--) {
				if (__gcd(i+1,j+1) != 1) continue;
				LL mn=(l-1)/v[j]+1;
				//cout<<"i = "<<i<<" , j = "<<j<<" , mn = "<<mn<<" , mx = "<<mx<<endl;
				if (mx>=mn)ans += (mx-mn+1);
			}
		}
		printf("%I64d\n",2*ans);
	}
}