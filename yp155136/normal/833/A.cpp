#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long long LL;
typedef long double ld;
const int MAX_N = 1e6 +6;

LL prime[MAX_N];

void build() {
	prime[1] = prime[0] = 1;
	for (LL i=1;MAX_N>i;i++) {
		if (prime[i] == 0) {
			for (int j=i;MAX_N>j;j+=i) {
				prime[j]=i;
			}
		}
	}
}

bool check(LL x) {
	ld haha = ld(1)/ld(3);
	LL ret=LL(pow(x,haha) + 0.000001);
	return ret*ret*ret == x;
}

int main () {
	build();
	int T;
	scanf("%d",&T);
	while (T--) {
		LL a,b;
		scanf("%lld %lld",&a,&b);
		if (!check(a*b)) {
			puts("No");
			continue;
		}
		else {
			LL x=a*b;
			ld haha = ld(1)/ld(3);
			LL ret=LL(pow(x,haha) + 0.000001);
			bool okay=true;
			while (ret != 1) {
				LL _1=0,_2=0;
				LL p=prime[ret];
				while (a%p==0) {
					_1++;
					a/=p;
				}
				while (b%p==0) {
					_2++;
					b/=p;
				}
				LL r=(_1+_2)/3;
				if((_1+_2)%3 != 0) okay=false;
				if (min(_1,_2) >= r && max(_1,_2) <= 2*r) ;
				else okay=false;
				while (ret%p==0) ret/=p;
			}
			if (okay) puts("Yes");
			else puts("No");
		}
	}
}