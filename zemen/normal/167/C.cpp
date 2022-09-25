/*		c.cpp
 *		Created on: 27.03.2012
 *      Author: zemen
 */

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define mp make_pair
#define INF __INT_MAX__
#define PI M_PIl

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

void solve();

int main() {
#ifndef LOCAL_BUILD
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		solve();
}

char gcd(ll a, ll b) {
	if (!b)
		return 0;
	char w = gcd(b, a % b);
	if (!w)
		return 1;
	ll q = a / b;
	if (b % 2)
		return (char) (q % 2 == 0);
	ll e = q % (b + 1);
	return (char) (e % 2 == 0);
}

void solve() {
	ll a, b;
	cin >> a >> b;
	if (a < b)
		swap(a, b);
	char res = gcd(a, b);
	if (res)
		cout << "First\n";
	else
		cout << "Second\n";
}