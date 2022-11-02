/*
 * d.cpp
 *
 *  Created on: 2012-2-24
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long ll;
int main() {
	ll x1, x2, a, b;
	cin >> x1 >> x2 >> a >> b;
	ll D = x1 - x2;
	bool swaped = 0;
	if (D < 0) {
		D = -D;
		ll na = -b, nb = -a;
		a = na, b = nb;
		swaped = 1;
	}
	//D>0
	//[a,b]
	if (b >= 0) {
		if (D + a <= 0) {
			puts("FIRST");
			cout << x2 << endl;
			return 0;
		}
		puts("DRAW");
		return 0;
	}
	//a<0,b<0
	ll l = -b, r = -a;
	//[l,r] l,r>0
	if (l == r) {
		if (D % l != 0)
			puts("DRAW");
		else {
			if ((D / l) % 2 == 0)
				puts("SECOND");
			else {
				puts("FIRST");
				cout << (swaped ? x1 - a : x1 + a) << endl;
			}
		}
		return 0;
	}
	ll rem = D % (l + r);
	if (rem == 0) { //LOSE
		puts("SECOND");
		return 0;
	}
	if (rem < l || rem + l - 1 >= l + r) { //DRAW
		puts("DRAW");
		return 0;
	}
	//WIN
	puts("FIRST");
	ll step = -rem;
	cout << (swaped ? x1 - step : x1 + step) << endl;
	return 0;
}