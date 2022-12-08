#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
//#include <unordered_map>  
//#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

int main() {
	ll F, T, t0;
	ll a1, t1, p1;
	ll a2, t2, p2, i;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &F, &T, &t0, &a1, &t1, &p1, &a2, &t2, &p2);
	t1 = min(t1, t0);
	t2 = min(t2, t0);
	if (t1 < t2) {
		swap(a1, a2);
		swap(t1, t2);
		swap(p1, p2);
	}
	if (F*t0 <= T) return !printf("0\n");
	if (t2 == t0) return !printf("-1\n");

	ll ans = LL_INF;
	for (i = 0; (i-1)*a2 < F; i++) {
		ll y = i, x = (F - a2*y + a1 - 1) / a1;

		ll v2 = min(a2 * y, F);
		ll v1 = F - v2;
		if (v1 * t1 + v2 * t2 <= T) ans = min(ans, x * p1 + y * p2);
	}
	for (i = 0; i*a2 <= F; i++) {
		ll y = i;
		ll xmx = (F - i*a2) / a1;
		
		ll q1 = a1 * (t0 - t1), q2 = F * t0 - T - a2*y*(t0 - t2);
		ll xmn = 0;
		if (q2 <= 0) xmn = 0;
		else if (q1 == 0) xmn = LL_INF;
		else xmn = (q2 + q1 - 1) / q1;
		if (xmn > xmx) continue;
		ans = min(ans, xmn * p1 + y * p2);
	}
	if (ans == LL_INF) ans = -1;
	return !printf("%lld\n", ans);
}