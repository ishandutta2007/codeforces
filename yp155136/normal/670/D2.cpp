#include <iostream>
#include <stdio.h>
using namespace std;

#define int long long

const int MAX_N = 100003;

int c[MAX_N];
int b[MAX_N];
int n,k;

bool check(int id) {
	int ret=0;
	for (int x=0;n>x;x++) {
		if (c[x]*id-b[x]>0) ret+=c[x]*id-b[x];
		if (ret>k) return false;
		if (ret<0) return false;
	}
	return ret<=k;
}

main () {
	while (scanf("%I64d %I64d",&n,&k) != EOF) {
		for (int x=0;n>x;x++) scanf("%I64d",&c[x]);
		for (int x=0;n>x;x++) scanf("%I64d",&b[x]);
		int L=0, R=2e9 + 10;
		while (R-L!=1) {
			int mid=(L+R)>>1;
//			cout<<"mid="<<mid<<endl;
			if (check(mid)) L=mid;
			else R=mid;
		}
		printf("%I64d\n",L);
	}
}