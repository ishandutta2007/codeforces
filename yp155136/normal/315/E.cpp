#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;
const int MAX_M = 1e6 + 6;
const LL mod = 1e9 + 7;

struct BIT {
	LL data[MAX_M];
	int n;
	void init(int _n) {
		n=_n;
		memset(data,0,sizeof(data));
	}
	void update(int pos,LL val) {
		val%=mod;
		for(int i=pos;n>=i;i+=(i&(-i))) {
			data[i] += val;
			data[i] %= mod;
		}
	}
	LL query(int pos) {
		LL ret=0;
		for(int i=pos;i>0;i-=(i&(-i))) {
			ret += data[i];
			ret%=mod;
		}
		return ret;
	}
} bit;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int m=1e6;
		bit.init(m);
		for (int i=1;n>=i;i++) {
			int x;
			scanf("%d",&x);
			LL pre=(bit.query(x));
			LL minus = (bit.query(x) - bit.query(x-1));
			bit.update(x,pre*x+x-minus);
		}
		printf("%lld\n",bit.query(m));
	}
}