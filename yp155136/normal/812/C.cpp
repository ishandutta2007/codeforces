#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;

LL a[MAX_N];
LL tmp[MAX_N];

LL check(LL id,int n) {
	for (int i=1;n>=i;i++) {
		tmp[i] = a[i] + id*i;
	}
	sort(tmp+1,tmp+n+1);
	LL ret = 0;
	for (int i=1;id>=i;i++) {
		ret += tmp[i];
	}
//	cout<<"id = "<<id<<" , ret = "<<ret<<endl;
	return ret;
}

int main () {
	int n,s;
	while (scanf("%d %d",&n,&s) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		int L=0,R=n+1;
		while (R-L != 1) {
			int mid=(L+R)>>1;
			if (check(mid,n) <= s) L=mid;
			else R=mid;
		}
		printf("%d %lld\n",L,check(L,n));
	}
}