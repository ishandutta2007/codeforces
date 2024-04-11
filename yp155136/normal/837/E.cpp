#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const LL MAX_N = 1e6 + 6;
const LL INF = 1e15 +7;

LL prime[MAX_N];
vector<LL> vv;
vector<LL> vvv;

void build(LL magic) {
	prime[1] = prime[0] = 1;
	for (LL i=1;MAX_N>i;i++) {
		if (prime[i] == 0) {
			if (magic % i ==0) {
				vvv.push_back(i);
				while (magic % i ==0)magic/=i;
			}
			for (int j=i;MAX_N>j;j+=i) {
				prime[j]=i;
			}
		}
	}
	if (magic != 1) vvv.push_back(magic);
}

LL f(LL x,LL y) {
	if (y==0) return 0;
	LL gcd=__gcd(x,y);
	LL xx=x/gcd;
	LL yy=y/gcd;
	if (xx == 1) return yy;
	if (yy == 1) return yy;
	LL xxx=xx;
	LL need=INF;
	for (LL i:vvv) {
		if (xxx%i==0) {
			need = min(need,yy - (yy/i)*i);
		}
	}
	return need + f(x,y-gcd*need);
}

int main () {
	LL x,y;
	cin >> x >>y;
	build(x);
	cout<<f(x,y)<<endl;
}