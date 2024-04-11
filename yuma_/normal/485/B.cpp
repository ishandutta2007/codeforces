#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
#include<cstdlib>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()


bool f[1000001];

int main() {
	long long int n; cin >> n;
	long long int u, d, l, r;

	for (int i = 0; i < n; ++i) {
		long long int x, y; cin >> x >> y;
		if (!i) {
			u = y; d = y; l = x; r = x;
		}
		else {
			u = min(u, y); d = max(d, y);
			l = min(l, x); r = max(r, x);
		}
		
	}
	long long int ans = max(d - u, r - l)*max(d - u, r - l);
	cout << ans << endl;
	return 0;
}