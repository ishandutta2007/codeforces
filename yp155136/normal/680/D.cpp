#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long long LL;

LL mxnum,mxtime,M;

LL get_a(LL m) {
	double tmp=pow(m,0.33);
	for (LL x=tmp-10;;x++) {
		if (x*x*x<=m && (x+1)*(x+1)*(x+1) > m) return x;
	}
}

void solve(LL m,LL minus, int time) {
	if (m<=7) {
		time+=m;
		if (time>mxtime || time==mxtime && M-minus>mxnum ) {
			mxtime=time;
			mxnum=M-minus;
		}
		return;
	}
	else {
		LL a=get_a(m);
		solve(m-a*a*a,minus,time+1);
		solve(a*a*a-1 - (a-1)*(a-1)*(a-1) ,minus+m+1-a*a*a,time+1);
	}
}

int main () {
	while (scanf("%I64d",&M) != EOF) {
		mxnum=mxtime=0;
		solve(M,0,0);
		printf("%I64d %I64d\n",mxtime,mxnum);
	}
}