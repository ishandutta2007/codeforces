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


pair<long long int,int> getans(long long int a) {
	if (a == 0) {
		return make_pair(0, 0);
	}
	else if (a == 1) {
		return make_pair(1, 0);
	}

}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		unsigned long long int l, r; cin >> l >> r;
		if (l == r) {
			cout << l << endl;
			continue;
		}
		long long int ans;
		bitset<100>lbs(l);
		bitset<100>rbs(r);
		bitset<100>ansbs(0);
		for (int i = 99; i >= 0; --i) {
			if (rbs[i] && !lbs[i]) {
				bitset<100>nbs;
				bool ok = true;
				for (int j = 0; j <= i; ++j) {
					if (!rbs[j]) {
						ok = false;
					}
				}
				if (ok) {
					ans = r;
					break;
				}
				else {
					for (int j = 0; j < i; ++j) {
						ansbs[j] = 1;
					}
					ans = ansbs.to_ullong();
					break;
				}
			}
			else if (rbs[i] && lbs[i]) {
				ansbs[i] = 1;
			}
			else if (!rbs[i] && !lbs[i]) {

			}
			else {

			}
		}
		cout << ans << endl;
	}
	return 0;
}