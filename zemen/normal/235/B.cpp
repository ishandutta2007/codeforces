#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>
#include <cassert>

#define INF __INT_MAX__
#define LINF __LONG_LONG_MAX__

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;

using namespace std;

void solve();

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cout.setf(ios::fixed);
    cout.precision(15);
    int n, i;
    n = 1;
    for (i = 0; i < n; i++)
        solve();
}

void solve() {
	int n;
	cin >> n;
	double p;
	double res = 0;
	double cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> p;
		res += p * (2 * cnt + 1);
		cnt = (cnt + 1) * p;
	}
	cout << res;
}