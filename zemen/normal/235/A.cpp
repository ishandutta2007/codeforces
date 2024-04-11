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
    cout.precision(10);
    int n, i;
    n = 1;
    for (i = 0; i < n; i++)
        solve();
}

void solve() {
	ll n;
	cin >> n;
	if (n == 2)
		cout << 2;
	else if (n == 1)
		cout << 1;
	else if (n == 4)
		cout << 12;
	else {
		ll res = n * (n - 1) * (n - 2) / (n % 2 == 0 ? 2 : 1);
		res = max(res, n * (n - 1) * (n - 3) / (n % 3 == 0 ? 3 : 1));
		res = max(res, (n - 1) * (n - 2) * (n - 3));
		cout << res;
	}
}