#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

const int MN = 200200;

int n;
int a[MN];


ll gcd(ll a, ll b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}


ll full(int c, int d) { 
	ll re = 0;
	for (int dd = d; dd <= c; dd += d) {
		if (gcd(dd, n) != d) continue;
		re += n;
	}
	return re;
}

ll cou(int c, int d) { 
	ll re = 0;
	for (int dd = d; dd <= c; dd += d) {
		if (gcd(dd, n) != d) continue;
		re += (c-dd+1);
	}
	return re;
}

int md[MN];
bool ok[MN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
	}

	ll sm = 0;
	for (int l = 1; l < n; l++) { // length
		if (n % l != 0) continue;
		fill_n(md, n, 0);
		int t = n/l; //times
		for (int j = 0; j < t; j++) {
			for (int k = 0; k < l; k++) {
				md[k] = max(md[k], a[j*l+k]);
			}
		}

		for (int j = 0; j < t; j++) {
			for (int k = 0; k < l; k++) {
				ok[j*l+k] = (a[j*l+k] == md[k]);
			}
		}

		int st = -1;
		for (int j = 0; j < n; j++) {
			if (!ok[j]) {
				st = j;
				break;
			}
		}
		if (st == -1) {
			sm += full(n, l);
			// length=n
			continue;
		}

		int ba = 1;
		for (int j = 1; j < n; j++) {
			int k = st+j;
			if (n <= k) k -= n;
			if (!ok[k]) {
				sm += cou(j-ba, l);
				// length = j-ba
				ba = j+1;
			}
		}
		sm += cou(n-ba, l);
		// n-ba
	}
	cout << sm << endl;
    return 0;
}