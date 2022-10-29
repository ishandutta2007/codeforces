#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;


const int MAX_N = 5e5 + 6;

LL num[MAX_N];
LL n;
LL k;

bool check1(int id) {
	LL sum=0;
	for (int x=0;n>x;x++) {
		if (num[x]<id) sum+=(id-num[x]);
	}
	if (sum<=k) return true;
	else return false;
}

bool check2(int id) {
	LL sum=0;
	for (int x=0;n>x;x++) {
		if (num[x]>id) sum+=(num[x]-id);
	}
	if (sum<=k) return true;
	else return false;
}

int main () {
	while (scanf("%I64d %I64d",&n,&k) != EOF) {
		LL sum=0;
		for (int x=0;n>x;x++) {
			scanf("%I64d",&num[x]);
			sum+=num[x];
		}
		LL ave=sum/n;
		sort(num,num+n);
		//
		LL l=num[0],r=ave+(sum%n==0?1:1); 
		while (r-l>1) {
			LL mid=(l+r)>>1;
			if (check1(mid)) l=mid;
			else r=mid;
		}
		//
		LL L=ave+(sum%n==0?-1:0),R=num[n-1];
		while (R-L>1) {
			LL mid=(L+R)>>1;
			if (check2(mid)) R=mid;
			else L=mid;
		} 
		printf("%I64d\n",R-l);
	}
}