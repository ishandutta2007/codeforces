#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cassert>
using namespace std;

typedef long long LL;
const LL MAX_N = 1e6 + 6;
const LL INF =1e9+7;

LL extgcd(LL a,LL b,LL &x,LL &y) {
	LL d=a;
	if (b!=0) {
		d = extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else x=1,y=0;
	return d;
}

LL cnt[MAX_N];

int main () {
	LL n,m,dx,dy;
	while (scanf("%I64d %I64d %I64d %I64d",&n,&m,&dx,&dy) != EOF) {
		memset(cnt,0,sizeof(cnt));
		LL a,b;
		extgcd(dy,n,a,b);
		LL _dy = (a+INF*n)%n;
		for (int i=0;m>i;i++) {
			LL x,y;
			scanf("%I64d %I64d",&x,&y);
			LL t=_dy*y;
			cnt[((x-dx*t+n*INF)%n + n)%n]++;
		}
		LL mx=-1,mx_id=-1;
		for (int i=0;n>i;i++) {
			if (cnt[i] > mx) {
				mx = cnt[i];
				mx_id = i;
			}
		}
		printf("%I64d 0\n",mx_id);
	}
}